//
// Created by OSAMA ASHRAF on 5/4/2024.
//

#ifndef MY_Cpp_LIBRARY_DEPENDENT_H
#define MY_Cpp_LIBRARY_DEPENDENT_H


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class dependent {
private:
    T *intRef = nullptr;
    dependent *depRef = nullptr;
    function<T(T)> operation;

public:
    dependent(T &other, function<T(T)> op = [](T x) { return x; });

    dependent(dependent &other, function<T(T)> op = [](T x) { return x; });

    operator T();
};



#endif //MY_Cpp_LIBRARY_DEPENDENT_H
