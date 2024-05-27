#ifndef CONSTANTS
#define CONSTANTS
#include "Includes.h"

//Nones
#define NONE 0
#define NONE_FLOAT 0.0
#define NONE_DOUBLE 0.0
#define NONE_STRING ""

//Constants for files management
#define CSV_DIRECTORY "bin/"
#define REPORT_TXT "RestaurantReport.txt"
#define REPORT_HEADER_MESSAGE "Restaurant Report:\nInventory State\n<Ingredient>: <AmountLeft>\n"
#define INVENTORY_CSV "/bin/ingredientes.csv"
#define RECIPES_CSV "/bin/recetas.csv"
#define READ_MODE "r"

//Constants for Inventory
#define UNLOCKED false
#define LOCKED true

//Constants for InventoryManager
#define INGREDIENTS_AMOUNT 10

//Constants for RecipeReader
#define RECIPE_MAIN_ELEMENTS 4
#define INGREDIENT_AND_AMOUNT_PAIR 2

//Constants for Customers
#define NAMES_AMOUNTS 30
const std::string NAMES[NAMES_AMOUNTS] = {
    "John",
    "Wei",
    "Miguel",
    "Aisha",
    "Akira",
    "Maria",
    "Liam",
    "Sofia",
    "Raj",
    "Emma",
    "Ethan",
    "Isabella",
    "Yuki",
    "Carlos",
    "Leila",
    "Nikolai",
    "Ming",
    "Fatima",
    "Viktor",
    "Ines",
    "Dmitri",
    "Priya",
    "Anna",
    "Javier",
    "Hana",
    "Ravi",
    "Elena",
    "Ahmed",
    "Lina",
    "Hiroshi"
};

const std::string LAST_NAMES[NAMES_AMOUNTS] = {
    "Smith",
    "Wang",
    "Garcia",
    "Ahmed",
    "Tanaka",
    "Martinez",
    "Johnson",
    "Hernandez",
    "Patel",
    "Kumar",
    "Chen",
    "Nguyen",
    "Lopez",
    "Kim",
    "Rodriguez",
    "Singh",
    "Davies",
    "Ivanov",
    "Muller",
    "Kowalski",
    "Popov",
    "Nakamura",
    "Santos",
    "Brown",
    "Murphy",
    "Schmidt",
    "Takahashi",
    "Rossi",
    "Gonzalez",
    "Lee"
};
#define MILLI_TO_SEC_CONV 1000
#define EATING false
#define FINISHED true

//Constants for customer spawner
#define SPAWNING true
#define HALT_SPAWNING false
#define MIN_CUSTOMER_COUNT 1
#define MAX_CUSTOMER_COUNT 6
#define SPAWN_RATE 2000

//Constants for tables
#define TABLES_AMOUNT 1
#define OCCUPIED true
#define UNOCCUPIED false

//Constants for orders
#define NEGATIVE -1
#define POSITIVE 1
#define READY true
#define IN_PREPARATION false
#define PREP_DELAY 2
#define EATING_DELAY 2

//Constants for LineCook and Deliverer
#define LINE_COOKS_AMOUNT 1
#define DELIVERERS_AMOUNT 1
#define COOKING true
#define CHILLING false
#define DELIVERING true

//Constants for ThreadPool
#define ADDED true
#define NOT_ADDED false

//Constants for Accountant
#define REPORTING true
#define ACCOUNTING false

//Constants for Restaurant
#define SIMULATING true
#define HALT_SIMULATING false
#define MAX_UNSATISFIED_CUSTOMERS 100

#endif