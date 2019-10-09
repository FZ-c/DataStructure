
/*
** Author:	FZChen
** Date:	2019/7/30
** Version:	v0.1
*/
#pragma once

template<class Type>
class LinkNode
{
private:

	//结点内容
	Type content;

	//结点的前后结点
	Type* front = nullptr, * next = nullptr;

public:

	//构造方法

	//默认构造方法
	explicit LinkNode()
	{
		content = 0;
	}

	//以结点内容及其前后结点指针为参数的构造方法
	explicit LinkNode(const Type& content = Type(), const Type* front = nullptr, const Type* next = nullptr)
	{
		this->content = content;
		this->front = front;
		this->next = next;
	}
};

template<class Type>
class LinkList
{
private:

	//链表首尾指针
	LinkNode<Type>* List_head = nullptr, List_tail = nullptr;

	//删除范围内的元素
	///TODO: 完成迭代器后再编写 编写后设置为public
	void erase(Type* pos) {}

	//插入元素至某个位置
	///TODO: 完成迭代器后再编写 编写后设置为public
	void insert(Type* pos) {}

public:
	//链表首地址
	LinkNode<Type>* List;
	//链表元素个数
	size_t List_len;


	//构造函数

	///TODO: 参数为数组的构造
	explicit LinkList(Type* arr, int len): List_len(len)
	{
	}

	//默认构造函数：线性表长度为1
	explicit LinkList(): List_len(0)
	{
		List = new LinkNode<int>();
		List_head = List_tail = List;
	}

	//以长度为参数的构造函数：线性表长度为参数值
	explicit LinkList(size_t arr_len) : List_len(arr_len)
	{
	}


	//成员函数

	//返回链表元素个数
	size_t length() const
	{
		return List_len;
	}

	//返回链表头结点地址
	Type* begin() const
	{
		return List;
	}

	//返回链表最后一个元素的下一个地址
	Type* end() const
	{
		return Arr + Array_len;
	}

	//在链表最后插入一个值
	void push_back(Type data)
	{
		if (Array_len == Array_size)
		{
			Arr = (Type*)realloc(Arr, sizeof(Type) * Array_size * 2);
			Array_size *= 2;
		}
		Arr[Array_len++] = data;
	}

	//返回链表的最后一个元素
	Type& back() const
	{
		return Arr[Array_len - 1];

	}

	//清空链表
	void clear()
	{
		free(Arr);
		Arr = new Type;
		Array_size = 1;
		Array_len = 0;
	}

	//判断链表是否为空
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

	//交换两个链表
	void swap(Array& x)
	{
		Type* tem = (Type*)malloc(sizeof(Type) * Array_size);
		memcpy(tem, Arr, sizeof(Type) * Array_size);
		this->resize(x.Array_size);
		memcpy(Arr, x.Arr, sizeof(Type) * Array_size);
		x.resize(this->Array_size);
		memcpy(x.Arr, tem, sizeof(Type) * x.Array_size);
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
			Arr = (Type*)realloc(Arr, sizeof(Type) * (pos + 1));
			memset(Arr + Array_size, 0, sizeof(Type) * (pos + 1 - Array_size));
		}
		return Arr[pos];
	}

	//赋值运算符（复制操作）
	Array& operator= (const Array& x)
	{
		clear();
		Arr = (Type*)malloc(sizeof(Type) * x.Array_size);
		Array_size = x.Array_size;
		Array_len = x.Array_len;
		memcpy(Arr, x.Arr, sizeof(Type) * Array_size);
		return *this;
	}


};

