//
// Created by OSAMA ASHRAF on 4/13/2024.
//

#include "Any.h"
bool isInt(Any& x){return holds_alternative<int>(x);}
bool isDouble(Any& x){return holds_alternative<double>(x);}
bool isString(Any& x){return holds_alternative<string>(x);}
bool isChar(Any& x){return holds_alternative<char>(x);}

string Any::toString(){
    ostringstream oss;
    if (holds_alternative<int>(*this)) {
        return to_string(get<int>(*this));
    } else if (holds_alternative<double>(*this)) {
        return to_string(get<double>(*this));
    } else if (holds_alternative<string>(*this)) {
        return get<string>(*this);
    } else if (holds_alternative<char>(*this)) {
        oss << get<char>(*this);
        return oss.str();
    } else {
        return "Unknown type";
    }
}

enum DataType {
    Integer, Double, Char, String
};

static DataType determineType(const string &str) {
    try {
        stod(str);
        if (str.find('.') != -1)
            return Double;
        throw std::invalid_argument("");
    } catch (const invalid_argument &) {
        try {
            stoi(str);
            for (char c: str)
                if (!isdigit(c) && c != *str.begin()) // To handle Date values
                    return String;
            return Integer;
        } catch (const invalid_argument &) {
            if ((int)str.size() > 1)
                return String;
            return Char;
        }

    }

}

/// Operators
Any Any::operator +(Any other){
    if (isInt(*this)){
        if (isInt(other)){
            return get<int>(*this) + get<int>(other);
        } else if (isDouble(other)){
            return get<int>(*this) + get<double>(other);
        }
    } else if (isDouble(*this)){
        if (isInt(other)){
            return get<double>(*this) + get<int>(other);
        } else if (isDouble(other)){
            return get<double>(*this) + get<double>(other);
        }
    }
    cerr << "Unknown type";
}
Any Any::operator -(Any other){
    if (isInt(*this)){
        if (isInt(other)){
            return get<int>(*this) - get<int>(other);
        } else if (isDouble(other)){
            return get<int>(*this) - get<double>(other);
        }
    } else if (isDouble(*this)){
        if (isInt(other)){
            return get<double>(*this) - get<int>(other);
        } else if (isDouble(other)){
            return get<double>(*this) - get<double>(other);
        }
    }
    cerr << "Unknown type";
}
Any Any::operator *(Any other){
    if (isInt(*this)){
        if (isInt(other)){
            return get<int>(*this) * get<int>(other);
        } else if (isDouble(other)){
            return get<int>(*this) * get<double>(other);
        }
    } else if (isDouble(*this)){
        if (isInt(other)){
            return get<double>(*this) * get<int>(other);
        } else if (isDouble(other)){
            return get<double>(*this) * get<double>(other);
        }
    }
    cerr << "Unknown type";
}
Any Any::operator /(Any other){
    if (isInt(*this)){
        if (isInt(other)){
            return get<int>(*this) / get<int>(other);
        } else if (isDouble(other)){
            return get<int>(*this) / get<double>(other);
        }
    } else if (isDouble(*this)){
        if (isInt(other)){
            return get<double>(*this) / get<int>(other);
        } else if (isDouble(other)){
            return get<double>(*this) / get<double>(other);
        }
    }
    cerr << "Unknown type";
}
bool Any::operator >(Any other) {
    if (isInt(*this)) {
        if (isInt(other)) {
            return get<int>(*this) > get<int>(other);
        } else if (isDouble(other)) {
            return get<int>(*this) > get<double>(other);
        }
    } else if (isDouble(*this)) {
        if (isInt(other)) {
            return get<double>(*this) > get<int>(other);
        } else if (isDouble(other)) {
            return get<double>(*this) > get<double>(other);
        }
    } else if (isString(*this) && isString(other)) {
        return get<string>(*this) > get<string>(other);
    } else if (isChar(*this) && isChar(other)) {
        return get<char>(*this) > get<char>(other);
    }
    cerr << "Unknown type";
}
bool Any::operator <(Any other){
    if (isInt(*this)){
        if (isInt(other)){
            return get<int>(*this) < get<int>(other);
        } else if (isDouble(other)){
            return get<int>(*this) < get<double>(other);
        }
    } else if (isDouble(*this)){
        if (isInt(other)){
            return get<double>(*this) < get<int>(other);
        } else if (isDouble(other)){
            return get<double>(*this) < get<double>(other);
        }
    } else if (isString(*this) && isString(other)){
        return get<string>(*this) < get<string>(other);
    } else if (isChar(*this) && isChar(other)){
        return get<char>(*this) < get<char>(other);
    }
    cerr << "Unknown type";
}
bool Any::operator >=(Any other){
    if (isInt(*this)){
        if (isInt(other)){
            return get<int>(*this) >= get<int>(other);
        } else if (isDouble(other)){
            return get<int>(*this) >= get<double>(other);
        }
    } else if (isDouble(*this)){
        if (isInt(other)){
            return get<double>(*this) >= get<int>(other);
        } else if (isDouble(other)){
            return get<double>(*this) >= get<double>(other);
        }
    } else if (isString(*this) && isString(other)){
        return get<string>(*this) >= get<string>(other);
    } else if (isChar(*this) && isChar(other)){
        return get<char>(*this) >= get<char>(other);
    }
    cerr << "Unknown type";
}
bool Any::operator <=(Any other){
    if (isInt(*this)){
        if (isInt(other)){
            return get<int>(*this) <= get<int>(other);
        } else if (isDouble(other)){
            return get<int>(*this) <= get<double>(other);
        }
    } else if (isDouble(*this)){
        if (isInt(other)){
            return get<double>(*this) <= get<int>(other);
        } else if (isDouble(other)){
            return get<double>(*this) <= get<double>(other);
        }
    } else if (isString(*this) && isString(other)){
        return get<string>(*this) <= get<string>(other);
    } else if (isChar(*this) && isChar(other)){
        return get<char>(*this) <= get<char>(other);
    }
    cerr << "Unknown type";
}
bool Any::operator ==(Any other){
    if (isInt(*this)){
        if (isInt(other)){
            return get<int>(*this) == get<int>(other);
        } else if (isDouble(other)){
            return get<int>(*this) == get<double>(other);
        }
    } else if (isDouble(*this)){
        if (isInt(other)){
            return get<double>(*this) == get<int>(other);
        } else if (isDouble(other)){
            return get<double>(*this) == get<double>(other);
        }
    } else if (isString(*this) && isString(other)){
        return get<string>(*this) == get<string>(other);
    } else if (isChar(*this) && isChar(other)){
        return get<char>(*this) == get<char>(other);
    }
    cerr << "Unknown type";
}
bool Any::operator !=(Any other){
    if (isInt(*this)){
        if (isInt(other)){
            return get<int>(*this) != get<int>(other);
        } else if (isDouble(other)){
            return get<int>(*this) != get<double>(other);
        }
    } else if (isDouble(*this)){
        if (isInt(other)){
            return get<double>(*this) != get<int>(other);
        } else if (isDouble(other)){
            return get<double>(*this) != get<double>(other);
        }
    } else if (isString(*this) && isString(other)){
        return get<string>(*this) != get<string>(other);
    } else if (isChar(*this) && isChar(other)){
        return get<char>(*this) != get<char>(other);
    }
    cerr << "Unknown type";
}


ostream& operator <<(ostream& os, Any x){
    if (isInt(x))
        os << get<int>(x);
    else if(isDouble(x))
        os << get<double>(x);
    else if(isString(x))
        os << get<string>(x);
    else
        os << get<char>(x);
    return os;
}

