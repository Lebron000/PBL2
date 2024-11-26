#include "ticket.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <algorithm>
string getCurrentDateTime()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream oss;
    oss << put_time(localTime, "%d/%m/%y %H:%M");
    return oss.str();
}

ticket::ticket(string id, string customer, string movie, string seat, string movietime, string staff,string ID)
{
    this->TicketId = id;
    this->CustomerName = customer;
    this->MovieName = movie;
    this->Seat = seat;
    this->Price = 55000;
    this->BuyTime = getCurrentDateTime();
    this->MovieTime = movietime;
    this->NameStaff = staff;
    this->ID = id;
}
ticket::~ticket()
{
}
void ticket::show()
{
    
    cout << "o" << std::string(38, '=') << "o" << endl;
    std::cout << "\t  TicketId:   "  << TicketId << endl;
    std::cout << "  Movie:\t"  << MovieName << endl;
    std::cout << "  START:\t"  << MovieTime << endl;
    std::cout << "  Price:\t"  << Price << "VND " << endl;
    std::cout << "  CUSTOMER:    "  << CustomerName << endl;
    std::cout << "  STAFF:       "  << NameStaff << " " <<endl;
    std::cout << "  BUYTIME:     "  << BuyTime  << endl;
    cout << "o" << std::string(38, '=') << "o";
}

string ticket::removeHyphens(string str)
{
    // Xóa tất cả các ký tự '-' khỏi chuỗi
    str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
    return str;
}
string ticket::getId()
{
    return this->TicketId;
}

string ticket::getCustomerName()
{
    return this->CustomerName;
}

string ticket::getMovieName()
{
    return this->MovieName;
}

string ticket::getSeat()
{
    return this->Seat;
}

int ticket::getPrice()
{
    return this->Price;
}

string ticket::getBuyTime()
{
    return this->BuyTime;
}

string ticket::getMovieTime()
{
    return this->MovieTime;
}

string ticket::getNameStaff()
{
    return this->NameStaff;
}

void ticket::setId(string id)
{
    this->TicketId = id;
}

void ticket::setCustomer(string customer)
{
    this->CustomerName = customer;
}

void ticket::setMovieName(string movie)
{
    this->MovieName = movie;
}
void ticket::setMovieTime(string time)
{
    this->MovieTime = time;
}
void ticket::setSeat(string seat)
{
    this->Seat = seat;
}
void ticket::setPrice(int price)
{
    this->Price = price;
}

void ticket::setBuyTime()
{
    this->BuyTime = getCurrentDateTime();
}

void ticket::setNameStaff(string staff)
{
    this->NameStaff = staff;
}

void ticket::SaveToFile()
{
    ofstream outFile("ticket.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << TicketId;
        outFile << ";" << CustomerName;
        outFile << ";" << MovieName;
        outFile << ";" << Seat;
        outFile << ";" << Price;
        outFile << ";" << BuyTime;
        outFile << ";" << MovieTime;
        outFile << ";" << NameStaff;
        outFile << ";" << ID << endl;
        outFile.close();
    }
}

bool ticket::operator==(const ticket &t)
{
    if (this->TicketId == t.TicketId)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &o, const ticket &t)
{
    o << t.TicketId;
    o << ";" << t.CustomerName;
    o << ";" << t.MovieName;
    o << ";" << t.Seat;
    o << ";" << t.Price;
    o << ";" << t.BuyTime;
    o << ";" << t.MovieTime;
    o << ";" << t.NameStaff << endl;
    return o;
}
// void ticket::readTicket(ifstream& inFile, const string& targetId){
//     ticket ticket;
//         std::string line;

//         while (std::getline(inFile, line)) {
//             std::string id, customer, movie, seat, buytime, movietime, staffname;
//             int price;

//             std::size_t pos = 0;
//             std::string token;
//             int count = 0;
//             while ((pos = line.find(";")) != string::npos) {
//                 token = line.substr(0, pos);
//                 line.erase(0, pos + 1);
//                 switch (count) {
//                     case 0:
//                         id = token;
//                         break;
//                     case 1:
//                         customer = token;
//                         break;
//                     case 2:
//                         movie = token;
//                         break;
//                     case 3:
//                         seat = token;
//                         break;
//                     case 4:
//                         price = std::stoi(token);
//                         break;
//                     case 5:
//                         buytime = token;
//                         break;
//                     case 6:
//                         movietime = token;
//                         break;
//                     case 7:
//                         staffname = token;
//                         break;
//                 }
//                 count++;
//             }

//             if (id == targetId) {
//                 ticket.TicketId = id;
//                 ticket.CustomerName = customer;
//                 ticket.MovieName = movie;
//                 ticket.Seat = seat;
//                 ticket.Price = price;
//                 ticket.BuyTime = buytime;
//                 ticket.MovieTime = movietime;
//                 ticket.NameStaff = staffname;
//                 ticket.show();
//                 inFile.close();
//                 return;
//             }
//         }
//         cout << "Khong tim thay id cua hoa don";
// }
