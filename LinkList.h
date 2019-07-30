
/*
** Author:	FZChen
** Date:	2019/7/30
** Version:	v0.1
*/
#pragma once

template<class Type>
class Linklist
{
private:

	//�����С
	size_t List_size = 0;

	//������βָ��
	Type* List_head = NULL, List_tail = NULL;

	//ɾ����Χ�ڵ�Ԫ��
	///TODO: ��ɵ��������ٱ�д ��д������Ϊpublic
	void erase(Type* pos) {}

	//����Ԫ����ĳ��λ��
	///TODO: ��ɵ��������ٱ�д ��д������Ϊpublic
	void insert(Type* pos) {}

public:
	//�����׵�ַ
	Type* List;
	//����Ԫ�ظ���
	size_t List_len;


	//���캯��

	///TODO: ����Ϊ����Ĺ���
	explicit Linklist(Type* arr, int len)
	{}

	//Ĭ�Ϲ��캯�������Ա���Ϊ1
	explicit Linklist()
	{}

	//�Գ���Ϊ�����Ĺ��캯�������Ա���Ϊ����ֵ
	explicit Linklist(size_t arr_len)
	{}



	//��Ա����

	//��������Ԫ�ظ���
	size_t length() const
	{
		return Array_len;
	}

	//���������С
	size_t size() const
	{
		return Array_size;
	}

	//���������׵�ַ
	Type* begin() const
	{
		return Arr;
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

