//
// Created by HuiWang on 2019/11/8.
//

#ifndef CPP0X11_VARIADIC_TEMPLATES_H
#define CPP0X11_VARIADIC_TEMPLATES_H
// cpp0x11 pack  template parameters pack
// or function parameter types pack
// or function parameter pack
#include <iostream>
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
// which one is better ?

template <typename T, typename... Types>
void print(const T& firstArg, const Types& ... args){
    std::cout<< firstArg << std::endl;
    std::cout <<  "sizeof...(args)" << std::endl;
    std::cout <<  sizeof...(args) << std::endl;
    print(args...);

}

#endif //CPP0X11_VARIADIC_TEMPLATES_H
