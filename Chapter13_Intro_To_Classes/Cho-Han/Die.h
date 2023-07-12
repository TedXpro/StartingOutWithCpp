#ifndef DIE_H
#define DIE_H

class Die
{
private:
    int sides;
    int value;

public:
    Die(int = 6);
    void roll();
    int getSides()
    {
        return sides;
    }
    int getValue()
    {
        return value;
    }
};

#endif