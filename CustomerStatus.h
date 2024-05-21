#ifndef CUSTOMERSTATUS_H
#define CUSTOMERSTATUS_H

enum class CustomerStatus {
    Waiting,
    Seated,
    Ordering,
    WaitingForFood,
    Eating,
    WaitingForBill,//could be removed
    Paying,//could be removed
    Leaving,
    Left//used to determine if it should be removed
};

#endif // CUSTOMERSTATUS_H
