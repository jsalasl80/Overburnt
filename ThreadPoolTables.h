#ifndef THREADPOOLTABLES_H
#define THREADPOOLTABLES_H

#include "Includes.h"
#include "Constants.h"
#include "CustomersInLine.h"
#include "ThreadPool.h"

class ThreadPoolTables : public ThreadPool {
private:
    Table** tables;
    CustomersInLine *customersInLine;

public:
    ThreadPoolTables(Table** _tables, CustomersInLine *customersInLine);
    Table* getUnoccupiedTable();
    void run();
    bool addTasksToQueue(Table *table);
};

#endif //THREADPOOLTABLES_H