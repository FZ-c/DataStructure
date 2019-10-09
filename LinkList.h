
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

	//�������
	Type content;

	//����ǰ����
	Type* front = nullptr, * next = nullptr;

public:

	//���췽��

	//Ĭ�Ϲ��췽��
	explicit LinkNode()
	{
		content = 0;
	}

	//�Խ�����ݼ���ǰ����ָ��Ϊ�����Ĺ��췽��
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

	//������βָ��
	LinkNode<Type>* List_head = nullptr, List_tail = nullptr;

	//ɾ����Χ�ڵ�Ԫ��
	///TODO: ��ɵ��������ٱ�д ��д������Ϊpublic
	void erase(Type* pos) {}

	//����Ԫ����ĳ��λ��
	///TODO: ��ɵ��������ٱ�д ��д������Ϊpublic
	void insert(Type* pos) {}

public:
	//�����׵�ַ
	LinkNode<Type>* List;
	//����Ԫ�ظ���
	size_t List_len;


	//���캯��

	///TODO: ����Ϊ����Ĺ���
	explicit LinkList(Type* arr, int len): List_len(len)
	{
	}

	//Ĭ�Ϲ��캯�������Ա���Ϊ1
	explicit LinkList(): List_len(0)
	{
		List = new LinkNode<int>();
		List_head = List_tail = List;
	}

	//�Գ���Ϊ�����Ĺ��캯�������Ա���Ϊ����ֵ
	explicit LinkList(size_t arr_len) : List_len(arr_len)
	{
	}


	//��Ա����

	//��������Ԫ�ظ���
	size_t length() const
	{
		return List_len;
	}

	//��������ͷ����ַ
	Type* begin() const
	{
		return List;
	}

	//�����������һ��Ԫ�ص���һ����ַ
	Type* end() const
	{
		return Arr + Array_len;
	}

	//������������һ��ֵ
	void push_back(Type data)
	{
		if (Array_len == Array_size)
		{
			Arr = (Type*)realloc(Arr, sizeof(Type) * Array_size * 2);
			Array_size *= 2;
		}
		Arr[Array_len++] = data;
	}

	//������������һ��Ԫ��
	Type& back() const
	{
		return Arr[Array_len - 1];

	}

	//�������
	void clear()
	{
		free(Arr);
		Arr = new Type;
		Array_size = 1;
		Array_len = 0;
	}

	//�ж������Ƿ�Ϊ��
	bool empty() const
	{
		return Array_len == 0;
	}

	//���ص�һ��Ԫ��
	Type* front()const
	{
		return Arr[0];
	}

	//ɾ�����һ��Ԫ��
	void pop_back()
	{
		if (Array_len > 0)
			Arr[Array_len--] = 0;
	}

	//������������
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


	//���������

	//�����±������
	Type& operator[](size_t pos)
	{
		if (pos > Array_size)
		{
			Arr = (Type*)realloc(Arr, sizeof(Type) * (pos + 1));
			memset(Arr + Array_size, 0, sizeof(Type) * (pos + 1 - Array_size));
		}
		return Arr[pos];
	}

	//��ֵ����������Ʋ�����
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

