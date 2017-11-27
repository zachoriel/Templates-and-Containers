#pragma once

#include <cstdlib>

template<bool exp>
void assert(bool cond)
{
	if (cond == exp)
	{
		return;
	}

	abort();  // Should give error message
}

template<typename T>
void assertEqual(T a, T b)
{
	if (a == b)
	{
		return;
	}

	abort(); // Should give error message
}

template <typename T>
void assertNotEqual(T a, T b)
{
	if (a != b)
	{
		return;
	}

	abort();
}