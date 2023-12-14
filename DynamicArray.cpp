#include "DynamicArray.h"
#include "Book.h"
#include "BookList.h"
template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<char>;
template class DynamicArray<string>;
template class DynamicArray<bool>;
template class DynamicArray<size_t>;
template class DynamicArray<Book>;

template < typename  T>
//default constructor
DynamicArray<T>::DynamicArray() :capacity(0), size(0)
{
	data = new T[capacity];
}
template < typename T >
//parametrize constructor to initialize attribute
DynamicArray<T>::DynamicArray(size_t initialize) : capacity(initialize), size(0)
{
	data = new T[capacity];
}
template < typename T >
// Give initialize value to Dynamic Array
void DynamicArray<T>::giveInitialize(size_t initialize)
{
    capacity = initialize;
    size = 0;
    data = new T[capacity];
}
template < typename T >
//resize the capacity of array
void DynamicArray<T>::resize(size_t newSize)
{
    if (newSize <= 0) {
        throw invalid_argument("Invalid new size"); // handle if size invalid
    }
    T* newData = new T[newSize];
    // copy elements from the old array to the new one
    for (size_t i = 0; i < min(size, newSize); ++i)
    {
        newData[i] = data[i];
    }
    // Deallocate the old memory and update the pointer and size
    delete[] data;
    data = newData;
    capacity = newSize;
}
template < typename T >
// Insert element in specific space
void DynamicArray<T>::insertAt(const T& value, size_t index)
{
    if (size == capacity) // Double capacity of array if we have no space
    {
        resize(2 * capacity);
    }
    for (size_t i = size; i >= index; --i)
    {
        if (i == index) // set value in require index
        {
            data[index] = value;
            size++;
        }
        else
            data[i] = data[i - 1]; // shifting the elements
    }
}
template < typename T >
// Add element in array front
void DynamicArray<T>::insertFront(const T& value)
{
    if (size == capacity) // Double capacity of array if we have no space
    {
        resize(2 * capacity);
    }
    for (size_t i = size; i > 0; --i) // shifting the elements
    {
        data[i] = data[i - 1];
    }
    data[0] = value; // Add value in front
    size++;
}
template < typename T >
// Add element in array End
void DynamicArray<T>::insertEnd(const T& value)
{
    if (size == capacity)  // Double capacity of array if we have no space
    {
        resize(2 * capacity);
    }
    data[size++] = value; // Add value in end of Array
}
template < typename T >
// [] operator overloading
T& DynamicArray<T>::operator [](size_t index)
{
    if (index >= capacity)
    {

        throw out_of_range("Index out of range");
    }
    return data[index];
}

template < typename T>
// remove element from end of array
void DynamicArray<T>::removeEnd()
{
    if (size > 0)
    {
        size--;
    }
}
template < typename T >
// remove element from front of array
void DynamicArray<T>::removeFront()
{
    if (size > 0)
    {
        for (size_t i = 0; i < size - 1; ++i) // Shifting element
        {
            data[i] = data[i + 1];
        }
        size--;
    }
}
template < typename T >
// remove elements by index
void DynamicArray<T>::removeAtIndex(size_t index)
{
    if (size > 0)
    {
        // Shifting element start by index
        for (size_t i = index; i < size; ++i)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
}
template < typename T>
// remove elements by value
void DynamicArray<T>::removeAtValue(const T& value)
{
    bool check = false;
    size_t index = 0;
    if (size > 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (data[i] == value)
            {
                check = true;
                index = i;
            }
        }
        for (size_t i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
}
template < typename T>
// Search in array
bool DynamicArray<T>::search(const T& value)
{
    bool check = false;
    if (size > 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (data[i] == value)
            {
                check = true;
                return check;
            }
        }
    }
    return check;
}
template < typename T >
// return size of array
size_t DynamicArray<T>::getSize() const
{
    return size;
}
