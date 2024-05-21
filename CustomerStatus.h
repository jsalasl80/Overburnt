#ifndef CUSTOMERSTATUS_H
#define CUSTOMERSTATUS_H

enum class CustomerStatus {
    Waiting,
    Ordering,
    WaitingForFood,
    Eating,
    WaitingToLeave,
    Leaving,
    Left//used to determine if it should be removed
};

#endif // CUSTOMERSTATUS_H
