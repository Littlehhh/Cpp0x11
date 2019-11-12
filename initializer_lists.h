//
// Created by HuiWang on 2019/11/8.
//

#ifndef CPP0X11_INITIALIZER_LISTS_H
#define CPP0X11_INITIALIZER_LISTS_H

#include <iostream>
#include <initializer_list>

void print(std::initializer_list<int> vals){
    for(auto p = vals.begin(); p != vals.end(); ++p){
        std::cout << *p << std::endl;
    }
}

class P{
public:
    P(int a, int b){
        std::cout << a << b << std::endl;
    }
    P(std::initializer_list<int> init_list){
        for(auto i : init_list){
            cout << i << " ";
        }
        cout << endl;
    }
};


#endif //CPP0X11_INITIALIZER_LISTS_H
