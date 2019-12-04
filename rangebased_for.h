//
// Created by HuiWang on 2019/11/9.
//

#ifndef CPP0X11_RANGEBASED_FOR_H
#define CPP0X11_RANGEBASED_FOR_H

#include <iostream>
#include <vector>

void range_for(){
    for(int i : {2,3,4,5,10,20}){
        std::cout << i << std::endl;
    }
    std::vector<double> vec;

    //copy version
    for( auto elem : vec ){
        std::cout << elem << std::endl;
    }
    //copy pointer
    for( auto& elem : vec ){
        std::cout << elem << std::endl;
    }
    //https://stackoverflow.com/questions/26991393/what-does-auto-e-do-in-range-based-for-loops
    for( auto&& elem : vec ){
        std::cout << elem << std::endl;
    }
}

// 接受容器的全局函数 begin() end()
template <typename T>
void printElements(const T& coll){
    for(const auto& elem: coll)
        std::cout << elem << std::endl;
}

#endif //CPP0X11_RANGEBASED_FOR_H
