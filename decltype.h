//
// Created by HuiWang on 2019/11/9.
//

#ifndef CPP0X11_DECLTYPE_H
#define CPP0X11_DECLTYPE_H
// decltype : unevaluated context
// used when declare return types or in meta programming or pass lambda type
#include <map>
#include <string>
std::map<std::string, float > coll;
decltype(coll)::value_type elem;
// before cpp0x11
std::map<std::string, float >::value_type elem0;
// 1 used to declare return type
// it not possible befor cpp0x11
//template <typename T1, typename T2>
//decltype(x+y) add(T1 x, T2 y);  return expression uses objects not introduced
template <typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x+y);


// 2 meta programming
template <typename T>
void test_decltype(T obj) {
    std::map<std::string, float>::value_type elem1;

    std::map<std::string, float> coll1;
    decltype(coll)::value_type elem2;


    // use decltype
    typedef typename decltype(obj)::iterator iType;

    typedef typename T::iterator iType;
    decltype(obj) anotherObj(obj);

}


// 3 pass the type of lambda
class Person{
public:
        void firstname() const {

        }
        void lastname() cosnt {

        }
};

auto cmp = [](const Person& p1, const Person& p2){
    return p1.lastname()<p2.lastname()
};

std::set<Person, decltype(cmp)> coll1(cmp);

#endif //CPP0X11_DECLTYPE_H
