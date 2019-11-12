//
// Created by HuiWang on 2019/11/9.
//

#ifndef CPP0X11_DEFAULT_DELETE_CTOR_H
#define CPP0X11_DEFAULT_DELETE_CTOR_H

class Zoo{
public:
    Zoo(int i1, int i2){}
    Zoo(const Zoo&) = delete;
    Zoo(Zoo&&) = default;

};

struct NoCopy{
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;
    NoCopy &operator=(const NoCopy&) = delete;
    ~NoCopy() = default;
};

struct NoDtor{
    NoDtor()= default;
    ~NoDtor() = delete;
};



#endif //CPP0X11_DEFAULT_DELETE_CTOR_H
