//
// Created by OSAMA ASHRAF on 4/24/2024.
//

#ifndef MY_Cpp_LIBRARY_BIGDECIMAL_H
#define MY_Cpp_LIBRARY_BIGDECIMAL_H


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define FOR(i, n) for(int i=0 ; i<(int)n ; i++)

//Functions
int pow10(int x){
    int result=1;
    FOR(i, x){
        result*=10;
    }

    return result;
}
short to_number(char c){return c-'0';}
long long int to_number(string s)
{
    reverse(s.begin(), s.end());
    long long int result=0;
    FOR(i, s.size())
    {
        result+=(s[i]-'0')* pow10(i);
    }

    return result;
}
int findPoint(string &s)
{
    int place = (int)s.find(".");
    if(place==-1)
        s.push_back('.');
    place = (int)s.find(".");

    return place;
}
void clear(string &s)
{
    findPoint(s);
    int i=s.size()-1;
    while((s[i]=='0' || s[i]=='.'))
    {
        if(s[i]=='.')
        {
            s.pop_back();
            break;
        }

        s.pop_back();

        i--;
    }

    i=s.size()-1;
    reverse(s.begin(), s.end());
    while((s[i]=='0') && (s.size()>1))
    {
        s.pop_back();
        i--;
    }
    reverse(s.begin(), s.end());
}
string smaller(string s1, string s2){
    clear(s1);  clear(s2);
    if(s1==s2)
        return "equals";
    else if(s1.size()>s2.size())
        return s2;
    else if(s1.size()<s2.size())
        return s1;
    else
    {
        FOR(i, s1.size())
        {
            if(s1[i]<s2[i])
                return s1;
            else if(s1[i]>s2[i])
                return s2;
        }
    }
    return s2;
}
void equalization(string &s1, string &s2)
{
    int size1=s1.size(), size2=s2.size();
    if(size1==size2)
        return;

    int difference=abs(size1-size2);
    string small = smaller(s1, s2);

    if(small==s1)
        FOR(i, difference){s1.push_back('0');}
    else
        FOR(i, difference){s2.push_back('0');}

}
string removePoint(string &s, int &place)
{
    place = (int)s.find(".");
    if(place+1)
        s.replace(place, 1, "");
    else
        place=s.size();
    return s;
}
void justifyPoint(string &s1, string &s2)
{
    int place1 = findPoint(s1), place2 = findPoint(s2);

    if(place1 < place2)
    {
        reverse(s1.begin(), s1.end());
        while(place1 < place2)
        {
            s1.push_back('0');
            reverse(s1.begin(), s1.end());
            place1 = (int)s1.find(".");
            reverse(s1.begin(), s1.end());
        }
        reverse(s1.begin(), s1.end());
    }
    else if(place1 > place2)
    {
        reverse(s2.begin(), s2.end());
        while(place1 > place2)
        {
            s2.push_back('0');
            reverse(s2.begin(), s2.end());
            place2 = (int)s2.find(".");
            reverse(s2.begin(), s2.end());
        }
        reverse(s2.begin(), s2.end());
    }
    equalization(s1, s2);
}
void swap(string &s1, string &s2)
{
    string temp=s1;
    s1=s2;
    s2=temp;
}
string toPositive(string &s)
{
    if(s[0]=='-')
        s.replace(0, 1, "");

    return s;
}
string toNegative(string &s)
{
    if(s[0]!='-')
    {
        reverse(s.begin(), s.end());
        s.push_back('-');
        reverse(s.begin(), s.end());
    }

    return s;
}
bool sign(string &s1, string &s2)
{
    char sign1=s1[0], sign2=s2[0];
    toPositive(s1);   toPositive(s2);
    if((sign1=='-' && sign2!='-')||(sign1!='-' && sign2=='-'))
        return true;
    else
        return false;
}
void addZeros(string &s, int x)
{
    FOR(i, x)
    {
        s.push_back('0');
    }
}








class bigDecimal{
public:
    //variables
    string value;


