//
// Created by HuiWang on 2019/11/9.
//

#ifndef CPP0X11_DECLTYPE_H
#define CPP0X11_DECLTYPE_H
// decltype : unevaluated context
// used when declare return types or in meta programming or pass
#include <map>
std::map<std::string, float > coll;
decltype(coll)::value_type elem;
// before cpp0x11
//std::map<std::string, float >::value_type elem1;
// 1 used to declare return type
// it not possible befor cpp0x11
//template <typename T1, typename T2>
//decltype(x+y) add(T1 x, T2 y);  return expression uses objects not introduced
template <typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x+y);

#endif //CPP0X11_DECLTYPE_H
