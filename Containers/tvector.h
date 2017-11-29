#pragma once

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