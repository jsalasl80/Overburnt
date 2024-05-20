#ifndef CONSTANTS
#define CONSTANTS
#include "Includes.h"

//Miscellaneous Constants
#define NONE 0
#define INGREDIENTS_AMOUNT 10

//Files Constants: Related to CSV's
#define CSV_DIRECTORY "bin/"
#define REPORT_TXT "RestaurantReport.txt"
#define REPORT_HEADER_MESSAGE "Restaurant Report:\nInventory State\n<Ingredient>: <AmountLeft>\n"
#define INVENTORY_CSV "bin/ingredientes.csv"
#define RECIPES_CSV "bin/recetas.csv"
#define READ_MODE "r"

//LockableMap Constants
#define UNLOCKED false
#define LOCKED true

//RecipeReader Constants
#define RECIPE_MAIN_ELEMENTS 4
#define INGREDIENT_AND_AMOUNT_PAIR 2

//Customer Constants
#define WAITING "waiting"
#define EATING "eating"
#define FINISHED "finished"
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

//Constants for customer spawner
#define SPAWNING true
#define HALT_SPAWNING false
#define MIN_CUSTOMER_COUNT 1
#define MAX_CUSTOMER_COUNT 6
#define SPAWN_RATE 5

//Constants for tables
#define TABLES_AMOUNT 6
#define OCCUPIED true
#define UNOCCUPIED false

//Constants for orders
#define READY true
#define NOT_READY false

#define PREP_DELAY 2
#define MIN_PREP_TIME 10

#define EATING_DELAY 3
#define MIN_EATING_TIME 10


#endif