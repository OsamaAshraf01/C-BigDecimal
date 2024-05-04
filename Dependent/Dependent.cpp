//
// Created by OSAMA ASHRAF on 5/4/2024.
//

#include "Dependent.h"
template<typename T>
dependent<T>::dependent(T &other, function<T(T)> op) {
    intRef = &other;
    operation = op;
}

template<typename T>
dependent<T>::dependent(dependent &other, function<T(T)> op) {
    depRef = &other;
    operation = op;
}

template<typename T>
dependent<T>::operator T() {
    if (depRef)
        return operation(*depRef);
    else
        return operation(*intRef);
}