
#include <iostream>
#include "SimpleVector.h"

int main()
{
	FSimpleVector<int> IntSimpleVector;
	FSimpleVector<float> FloatSimpleVector(5);

	// Push
	for (int n = 1; n <= 12; n++)
	{
		IntSimpleVector.PushBack(n);
		FloatSimpleVector.PushBack(1.0f / n);
		std::cout << "IntSimpleVector"
				  << ", Size():" << IntSimpleVector.Size()
				  << ", Capacity(): " << IntSimpleVector.Capacity() << std::endl;
	}

	// Iteration
	for (int n = 0; n < IntSimpleVector.Size(); n++)
	{
		std::cout << "IntSimpleVector[" << n << "] = " << IntSimpleVector.Get(n) << std::endl;
	}
	for (int n = 0; n < FloatSimpleVector.Size(); n++)
	{
		std::cout << "FloatSimpleVector[" << n << "] = " << FloatSimpleVector.Get(n) << std::endl;
	}

	// Pop
	for (int n = 0; n < 5; n++)
	{
		IntSimpleVector.PopBack();
		FloatSimpleVector.PopBack();
	}

	// Iteration
	std::cout << "After PopBack() * 5" << std::endl;
	for (int n = 0; n < IntSimpleVector.Size(); n++)
	{
		std::cout << "IntSimpleVector[" << n << "] = " << IntSimpleVector.Get(n) << std::endl;
	}
	for (int n = 0; n < FloatSimpleVector.Size(); n++)
	{
		std::cout << "FloatSimpleVector[" << n << "] = " << FloatSimpleVector.Get(n) << std::endl;
	}
	return 0;
}