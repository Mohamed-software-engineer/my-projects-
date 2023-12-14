#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <stdexcept> // To use handle exception
#include <string.h>

using namespace std;

template < typename T>
class DynamicArray
{
private:
	T* data;
	size_t size;
	size_t capacity;
public:
	DynamicArray();
	DynamicArray(size_t initialize);
	void giveInitialize(size_t initialize);
	void resize(size_t newSize);
	void insertAt(const T& value, size_t index);
	void insertFront(const T& value);
	void insertEnd(const T& value);
	void removeAtIndex(size_t index);
	void removeEnd();
	void removeFront();
	void removeAtValue(const T& value);
	bool search(const T& searchValue);
	size_t getSize() const;
	T& operator [](size_t index);
	// operator overloading to = operator
	DynamicArray& operator =(const DynamicArray <T> other)
	{
		if (this != &other)
		{
			delete[] data;
			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];
			for (size_t i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
		}
		return *this;
	}
	// Destructor
	~DynamicArray()
	{
		delete[] data;
	}
};
#endif // DYNAMICARRAY_H
