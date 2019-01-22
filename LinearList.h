
/*
** Author:	FZChen
** Date:	2019/1/22
** Version:	v0.1
*/
#pragma once
template<class Type>

class Array
{
private:
	//线性表大小
	size_t Array_size = 0;
public:
	//线性表首地址
	Type *Arr;
	//线性表元素个数
	size_t Array_len;

	//构造函数
	//未完成：参数为数组的构造

	//默认构造函数：线性表长度为1
	explicit Array()
	{
		Arr = new Type;
		Array_size = 1;
		memset(Arr, 0, sizeof(Arr)*Array_size);
	}

	//以长度为参数的构造函数：线性表长度为参数值
	explicit Array(size_t arr_len)
	{
		Arr = new Type[arr_len];
		Array_size = arr_len;
		memset(Arr, 0, sizeof(Arr)*Array_size);
	}

	//返回线性表元素个数
	size_t length()
	{
		return Array_len;
	}

	//返回线性表首地址
	Type* begin()
	{
		return Arr;
	}

	//返回线性表最后一个元素的下一个地址
	Type* end()
	{
		return Arr + Array_len;
	}

	//在线性表最后插入一个值
	void push_back(Type data)
	{
		if (Array_len == Array_size - 1)
		{
			Arr = (Type*)realloc(Arr, sizeof(Type)*Array_size * 2);
			Array_size *= 2;
		}
		Arr[Array_len++] = data;
	}

	//重载下标运算符
	///TODO: 未实现下标赋值时数组元素个数改变
	Type& operator[](size_t pos)
	{
		return Arr[pos];
	}
};