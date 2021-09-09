#pragma once
#ifndef MYSTL_VECTOR_H_
#define MYSTL_VECTOR_H_

// 这个头文件包含一个模板类 vector
// vector : 向量
//
// notes:
//
// 异常保证：
// mystl::vector<T> 满足基本异常保证，部分函数无异常保证，并对以下函数做强异常安全保证：
//	* emplace
//	* emplace_back
//	* push_back
// 当 std::is_nothrow_move_assignable<T>::value == true 时，以下函数也满足强异常保证：
//	* reserve
//	* resize
//	* insert



#include <initializer_list>

#include "iterator.h"
#include "memory.h"
#include "util.h"
#include "exceptdef.h"

namespace mystl
{
#ifdef max
#pragma message("#undefing marco max")
#undef max
#endif // max

#ifdef min
#pragma message("#undefing marco min")
#undef min
#endif // min

// 模板类: vector 
// 模板参数 T 代表类型
template <class T>
class vector
{

};
}


#endif // !MYSTL_VECTOR_H
