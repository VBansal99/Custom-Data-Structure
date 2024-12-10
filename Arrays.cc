#include <iostream>
#include <stdio.h>
template <class X>
class Array
{
private:
    int capacity;
    int lastIndex;
    X *ptr;

public:
    Array();
    ~Array();
    void createArray(int);
    X &operator[](int);
    int getSize();
    bool isEmpty();
    void append(X);
    bool isFull();
    void del(X);
    X at(int);
    X front();
    X back();
    X addBack(X);
    X addFront(X);
    int begin();
    int end();

    // void append(X);
    // void insert(X);
    // X getItem();
    // void edit(int,X);
};
template <class X>
Array<X>::Array()
{
    ptr = NULL;
    capacity = 0;
    lastIndex = -1;
}

template <class X>
Array<X>::~Array()
{
    if (ptr != NULL)
    {
        delete[] ptr;
    }
}

template <class X>
void Array<X>::createArray(int cap)
{
    capacity = cap;
    lastIndex = -1;
    if (ptr != NULL)
    {
        delete[] ptr;
    }
    else
    {
        ptr = new X[cap];
    }
}
template <class X>
X &Array<X>::operator[](int index)
{
    if (index >= 0 && index <= lastIndex)
    {
        return ptr[index];
    }
    else
    {
        throw std::out_of_range("Array index out of bounds");
    }
}

template <class X>
bool Array<X>::isEmpty()
{
    if (lastIndex == -1)
        return true;
    else
        return false;
}
template <class X>
bool Array<X>::isFull()
{
    if (lastIndex == capacity - 1)
        return true;
    else
        return false;
}
template <class X>
int Array<X>::getSize()
{
    return capacity;
}

template <class X>
void Array<X>::append(X value)
{
    if (lastIndex < capacity - 1)
    {
        lastIndex++;
        ptr[lastIndex] = value;
    }
    else
    {
        std::cout << "Array is full";
    }
}
template <class X>
X Array<X>::at(int index)
{
    if (index < 0 || index > lastIndex)
        throw std::out_of_range("Array index out of bounds");
    else
        return ptr[index];
}
template <class X>
X Array<X>::front()
{
    if (lastIndex == 0 || capacity == 1)
        return ptr[lastIndex];
    else
        return ptr[0];
}
template <class X>
X Array<X>::back()
{
    return ptr[lastIndex];
}
template <class X>
X Array<X>::addBack(X value)
{
    ptr[lastIndex] = value;
    return ptr[lastIndex];
}
template <class X>
X Array<X>::addFront(X value)
{
    ptr[0] = value;
    return ptr[0];
}
template <class X>
int Array<X>::begin()
{
    return 0;
}
template <class X>
int Array<X>::end()
{
    return capacity;
}
int main()
{
    Array<int> arr;
    arr.createArray(5);
    if (arr.isEmpty())
        std::cout << "Array is Empty" << std::endl;
    else
        std::cout << "Array has some data" << std::endl;

    for (int i = 0; i < arr.getSize(); i++)
    {
        int value;
        std::cin >> value;
        arr.append(value);
    }

    for (int i = 0; i < arr.getSize(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    if (arr.isFull())
        std::cout << "Array is Full" << std::endl;
    else
        std::cout << "Array is empty" << std::endl;

    std::cout << arr.at(3) << std::endl;

    std::cout << arr.front() << std::endl;
    std::cout << arr.back() << std::endl;
    std::cout << arr.addBack(90) << std::endl;

    for (int i = 0; i < arr.getSize(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << arr.addFront(99) << std::endl;

    for (int i = 0; i < arr.getSize(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    for (int i = arr.begin()+1; i < arr.end(); i++)
    {
        std::cout << arr[i] << " ";
    }
    

}