#pragma once

#include <algorithm>

template <typename T>
class FSimpleVector
{
public:
	FSimpleVector();
	FSimpleVector(int capacity);
	FSimpleVector(const FSimpleVector& value); // 복사 생성자
	virtual ~FSimpleVector();

	void PushBack(const T& value);
	void PopBack();
	int Size() { return CurrentSize; }
	int Capacity() { return CurrentCapacity; }
	
	void Resize(int newCapacity);
	void SortData();

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
inline FSimpleVector<T>::FSimpleVector(const FSimpleVector& value) : FSimpleVector(value.CurrentCapacity)
{
	CurrentSize = value.CurrentSize;
	for (int n = 0; n < CurrentSize; n++)
	{
		Data[n] = value.Data[n];
	}
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
		Resize(CurrentCapacity * 2);
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

template<typename T>
inline void FSimpleVector<T>::Resize(int newCapacity)
{
	if (newCapacity > CurrentCapacity)
	{
		CurrentCapacity = newCapacity;
		T* NewData = new T[CurrentCapacity];
		for (int n = 0; n < CurrentSize; n++)
		{
			NewData[n] = Data[n];
		}
		delete Data;
		Data = NewData;
	}
}

template<typename T>
inline void FSimpleVector<T>::SortData()
{
	std::sort(Data, Data + CurrentSize);
}
