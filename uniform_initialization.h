//
// Created by HuiWang on 2019/11/8.
//

#ifndef CPP0X11_UNIFORM_INITIALIZATION_H
#define CPP0X11_UNIFORM_INITIALIZATION_H

#include <initializer_list>
// Initialization could happen with parentheses, braces, or assignment operators
// use braces !!!!
int values[] = {1,2,3};
// backend
std::initializer_list<int> temp;

#endif //CPP0X11_UNIFORM_INITIALIZATION_H