    //Methods
    string add(string aVal, string bVal)
    {
        //cout<<"ADD : ";
        if(aVal=="0")
            return bVal;
        else if(bVal=="0")
            return aVal;
        else if(aVal[0]!='-' && bVal[0]=='-')
            return subtract(aVal, toPositive(bVal));
        else if(aVal[0]=='-' && bVal[0]!='-')
            return subtract(bVal, toPositive(aVal));
        else if(aVal[0]=='-' && bVal[0]=='-')
            return subtract(aVal, toPositive(bVal));
        int point;

        justifyPoint(aVal, bVal);

        removePoint(aVal, point);
        removePoint(bVal, point);

        reverse(aVal.begin(), aVal.end());
        reverse(bVal.begin(), bVal.end());

        int digits[aVal.size()+1]={0};

        FOR(i, aVal.size())
        {
            digits[i]= (aVal[i]-'0') + (bVal[i]-'0');
        }
        FOR(i, aVal.size()+1)
        {
            digits[i+1]+=digits[i]/10;
            digits[i]=digits[i]%10;
        }

        reverse(digits, digits+aVal.size()+1);

        string result;
        point++;
        FOR(i, aVal.size()+1)
        {
            if(i==point)
                result.push_back('.');
            if(!(i==0 && digits[i]==0))
                result.push_back((char)(digits[i]+'0'));
        }
        clear(result);
        //cout<<result<<"\n";
        return result;
    }

    string subtract(string aVal, string bVal)
    {
        //cout<<"SUBTRACT : ";
        string result;

        if(aVal=="0")
            return multiply(bVal, "-1");
        else if(bVal=="0")
            return aVal;
        else if(aVal[0]=='-' && bVal[0]!='-')
        {
            result = add(toPositive(aVal), bVal);
            return toNegative(result);
        }
        else if(aVal[0]!='-' && bVal[0]=='-')
        {
            return add(aVal, toPositive(bVal));
        }
        else if(aVal[0]=='-' && bVal[0]=='-')
            return add(aVal, toPositive(bVal));


        clear(aVal);  clear(bVal);
        if(aVal==bVal)
            return "0";

        bool negative=false;
        if(smaller(aVal, bVal)==aVal)
        {
            swap(aVal, bVal);
            negative=true;
        }

        int point;

        justifyPoint(aVal, bVal);

        removePoint(aVal, point);
        removePoint(bVal, point);

        reverse(aVal.begin(), aVal.end());
        reverse(bVal.begin(), bVal.end());

        int digits[aVal.size()+1]={0};

        FOR(i, aVal.size())
        {
            digits[i] += (aVal[i]-'0') - (bVal[i]-'0');
            if(digits[i]<0)
            {
                digits[i]+=10;
                digits[i+1]--;
            }
        }


        FOR(i, aVal.size()+1)
        {
            digits[i+1]+=digits[i]/10;
            digits[i]=digits[i]%10;
        }

        reverse(digits, digits+aVal.size()+1);


        point++;
        for(int i=1 ; i<(int)aVal.size()+1 ; i++)
        {
            if(i==point)
                result.push_back('.');
            if(!(i==0 && digits[i]==0))
                result.push_back((char)(digits[i]+'0'));
        }

        clear(result);

        if(negative)
        {
            reverse(result.begin(), result.end());
            result.push_back('-');
            reverse(result.begin(), result.end());
        }

        //cout<<result<<"\n";
        return result;
    }

    string multiply(string aVal, string bVal)
    {
        //cout<<"MULTIPLICATION : ";
        clear(aVal);     clear(bVal);
        if(aVal=="0" || bVal=="0")
            return "0";
        else if(aVal=="1")
            return bVal;
        else if(bVal=="1")
            return aVal;
        bool is_negative = sign(aVal, bVal);

        int pointA, pointB;
        removePoint(aVal, pointA);
        removePoint(bVal, pointB);
        pointA = aVal.size() - pointA;
        pointB = bVal.size() - pointB;


        reverse(aVal.begin(), aVal.end());
        reverse(bVal.begin(), bVal.end());

        int size=aVal.size()+bVal.size(), digits[size]={0};
        int point = size - pointA - pointB;

        FOR(i, aVal.size())
        {
            FOR(j, bVal.size())
            {
                digits[i+j]+=(aVal[i]-'0')*(bVal[j]-'0');
            }
        }
        FOR(i, size)
        {
            digits[i+1]+=digits[i]/10;
            digits[i]=digits[i]%10;
        }

        reverse(digits, digits+size);

        string result;

        FOR(i, size)
        {
            if(i==point)
                result.push_back('.');
            result.push_back((char)(digits[i]+'0'));
        }

        clear(result);
        if(is_negative)
        {
            reverse(result.begin(), result.end());
            result.push_back('-');
            reverse(result.begin(), result.end());
        }

        //cout<<result<<"\n";
        return result;
    }

