#include "ThreadPoolTables.h"

ThreadPoolTables::ThreadPoolTables(Table** _tables, CustomersInLine *_customersInLine): 
    ThreadPool(TABLES_AMOUNT),
    tables(_tables),
    customersInLine(_customersInLine),
    running(true)
    {};

Table* ThreadPoolTables::getUnoccupiedTable(){
    bool tableOccupied;
    Table* ptrTable = nullptr;

    //Check for the first available table
    for (int i = 0; i < TABLES_AMOUNT; ++i){
        tableOccupied = tables[i] -> isOccupied();

        if (!tableOccupied){
            ptrTable = tables[i];
            ptrTable -> setStatus(OCCUPIED);
            break;
        }
    }

    return ptrTable;
}

void ThreadPoolTables::run(){
    bool tablesCheckable = true; //Controls whether we must check for a table
    Table *table = nullptr;
    while (running){
        //If we already have a table to assign, and it hasn't been assigned, no need to get another one
        if (tablesCheckable){
            table = getUnoccupiedTable();
        }
        
        if (table != nullptr){
            tablesCheckable = addTasksToQueue(table);
        }
        else{
            //If there were no tables to assign, then most of them must still be occupied
            //since tables take more time, then it's acceptable to wait a bit more before checking again
            std::this_thread::sleep_for(std::chrono::milliseconds(4*MILLI_TO_SEC_CONV));
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(SPAWN_RATE / 2));

    }
}

bool ThreadPoolTables::addTasksToQueue(Table *table){
    std::future<bool> customersExist; //To check if there are customers in line yet
    std::vector<Customer*> customersToAttend;
    bool addedTask = NOT_ADDED;

    customersExist = std::async(std::launch::async, [this]{
            return customersInLine -> isEmpty();}
        );

    if (!customersExist.get()){
        customersToAttend = customersInLine -> extractCustomers();
        enqueue(&Table::seatAndAttendCustomers, table, customersToAttend);

        addedTask = ADDED;
    }

    return addedTask;
}

void ThreadPoolTables::stopRunning(){
    running = false;
}
