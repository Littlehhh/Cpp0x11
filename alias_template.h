//
// Created by HuiWang on 2019/11/9.
//

#ifndef CPP0X11_ALIAS_TEMPLATE_H
#define CPP0X11_ALIAS_TEMPLATE_H

#include <vector>
#include <iterator>

template <typename T>
using Vec = std::vector<T,std::allocator<T>>;
Vec<int> coll;
// is equals to
std::vector<int, std::allocator<int>> coll_same;

// not work
//template <typename Container, typename T>
//void test_moveable(Container cntr, T elem){
//    Container<T> c;
//    for(long i=0; i < SIZE; ++i)
//        c.insert(c.end(), T());
//    Container<T> c1(c)
//    Container<T> c2(std::move(c));
//    c1.swap(c2);
//}

// 采用 function template + iterator + traits
template <typename Container>
void test_moveable(Container c){
    typedef typename std::iterator_traits<typename Container::iterator>::value_type ValType;
    for(long i=0; i < c.Size(); ++i)
        c.insert(c.end(), ValType());
    Container c1(c);
    Container c2(std::move(c));
    c1.swap(c2);
}

// template template parameter

// and template template parameter + alias template
template <typename T>
using Vec = std::vector<T,std::allocator<T>>;

template <typename T,
          template <class> class Container>
class XCLs{
private:
        Container<T> c;
public:
        XCLs(){
            for(long i=0; i < c.Size(); ++i)
                c.insert(c.end(), T());
            Container<T> c1(c);
            Container<T> c2(std::move(c));
            c1.swap(c2);
        }
};

//Type alias
typedef void(*func)(int, int);
using func = void(*)(int, int);
void example(int, int){}
func fn = example;

// no exception
class MyString{
private:
    char* _data;
    size_t _len;
public:
    // move constructor
    MyString(MyString&& str) noexcept :_data(str._data), _len(str._len){

    }
    // move assignment
    MyString& operator=(MyString&& str) noexcept {

    }

};

#endif //CPP0X11_ALIAS_TEMPLATE_H
