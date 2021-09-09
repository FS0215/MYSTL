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

};
}


#endif // !MYSTL_VECTOR_H
