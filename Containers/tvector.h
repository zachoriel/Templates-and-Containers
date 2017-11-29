#pragma once

#include <cassert>

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

	bool grow(size_t minSize);

public:
	tVector();
	~tVector();

	T& at(size_t idx);
	T& append(T val);
	void pop();

	T* c_ptr() const;
	size_t getCapacity() const;
	size_t getSize() const;

	bool empty() const;

	T front() const;
	T back() const;

	T& operator[](size_t idx);
	T operator[](size_t idx) const;
};

template<typename T>
bool tVector<T>::grow(size_t minSize)
{
	assert(minSize <= 64000);

	if (minSize <= capacity)
	{
		return true;
	}
	
	while (capacity < minSize)
	{
		capacity *= 2;
	}

	T* newData = new T[capacity];
	memcpy(newData, data, sizeof(T) * size);

	delete[] data;

	data = newData;
	return true;
}

template<typename T>
T* tVector<T>::c_ptr() const
{
	return data;
}

template<typename T>
size_t tVector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
size_t tVector<T>::getSize() const
{
	return size;
}

template<typename T>
bool tVector<T>::empty() const
{
	return size > 0;
}

template<typename T>
T tVector<T>::front() const
{
	assert(size > 0);
	return data[0];
}

template<typename T>
T tVector<T>::back() const
{
	assert(size > 0);
	return data[size - 1];
}

template<typename T>
void tVector<T>::pop()
{
	assert(size > 0);
	size -= 1;
}

template<typename T>
T& tVector<T>::operator[](size_t idx)
{
	assert(idx < size);
	return data[idx];
}

template<typename T>
T tVector<T>::operator[](size_t idx) const
{
	assert(idx < size);
	return data[idx];
}

template<typename T>
tVector::tVector()
{
	capacity = 2;
	data = new T[capacity];
	size = 0;
}

template<typename T>
tVector::~tVector()
{
	delete[];
}

template<typename T>
inline T & tVector<T>::append(T val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1)
			assert(didGrow);
	}

	data[size] = val;
	++size;

	return data[size - 1];
}

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

public:
	tVector();
	~tVector();

	T& at(size_t idx);
	T& append(T val);
};

template<typename T>
tVector::tVector()
{
	capacity = 2;
	data = new T[capacity];
	size = 0;
}

template<typename T>
tVector::~tVector()
{
	delete[];
}