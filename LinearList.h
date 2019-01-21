#pragma once
template<class Type> 

class Array
{
private:
	size_t Array_len;
public:
	Type *Arr;
	explicit Array()
	{
		Arr = new Type;
		Array_len = 1;
	}
	explicit Array(Type arr[])
	{
		//Array_len = sizeof(arr) / sizeof(arr[0]);
		///TODO: 将数组大小赋给Array_len
		Arr = new Type[Array_len];
		for (size_t i = 0; i < Array_len; i++)
			Arr[i] = arr[i];
	}
	explicit Array(size_t arr_len)
	{
		Arr = new Type[arr_len];
		Array_len = arr_len;
	}

	size_t length()
	{
		return Array_len;
	}
	Type* begin()
	{
		return Arr;
	}
	Type* end()
	{
		return Arr + Array_len - 1;
	}

};