#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "Includes.h"
#include "Constants.h"
#include "ResultsQueue.h"

#include "Table.h"
#include "LineCook.h"
#include "Deliverer.h"

#include "Customer.h"
#include "Order.h"
using namespace std;

class ThreadPool{
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex; // Protects access to tasks
    std::condition_variable condition; // Notifies other threads in the thread pool

protected:
    bool stop; // Indicates if thread pool must stop

public:
    ThreadPool(size_t numThreads)
        : stop(false){ 
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] { // Cada hilo ejecuta esta lambda
                while (true) { // Bucle infinito para que el hilo siga ejecutándose
                    std::function<void()> task; // Tarea a ejecutar por el hilo
                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex); // Adquiere el bloqueo exclusivo del mutex
                        // Espera a que haya una tarea en la cola o que se detenga el pool
                        this->condition.wait(lock, [this] {
                            return this->stop || !this->tasks.empty();
                        });
                        // Si el pool se ha detenido y no hay tareas, el hilo termina
                        if (this->stop && this->tasks.empty())
                            return;
                        // Toma la siguiente tarea de la cola
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }
                    task(); // Ejecuta la tarea
                }
            });
        }
    }

    template <class F, class... Args> //The ... indicate parameter pack, which can contain as many as a function needs 
    auto enqueue(F&& f, Args&&... args)
        -> std::future<typename std::result_of<F(Args...)>::type>{
        using return_type = typename std::result_of<F(Args...)>::type; // Determina el tipo de retorno de la tarea

        // Crea una tarea empaquetada que encapsula la función `f` y sus argumentos `args`
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

        std::future<return_type> res = task->get_future(); // Obtiene el future asociado con la tarea empaquetada
        {
            std::unique_lock<std::mutex> lock(queue_mutex); // Adquiere el bloqueo exclusivo del mutex
            // Si el pool está detenido, lanza una excepción
            if (stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");
            // Encola la tarea
            tasks.emplace([task]() { (*task)(); });
        }
        condition.notify_one(); // Notifica a uno de los hilos en espera
        return res; // Devuelve el future
    }
    
    virtual ~ThreadPool(){
        {
            std::unique_lock<std::mutex> lock(queue_mutex); // Adquiere el bloqueo exclusivo del mutex
            stop = true; // Indica que el pool debe detenerse
        }
        condition.notify_all(); // Notifica a todos los hilos en espera
        for (std::thread &worker : workers) // Une todos los hilos trabajadores
            worker.join();
    }

    void stopRunning(){
        stop = true;
    }
};

#endif //THREADPOOL_H