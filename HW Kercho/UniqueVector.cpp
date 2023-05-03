#include <iostream>
#include <functional>
#include "UniqueVector.h"

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
void UniqueVector<T>::setCapacity(int capacity)
	{
		_capacity = capacity;
	}

template <typename T>
void UniqueVector<T>::resize() {
		this->_size *= 2;
		UniqueVector* newVector = new UniqueVector[_size];
		for (int i = 0; i < _size; i++)
		{
			newVector->_elements[i] = this->_elements[i];
		}
		delete[]this->_elements;
		this = newVector;
	}

template <typename T>
void UniqueVector<T>::destroy() {
		delete[]this->_elements;
		this->_elements = nullptr;
	}

template <typename T>
bool UniqueVector<T>::repeat(const T& other) {
		for (size_t i = 0; i < _size; i++)
		{
			if (this->_elements[i] = other)
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
UniqueVector<T>& UniqueVector<T>::operator=(const UniqueVector& other)
	{
		if (this != other) {
			this->destroy();
			copy(other._elements, other._size);
		}
		return *this;
	}

template <typename T>
UniqueVector<T>::UniqueVector() {
		_elements = new T[1];
		_elements[0] = '\0';
		_size = 0;
		_capacity = 0;
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
		if (repeat) 
		{
			throw 99;
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
		T* newElements = new T[_capacity];

		for (size_t i = 0; i < index; i++)
		{
			newElements[i] = this->_elements[i];
		}
		for (size_t i = 0; i < this->_size-index; i++)
		{
			newElements[index] = this->_elements[index + 1 + i];
		}
		delete[]this->_elements;
		_elements = newElements;
		_size--;
	}

template <typename T>
void UniqueVector<T>::reverse() {
		T temp;
		for (size_t i = 0; i < _size/2; i++)
		{
			temp = this->_elements[i];
			this->_elements[i] = this->_elements[_size - i -1];
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
std::ostream& operator<<(std::ostream os, const UniqueVector<T>& other)
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


