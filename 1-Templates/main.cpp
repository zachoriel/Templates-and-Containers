#include <iostream>
#include <string>

class Person
{
public:
	std::string name;
	int age;
	int height;
};

int add(int a, int b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

template<typename T>
T sub(T a, T b)
{
	return a - b;
}

template<typename T>
void print(T value)
{
	std::cout << value;
}

template<>
void print(Person value)
{
	std::cout << value.name << std::endl;
	std::cout << value.age << std::endl;
	std::cout << value.height << std::endl;
}

template<typename T>
T min(T a, T b)
{
	if (a < b)
	{
		return a;
	}

	return b;
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
	{
		return a;
	}

	return b;
}

template<typename T>
T clamp(T value, T lower, T upper)
{
	if (value < lower)
	{
		return lower;
	}
	else if (value > upper)
	{
		return upper;
	}
	else
	{
		return value;
	}
}

template<typename T>
T swap(T valueOne, T valueTwo)
{

}

int main()
{
	Person theKob;
	theKob.name = "Kobington";
	theKob.age = 19;
	theKob.height = 170.18f;

	print(theKob);

	int age = 22;
	float weight = 105.7f;

	print(age);
	std::cout << std::endl;
	print(weight);

	int smallest = min(5, 7);
	int smallestFlt = min<int>(5, 7.5f);

	int biggest = max(5, 7);

	int squished = clamp(2, 5, 7);   // clamp 2 between 5 & 7
	//float somethingElse = clamp(2.1f, 0.0, 1.0f);    clamp 2.1 between 0.0 & 1.0

	int v1 = add(5, 2);
	float v2 = add(2.1f, 3.2f);

	int s1 = sub(1, 1);
	float s2 = sub(2.5f, 1.1f);
	int s3 = sub<int>(1, 2.0f);

	return 0;
}