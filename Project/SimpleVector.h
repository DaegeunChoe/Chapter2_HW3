#pragma once

template <typename T>
class FSimpleVector
{
public:
	FSimpleVector();
	FSimpleVector(int capacity);
	virtual ~FSimpleVector();

	void PushBack(const T& value);
	void PopBack();
	int Size() { return CurrentSize; }
	int Capacity() { return CurrentCapacity; }

	T& Get(int index) { return Data[index]; }

protected:
	T* Data;
	int CurrentSize;
	int CurrentCapacity;
};

template<typename T>
inline FSimpleVector<T>::FSimpleVector() : FSimpleVector(10)
{
}

template<typename T>
inline FSimpleVector<T>::FSimpleVector(int capacity)
{
	CurrentCapacity = capacity;
	CurrentSize = 0;
	Data = new T[CurrentCapacity];
}

template<typename T>
inline FSimpleVector<T>::~FSimpleVector()
{
	delete Data;
}

template<typename T>
inline void FSimpleVector<T>::PushBack(const T& value)
{
	if (CurrentSize >= CurrentCapacity)
	{
		return;
	}
	Data[CurrentSize] = value;
	CurrentSize++;
}

template<typename T>
inline void FSimpleVector<T>::PopBack()
{
	if (CurrentSize <= 0)
	{
		return;
	}
	// Data[CurrentSize] = 0;
	CurrentSize--;
}
