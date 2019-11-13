//
// Created by HuiWang on 2019/11/8.
//

#ifndef CPP0X11_VARIADIC_TEMPLATES_H
#define CPP0X11_VARIADIC_TEMPLATES_H
// cpp0x11 pack  template parameters pack
// or function parameter types pack
// or function parameter pack
#include <iostream>
#include <tuple>
// 处理边界 当参数个数为0的时候
// recursive function call
void print(){
    std::cout << "call basic" << std::endl;
}
// or

template <typename T>
void print(const T& endArg){
    std::cout << endArg << std::endl;
}
template <typename... Types>
void print(const Types& ... args){
    print(args...);
}

// 1+3 more special
// which one is better ?
// when 1+3 exist, the typename... Types will never  be call

template <typename T, typename... Types>
void print(const T& firstArg, const Types& ... args){
    std::cout<< firstArg << std::endl;
    std::cout <<  "sizeof...(args)" << std::endl;
    std::cout <<  sizeof...(args) << std::endl;
    print(args...);
}

// use variadic templates rewrite printf()
void printf(const char *s){
    while(*s){
        if(*s == '%' && *(++s) != '%')
            throw std::runtime_error("invalid format string: missing arguments");
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void printf(const char *s, T value, Args... args){
    while(*s){
        if(*s == '%' && *(++s) != '%'){
            std::cout << value;
            printf(++s, args...);
            return;
        }
        std::cout << *s++;

    }
    throw std::logic_error("extra arguments provided to printf");
}

// find max
int maximum(int n){
    return n;
}

template <typename... Args>
int maximum(int n, Args... args){
    return std::max(n, maximum(args...));
}

// class templates

template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE{
    static void print(std::ostream& os, const std::tuple<Args...>& t){
        os << std::get<IDX>(t) << (IDX+1 == MAX ? "" : ",");
        PRINT_TUPLE<IDX+1, MAX, Args...>::print(os, t);
    }
};

// partial specialization to end the recursion
template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...>{
    static void print(std::ostream& os, const std::tuple<Args...>& t){

    }
};
// ostream override
template <typename... Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t){
    os << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
    return os << "]";
}

// recursive inheritance
template <typename... Values> class tuple;
template <> class tuple<>{};

template <typename Head, typename... Tail>
class tuple<Head, Tail...>:private tuple<Tail...>{
    typedef tuple<Tail...> inherited;
public:
    tuple()= default;
    explicit tuple(Head v, Tail... vtail):m_head(v), inherited(vtail...){}// initialization list
    typename Head::type head(){ return m_head; }
    inherited& tail(){ return *this;}
protected:
    Head m_head;
};


#endif //CPP0X11_VARIADIC_TEMPLATES_H
