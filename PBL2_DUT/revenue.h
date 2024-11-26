#pragma once
#include <iostream>
#include "Staff.h"
#include "list.h"
using namespace std;

class revenue : protected list<staff>
{
private:
    long money;
public:
    revenue(int = 0);
    ~revenue();
    
    //void staff_inDay(string = "");
    void total_inDay();

    friend ostream& operator<<(ostream&, revenue&);
};

