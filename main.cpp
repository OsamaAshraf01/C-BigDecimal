#include <iostream>
#include "BigDecimal/BigDecimal.h"
#include "Dependent/Dependent.h"

using namespace std;

int main() {
//    bigDecimal a, b;
//    while(true)
//    {
//        cin>>a.value>>b.value;
//        cout<<"a+b = "<<a+b<<"\n";
//        cout<<"a-b = "<<a-b<<"\n";
//        cout<<"a*b = "<<a*b<<"\n";
//        cout<<"a/b = "<<a/b<<"\n";
//    }


    int a = 5;
    dependent<int> b(a, [](int x) { return x * 2; });
    dependent<int> c(b, [](int x) { return x * 2; });
    dependent<int> d(c, [](int x) { return x * 2; });

    cout << a << " " << b << " " << c << " " << d << "\n";
    a++;
    cout << a << " " << b << " " << c << " " << d << "\n";
    a++;
    cout << a << " " << b << " " << c << " " << d << "\n";


    return 0;


    return 0;
}
