#pragma once
#ifndef MYSTL_VECTOR_H_
#define MYSTL_VECTOR_H_

// ���ͷ�ļ�����һ��ģ���� vector
// vector : ����
//
// notes:
//
// �쳣��֤��
// mystl::vector<T> ��������쳣��֤�����ֺ������쳣��֤���������º�����ǿ�쳣��ȫ��֤��
//	* emplace
//	* emplace_back
//	* push_back
// �� std::is_nothrow_move_assignable<T>::value == true ʱ�����º���Ҳ����ǿ�쳣��֤��
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

	// ģ����: vector 
	// ģ����� T ��������
	template <class T>
	class vector
	{
		static_assert(!std::is_same<bool, T>::value, "vector<bool> is abandoned in mystl");
	public:
		//vector ��Ƕ���ͱ���
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
		iterator begin_;				//  ��ʾĿǰʹ�ÿռ��ͷ��
		iterator end_;					//  ��ʾĿǰʹ�ÿռ��β��
		iterator cap_;					//	��ʾĿǰ����ռ��β��

	public:
		//	���졢���ơ��ƶ�����������
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

//	try_init  ������������ʧ������ԣ����׳��쳣
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
