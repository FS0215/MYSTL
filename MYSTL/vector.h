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
		static_assert(!std::is_same<bool, T>::value, "vector<bool> is abandoned in mystl");
	public:
		//vector 的嵌套型别定义
		typedef mystl::allocator<T>										allocator_type;
		typedef mystl::allocator<T>										data_allocator;

		typedef typename allocator_type::value_type						value_type;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_conference				const_reference;
		typedef typename allocator_type::size_type						size_type;
		typedef typename allocator_type::difference_type				difference_type;

		typedef value_type* iterator;
		typedef const value_type* const_iterator;
		typedef mystl::reverse_iterator<iterator>						reverse_iterator;
		typedef mystl::reverse_iterator<const_iterator>					const_reverse_iterator;

		allocator_type get_allocator() { return data_allocator(); }

	private:
		iterator begin_;				//  表示目前使用空间的头部
		iterator end_;					//  表示目前使用空间的尾部
		iterator cap_;					//	表示目前储存空间的尾部

	public:
		//	构造、复制、移动、析构函数
		vector() noexcept
		{
			try_init();
		}
	private:
		void      try_init() noexcept;
	};
};


/***********************************************************************************************/
//	helper function

//	try_init  函数，若分配失败则忽略，不抛出异常
//template <class T>
//void vector<T>::try_init() noexcept
//{
//	try
//	{
//		begin_ = data_allocator::allocate(16);
//		end_ = begin_;
//		cap_ = begin_ + 16;
//	}
//	catch (...)
//	{
//		begin_ = nullptr;
//		end_ = nullptr;
//		cap_ = nullptr;
//	}
//}
#endif // !MYSTL_VECTOR_H
