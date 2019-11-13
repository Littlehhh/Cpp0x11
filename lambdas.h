//
// Created by HuiWang on 2019/11/13.
//

#ifndef CPP0X11_LAMBDAS_H
#define CPP0X11_LAMBDAS_H
// define inline function  be used as a parameter or a local object
#include <iostream>
#include <vector>

auto l = []{
    std::cout<< "Hello lambda" << std::endl;
};

void test_lambda(){
    std::vector<int> vi = {5,28,50,83,70};
    int x=30, y=100;
    vi.erase(std::remove_if(vi.begin(),
            vi.end(),
            [x,y](int n){ return x<n && n<y;}),
                    vi.end());
    for(auto i:vi){
        std::cout << i << " ";
    }
}




#endif //CPP0X11_LAMBDAS_H
