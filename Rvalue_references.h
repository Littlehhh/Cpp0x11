//
// Created by HuiWang on 2019/11/13.
//

#ifndef CPP0X11_RVALUE_REFERENCES_H
#define CPP0X11_RVALUE_REFERENCES_H
// Rvalue references are a new reference type Cpp0x13
// solve unnecessary copying perfect forwarding
// Lvalue can appear operator= left
// Rvalue only appear operator= right

// for example
// int
//int a=9;
//int b=4;
//a=b; //ok
//b=a; //ok
//a=a+b; //ok
//a+b=42; //[error] Lvalue required as left operand of assignment

// string
//string s1("Hello");
//string s2("World");
//s1 + s2 = s2; // can compile
//string()="World"; // temp obj assignment

//int foo(){ return 5;}
//int x = foo();   // ok
//int *p = &foo(); // error
//foo() = 7;       // error




//#include <iterator>
class MyString{
private:
    char* _data;

public:
    // copy ctor
    MyString(const MyString& str):_data(str._data){

    }
    // copy assignment
    MyString& operator=(const MyString& str) {
        this->_data = str._data;
        return *this;
    }

//    MyString&operator
    // move ctor only move the pointer  ensure never use str
    MyString(MyString&& str) noexcept :_data(str._data){
        str._data = nullptr; // important
    }

    // move assignment
    MyString& operator=(MyString&& str) noexcept {
        if(this != &str){
            if(this->_data)
                delete _data;
            _data = str._data;
            str._data = nullptr;
        }
        return *this;
    }

};

// perfect forwarding
// std::move will converte Lvalue to Rvalue


#endif //CPP0X11_RVALUE_REFERENCES_H
