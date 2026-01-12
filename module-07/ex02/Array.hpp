#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
	T *_data;
	unsigned int _size;

public:
	Array() : _data(NULL), _size(0) {}

	Array(unsigned int n) : _data(new T[n]()), _size(n) {}

	Array(Array const &src) : _data(NULL), _size(0)
	{
		*this = src;
	}

	~Array()
	{
		delete[] _data;
	}

	Array &operator=(Array const &rhs)
	{
		if (this != &rhs)
		{
			delete[] _data;
			_size = rhs._size;
			_data = new T[_size]();
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = rhs._data[i];
		}
		return *this;
	}

	T &operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::exception();
		return _data[index];
	}

	T const &operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::exception();
		return _data[index];
	}

	unsigned int size() const
	{
		return _size;
	}
};

#endif
