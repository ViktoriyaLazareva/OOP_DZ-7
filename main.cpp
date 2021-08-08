#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <memory>

using namespace std;

//Task 1.1-----------------------------------------------------

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date();
    ~Date();

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    int getDay();
    int getMonth();
    int getYear();

    friend ostream& operator<< (ostream& os, const Date& n_Date);

};

Date::Date(){}
Date::~Date(){}

void Date::setDay(int d){
    day = d;
}

void Date::setMonth(int m){
    month = m;
}

void Date::setYear(int y){
    year = y;
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}
ostream& operator<< (ostream& os, const Date& n_Date){
    os << "Day:" << n_Date.day << "  Month:" << n_Date.month << "  Year:"<< n_Date.year << "\n";
    return os;
}

//Task 2.1.1--------------------------------------------------------

Date* foo(Date* d1, Date* d2){

    return ((d1->getDay() > d2->getDay()) ? d1 : d2);
}

unique_ptr<Date>& foo_1(unique_ptr<Date>& d1, unique_ptr<Date>& d2){
    return ((d1->getDay() > d2->getDay()) ? d1 : d2);
}

//Task 2.1.2------------------------------------------------------
void swap_ptr(unique_ptr<Date>& d1, unique_ptr<Date>& d2){
    unique_ptr<Date> temp;
    temp = move(d2);
    d2 = move(d1);
    d1 = move(temp);

}


int main()
{
//Task 1.2--------------------------------------------------
    unique_ptr<Date> today(new Date());
    unique_ptr<Date> date;

    today->setDay(25);
    today->setMonth(12);
    today->setYear(1925);
    cout << *(today) << endl;

    date = move(today);
    cout << *(date) << endl;

    if(today == nullptr)
    cout << "today is now nullptr" << endl;
    cout << "-----------------------------" << endl;

//Task 2.2.1---------------------------------------------------

    unique_ptr<Date> date1(new Date());
    date1->setDay(15);
    date1->setMonth(12);
    date1->setYear(1925);

    unique_ptr<Date> date2(new Date());

    date2->setDay(16);
    date2->setMonth(12);
    date2->setYear(1925);

    cout << *(foo(date2.get(), date1.get())) << endl;//variant 1
    cout <<*(foo_1(date2, date1)) << endl;//variant2
    cout << "-----------------------------" << endl;

//Task 2.2.2--------------------------------------------------

    swap_ptr(date1, date2);

    cout << *date1 << endl;

    system ("Pause");
    return 0;
}
