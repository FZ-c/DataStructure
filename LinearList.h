
/*
** Author:	FZChen
** Date:	2019/1/23
** Version:	v0.2
*/
#pragma once
template<class Type>

class Array
{
private:
	//线性表大小
	size_t Array_size = 0;

	//删除范围内的元素
	///TODO: 完成迭代器后再编写 编写后设置为public
	void erase(Type* pos){}

	//插入元素至某个位置
	///TODO: 完成迭代器后再编写 编写后设置为public
	void insert(Type* pos){}
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



	//成员函数

	//返回线性表元素个数
	size_t length() const
	{
		return Array_len;
	}

	//返回线性表大小
	size_t size() const
	{
		return Array_size;
	}

	//返回线性表首地址
	Type* begin() const
	{
		return Arr;
	}

	//返回线性表最后一个元素的下一个地址
	Type* end() const
	{
		return Arr + Array_len;
	}

	//在线性表最后插入一个值
	void push_back(Type data)
	{
		if (Array_len == Array_size)
		{
			Arr = (Type*)realloc(Arr, sizeof(Type)*Array_size * 2);
			Array_size *= 2;
		}
		Arr[Array_len++] = data;
	}

	//返回线性表的最后一个元素
	Type& back() const
	{
		return Arr[Array_len - 1];

	}

	//清空线性表
	void clear()
	{
		free(Arr);
		Arr = new Type;
		Array_size = 1;
		Array_len = 0;
	}

	//判断线性表是否为空
	bool empty() const
	{
		return Array_len == 0;
	}

	//返回第一个元素
	Type* front()const
	{
		return Arr[0];
	}

	//删除最后一个元素
	void pop_back()
	{
		if (Array_len > 0)
			Arr[Array_len--] = 0;
	}

	//重新分配线性表内存
	void reserve(size_t n)
	{
		if (n >= Array_len)
		{
			Arr = (Type*)realloc(Arr, sizeof(Type)*n);
			memset(Arr + Array_len, 0, sizeof(Type)*(n - Array_len));
		}
	}

	//重新分配线性表内存（不安全，带有初始化）
	void resize(size_t n, Type val = Type())
	{
		Type* tem = (Type*)malloc(sizeof(Type)*n);
		memcpy(tem, Arr, sizeof(Type)*n);
		Array_len = Array_size = n;
		free(Arr);
		Arr = tem;
		for (int i = 0; i < Array_len; i++)
		{
			Arr[i] = val;
		}
	}

	//重新分配线性表内存以适应线性表元素
	void shrink_to_fit()
	{
		if (Array_len != 0)
			Arr = (Type*)realloc(sizeof(Type)*Array_len);
		else
			Arr = (Type*)realloc(sizeof(Type));
	}

	//交换两个线性表
	void swap(Array& x)
	{
		Type* tem = (Type*)malloc(sizeof(Type)*Array_size);
		memcpy(tem, Arr, sizeof(Type)*Array_size);
		this->resize(x.Array_size);
		memcpy(Arr, x.Arr, sizeof(Type)*Array_size);
		x.resize(this->Array_size);
		memcpy(x.Arr, tem, sizeof(Type)*x.Array_size);
		free(tem);
		size_t s_tem;
		std::swap(x.Array_len, this->Array_len);
		std::swap(x.Array_size, this->Array_size);
	}


	//运算符重载

	//重载下标运算符
	Type& operator[](size_t pos)
	{
		if (pos > Array_size)
		{
			Arr = (Type*)realloc(Arr, sizeof(Type)*(pos + 1));
			memset(Arr + Array_size, 0, sizeof(Type)*(pos + 1));
		}
		if (pos >= Array_len)
			Array_len = pos + 1;
		return Arr[pos];
	}

	//赋值运算符（复制操作）
	Array& operator= (const Array& x)
	{
		clear();
		Arr = (Type*)malloc(sizeof(Type)*x.Array_size);
		Array_size = x.Array_size;
		Array_len = x.Array_len;
		memcpy(Arr, x.Arr, sizeof(Type)*Array_size);
		return *this;
	}


};