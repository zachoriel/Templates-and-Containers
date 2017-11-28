#include "intvector.h"
#include <cassert>
#include <cstring>

intVector::intVector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

intVector::~intVector()
{
	delete[] data;
}

int& intVector::at(size_t idx)
{
	assert(idx >= 0);
	assert(idx < size);

	return data[idx];
}

int& intVector::append(int val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}

	data[size] = val;
	++size;
}

bool intVector::grow(size_t minSize)
{
	assert(minSize <= 64000);      // So we don't get stuck in an infinite loop

	if (minSize <= capacity)
	{
		return true;
	}

	while (capacity < minSize)
	{
		capacity *= 2;
	}

	int* newData = new int[capacity];
	memcpy(newData, data, size);

	delete[] data;

	data = newData;
	return true;
}