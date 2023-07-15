#ifndef MATHSTACK_H
#define MATHSTACK_H

#include "IntStack.h"

class MathStack : public IntStack
{
public:
    MathStack(int n) : IntStack(n) {}

    void add();
    void sub();
};

#endif
