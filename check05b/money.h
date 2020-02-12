/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
    int dollars;
    int cents;

public:
    Money();
    Money(double dollars);
    Money(double dollars, double cents);

    void prompt();
    void display() const;

    double getDollars() const;
    void setDollars(double pDollars);

    double getCents() const;
    void setCents(double pCents);
};

#endif
