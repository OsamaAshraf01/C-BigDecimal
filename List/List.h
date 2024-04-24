//
// Created by OSAMA ASHRAF on 4/13/2024.
//
/*=====List Example========
    List l1, l2, l3;
    l1 = {"osama", 45, 98.5, 'A'};
    l1.append(14.5);
    l1.append("Ahmed");


    // Adding two lists
    l2 = {14, 89.4, "Omar"};
    l3 = l1 + l2;

    // Printing
    cout<<l3;
============================*/

#ifndef RA7AL_LIST_H
#define RA7AL_LIST_H
#include "Any.h"
#include <vector>
using namespace std;

class List {
private:
    vector<Any> values;


public:
    /// Constructor
    template<typename... Args>
    List(Args... args) {
        this->initialize(args...);
    }

    template<typename T, typename... Args>
    void initialize(T first, Args... rest) {
        values.emplace_back(first);
        this->initialize(rest...);
    }

    // Base Case
    void initialize() {}


    /// Methods
    void append(Any e);
    string getItem(int index);
    string toString();
    int size();


    /// Iterators
    using iterator = vector<Any>::iterator;
    iterator begin();
    iterator end();



    /// Operators
    friend ostream &operator<<(ostream &os, List l);
    List operator+(List &other);
    Any& operator[](int index);
};


#endif //RA7AL_LIST_H
