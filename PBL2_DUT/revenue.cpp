#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "revenue.h"
#include "Staff.h"
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <sstream>
string getCurrentDateTime()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream oss;
    oss << put_time(localTime, "%d/%m/%y");
    return oss.str();
}

revenue::revenue(int x)
    : money(x) {}

revenue::~revenue() {}

// void revenue::staff_inDay(string id)
// {
//     staff *s = this->search(id);
//     if (s == NULL)
//     {
//         cout << "\n ID not found! "<< endl;
//         return;
//     }
//     ifstream inputFile("ticket.txt");

//     if (!inputFile.is_open())
//     {
//         cerr << "Error!" << endl;
//         return;
//     }

//     string line;
//     while (getline(inputFile, line))
//     {

//         size_t pos = line.find(';', 0);
//         pos = line.find(';', pos + 1);
//         pos = line.find(';', pos + 1);
//         pos = line.find(';', pos + 1);
//         line.erase(0, pos + 1);
//         pos = line.find(';', 0);

//         string RV = line.substr(0, pos);
//         line.erase(0, pos + 1);
//         string day = line.substr(0, 8);
//         pos = line.find(';', 0);
//         line.erase(0, pos + 1);
//         pos = line.find(';', 0);
//         line.erase(0, pos + 1);
//         pos = line.find(';', 0);
//         line.erase(0, pos + 1);
//         string idx = line.substr(0, pos);
//         cout << getCurrentDateTime() << ", " << day << ", " << id << ", " << idx << endl;
//         pos = 0;
//         if (getCurrentDateTime() == day && id == idx)
//         {
//             this->money += stol(RV);
//             cout << RV << ", ";
//         }
//     }

//     inputFile.close();
//     staff sxmax = (*s);
//     cout << sxmax.getName() << ": " << this->money << endl;
// }

ostream &operator<<(ostream &o, revenue &x)
{
    o << x.money << endl;
    return o;
}
void revenue::total_inDay()
{
    string id_t = "";
    long total = 0;
    ifstream inputFile("ticket.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error!" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line))
    {
        size_t pos = line.find(';', 0);
        pos = line.find(';', pos + 1);
        pos = line.find(';', pos + 1);
        pos = line.find(';', pos + 1);
        line.erase(0, pos + 1);
        pos = line.find(';', 0);

        string RV = line.substr(0, pos);
        line.erase(0, pos + 1);
        string day = line.substr(0, 8);
        pos = line.find(';', 0);
        line.erase(0, pos + 1);
        pos = line.find(';', 0);
        line.erase(0, pos + 1);
        pos = line.find(';', 0);
        string name = line.substr(0, pos);
        line.erase(0, pos + 1);
        string idx = line.substr(0, pos);
        pos = 0;
        cout << getCurrentDateTime() <<", " << day << endl;
        if (getCurrentDateTime() == day)
        {
            //total += stol(RV);
            total +=55000;
        }
        if (idx != id_t)
        {
            cout << name << ", " << idx <<", " << id_t << ": " << total << ","<< RV << endl;
            total = 0;
            id_t = idx;
        }
    }
    inputFile.close();
}