    string divide(string aVal, string bVal, int numberDecimals=9)
    {
        //cout<<"DIVISION : ";
        if(bVal=="0")
            return "Error";
        else if(aVal=="0")
            return "0";
        else if(bVal=="1")
            return aVal;

        string result="";
        bool is_negative = sign(aVal, bVal);

        clear(aVal);    clear(bVal);
        while((int)aVal.find(".")+1)
        {
            aVal=multiply(aVal, "10");
            bVal=multiply(bVal, "10");
            clear(aVal);  clear(bVal);
        }

        while((int)bVal.find(".")+1)
        {
            bVal=multiply(bVal, "10");
            aVal=multiply(aVal, "10");
            clear(bVal);  clear(aVal);
        }

        int aSize=aVal.size(), point = aSize;
        addZeros(aVal, numberDecimals+aSize);

        long long int b = to_number(bVal);

        if(is_negative)
            result.push_back('-');

        string x;
        FOR(i, numberDecimals+aSize)
        {

            if(i==point) result.push_back('.');

            x.push_back(aVal[i]);
            //cout<<"_"<<x<<"_";
            long long int r = to_number(x)/b;
            //cout<<"_"<<r<<"_";
            result.push_back((char)(r+'0'));
            //cout<<"_"<<result<<"_";
            x = subtract(x, multiply(to_string(r), to_string(b)));
            //cout<<"_"<<x<<"\n";
        }
        addZeros(x, 1);
        if(to_number(x)/b>=5)
            result[numberDecimals+aSize]++;

        clear(result);
        //cout<<result<<"\n";
        return result;
    }





    //Constructors
    bigDecimal(){
        value="";
    }


    //Operators
    void operator = (bigDecimal b) {value = b.value;}
    void operator = (string val) {value = val;}
    void operator = (double val) {value = to_string(val);}



    //adding Method
    string operator +(bigDecimal b) { return add(value, b.value); }
    string operator +(string b) { return add(value, b); }
    string operator +(double b) { return add(value, to_string(b)); }


    //Subtraction Method
    string operator -(bigDecimal b) { return subtract(value, b.value); }
    string operator -(string b) { return subtract(value, b); }
    string operator -(double b) { return subtract(value, to_string(b)); }


    //Multiplication Method
    string operator *(bigDecimal b) { return multiply(value, b.value); }
    string operator *(string b) { return multiply(value, b); }
    string operator *(double b) { return multiply(value, to_string(b)); }


    //Division Method
    string operator /(bigDecimal b) {return divide(value, b.value);}
    string operator /(string b) {return divide(value, b);}
    string operator /(double b) {return divide(value, to_string(b));}


    //Comparison Operators
    bool operator >(bigDecimal b){return to_number(value)>to_number(b.value);}
    bool operator >(string b){return to_number(value)>to_number(b);}
    bool operator >(double b){return to_number(value)>b;}

    bool operator <(bigDecimal b){return to_number(value)<to_number(b.value);}
    bool operator <(string b){return to_number(value)<to_number(b);}
    bool operator <(double b){return to_number(value)<b;}

    bool operator ==(bigDecimal b){return to_number(value)==to_number(b.value);}
    bool operator ==(string b){return to_number(value)==to_number(b);}
    bool operator ==(double b){return to_number(value)==b;}

    bool operator >=(bigDecimal b){return to_number(value)>=to_number(b.value);}
    bool operator >=(string b){return to_number(value)>=to_number(b);}
    bool operator >=(double b){return to_number(value)>=b;}

    bool operator <=(bigDecimal b){return to_number(value)<=to_number(b.value);}
    bool operator <=(string b){return to_number(value)<=to_number(b);}
    bool operator <=(double b){return to_number(value)<=b;}
};





#endif //MY_Cpp_LIBRARY_BIGDECIMAL_H
