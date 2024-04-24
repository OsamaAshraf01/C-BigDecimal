#include <iostream>
#include "BigDecimal.h"
using namespace std;

int main()
{
    bigDecimal a, b;
    while(true)
    {
        cin>>a.value>>b.value;
        cout<<"a+b = "<<a+b<<"\n";
        cout<<"a-b = "<<a-b<<"\n";
        cout<<"a*b = "<<a*b<<"\n";
        cout<<"a/b = "<<a/b<<"\n";
    }
    return 0;
}
