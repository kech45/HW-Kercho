#include <iostream>
#include <functional>
#include "UniqueVector.h"
#include <cstring>


//zad1 UniqueVector

template <typename T>
void UniqueVector<T>::copy(const T* arr, int size)
{
	_size = size;
	_elements = new T[_size];
	for (int i = 0; i < _size; i++)
	{
		_elements[i] = arr[i];
	}
}

template <typename T>
bool UniqueVector<T>::operator!=(const UniqueVector<T>& other) const
{
	if (this->getSize() != other.getSize()) {
		return true;
	}
	for (size_t i = 0; i < this->getSize(); i++)
	{
		if (this->_elements[i] != other._elements[i]) {
			return true;
		}
	}
	return false;
}

template <typename T>
void UniqueVector<T>::setCapacity(int capacity)
{
	_capacity = capacity;
}

template <typename T>
void UniqueVector<T>::resize() {
	this->_capacity *= 2;
	T* newVector = new T[_capacity];
	for (int i = 0; i < _size; i++)
	{
		newVector[i] = this->_elements[i];
	}
	delete[]this->_elements;
	this->_elements = newVector;
}

template <typename T>
void UniqueVector<T>::destroy() {
	if (this->_elements != nullptr) 
	{ 
		delete[] this->_elements;
	}
	this->_elements = nullptr;
}

template <typename T>
bool UniqueVector<T>::repeat(const T& other) {
	for (size_t i = 0; i < _size; i++)
	{
		if (this->_elements[i] == other)
		{
			return true;
		}
	}
	return false;
}

template <typename T>
const int UniqueVector<T>::getCapacity()const { return _capacity; }

template <typename T>
const int UniqueVector<T>::getSize()const { return _size; }

template <typename T>
UniqueVector<T>& UniqueVector<T>::operator=(const UniqueVector<T>& other)
{
	if (this != &other) {
		if (this != nullptr) {
			if (this->_elements != nullptr) 
			{ 
				delete[]this->_elements; 
			}
			copy(other._elements, other._size);
		}
	}
	return *this;
}

template <typename T>
UniqueVector<T>::UniqueVector() {
	_capacity = 20;
	_elements = nullptr;
}

template <typename T>
UniqueVector<T>::UniqueVector(int n) {
	setCapacity(n);
}

template <typename T>
UniqueVector<T>::UniqueVector(const UniqueVector<T>& other) {
	copy(other._elements, other._size);
}

template <typename T>
UniqueVector<T>::~UniqueVector() {
	destroy();
}

template <typename T>
void UniqueVector<T>::addNewElem(const T& other) {
	if (this->_size == _capacity - 1)
	{
		resize();
	}
	if (repeat(other))
	{
		throw "The element repeats!";
	}
	this->_elements[_size] = other;
	_size++;
}

template <typename T>
void UniqueVector<T>::addElemIndex(int index, const T& other)
{
	if (this->_size == _capacity - 1) {
		resize();
	}
	if (!repeat)
	{
		T* newElements = new T[this->_capacity];

		for (int i = 0; i < index; i++)
		{
			newElements[i] = this->_elements[i];
		}
		newElements[index] = other;

		for (size_t i = 0; i < this->_size - index; i++)
		{
			newElements[index + i + 1] = this->_elements[index + i];
		}
		delete[]this->_elements;
		_elements = newElements;
		this->_size++;
	}
	else {
		std::cout << "Repeating element";
	}

}

template <typename T>
void UniqueVector<T>::removeElemByIndex(int index)
{
	T* newElements = new T[this->getCapacity()];
	int count = 0;
	for (size_t i = 0; i < this->_size; i++)
	{
		if (i != index)
		{
			newElements[count] = this->_elements[i];
			count++;
		}
	}
	_elements = newElements;
	_size--;
}

template <typename T>
void UniqueVector<T>::reverse() {
	T temp;
	for (size_t i = 0; i < _size / 2; i++)
	{
		temp = this->_elements[i];
		this->_elements[i] = this->_elements[_size - i - 1];
		this->_elements[_size - i - 1] = temp;
	}

}

template <typename T>
T& UniqueVector<T>::operator[](int index) {

	return this->_elements[index];
}

template <typename T>
const T& UniqueVector<T>:: operator[](int index) const {
	return _elements[index];
}

template <typename T>
std::ostream& operator <<(std::ostream& os, const UniqueVector<T>& other)
{
	for (size_t i = 0; i < other.getSize(); i++)
	{
		os << other[i] << " ";
	}
	os << std::endl;
	return os;
}

template <typename T>
template<typename U>
UniqueVector<U> UniqueVector<T>::map(std::function<U(const T&)> mapper)
{
	UniqueVector<U> result;

	for (std::size_t i = 0; i < this->_size; ++i)
	{
		result.addNewElem(mapper(this->_elements[i]));
	}

	return result;
}

template <typename T>
UniqueVector<T> UniqueVector<T>::filter(std::function<bool(const T&)> predicate)
{
	UniqueVector<T> result;

	for (size_t i = 0; i < this->_size; i++)
	{
		if (predicate(_elements[i]))
		{
			result.addElement(_elements[i]);
		}
	}
	return result;
}

template <typename T>
template <typename R>
R UniqueVector<T>::reduce(const R& init, std::function<R(const R&, const T&)> reducer)
{
	R result = init;

	for (std::size_t i = 0; i < this->_size; ++i)
	{
		result = reducer(result, this->_elements[i]);
	}

	return result;
}

template <typename T>
UniqueVector<T> UniqueVector<T>::partition(std::function<bool(const T&)>predicate)
{
	int beginPos = 0;
	int endPos = this->_size;
	UniqueVector<T> result;
	for (size_t i = 0; i < this->_size; i++)
	{
		if (predicate(this->_elements[i])) {
			result.addElemIndex(beginPos, this->_elements[i]);
			beginPos++;
		}
		else {
			result.addElemIndex(endPos, this->_elements[i]);
			endPos--;
		}
	}
	return result;
}

