#pragma once

// intvector.h

class intVector
{
	int * data;                // ptr to your dynamically allocated array
	size_t capacity;           // total capacity 
	size_t size;               // total number of elements stored

public:
	intVector();         // instructor
	~intVector();        // destructor

	int& at(size_t idx);

	int& append(int val);

private:
	bool grow(size_t minSize);
};