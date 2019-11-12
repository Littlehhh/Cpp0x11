//
// Created by HuiWang on 2019/11/9.
//

#ifndef CPP0X11_EXPLICIT_H
#define CPP0X11_EXPLICIT_H
// explicit 拒绝隐式调用
// C++ 0x11 多个参数也可以使用
struct Complex{
    int real, imag;
//    explicit
    Complex(int re, int im=0):real(re),imag(im){

    }
    Complex operator+(const Complex& x){
        return Complex((real+x.real), (imag+x.imag));

    }
};

#endif //CPP0X11_EXPLICIT_H
