//
// Created by OSAMA ASHRAF on 4/13/2024.
//
/*==============Example==============
    Any x;
    x = 5;
    x = 14.7;
    x = "Osama";
    cout<<x;
 ==================
    Any x, y;
    x = 5;
    y = 6.6;
    cout << y + x;    // 11.6
 ==================
    Any x, y;
    cin >> x >> y;
    cout << x + y << endl;
    cout << (x > y);
 =====================================*/
#ifndef RA7AL_ANY_H
#define RA7AL_ANY_H
#include <iostream>
#include <variant>
#include <string>
#include <sstream>
using namespace std;
using Variant = variant<int, double, string, char>;
// TODO: Handle 2D Lists



class Any : public Variant{
private:
    string toString();
public:
    using Variant::variant;   // bringing all variant's constructors
    friend class List;


    /// Operators
    Any operator +(Any other);
    Any operator -(Any other);
    Any operator *(Any other);
    Any operator /(Any other);
    bool operator >(Any other);
    bool operator <(Any other);
    bool operator >=(Any other);
    bool operator <=(Any other);
    bool operator ==(Any other);
    bool operator !=(Any other);
    friend ostream& operator <<(ostream& os, Any x);
};


#endif //RA7AL_ANY_H
