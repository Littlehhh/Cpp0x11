//
// Created by HuiWang on 2019/11/8.
//

#ifndef CPP0X11_SPACES_IN_TEMPLATE_EXPRESSION_AND_NULLPTR_H
#define CPP0X11_SPACES_IN_TEMPLATE_EXPRESSION_AND_NULLPTR_H

#include <vector>
#include <list>
std::vector<std::list<int> > t; //equals to
std::vector<std::list<int>> l;

//And nullptr help solve f(void *)  new keyword
int * p = nullptr;

// auto: declare a variable or an object without specifying its specific type
// the type pretty long or complicated expression
auto i = 42;
std::vector<std::string> v;
auto pos = v.begin();

#endif //CPP0X11_SPACES_IN_TEMPLATE_EXPRESSION_AND_NULLPTR_H
