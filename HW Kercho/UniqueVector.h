#pragma once
#include <functional>
#include <iostream>


template <typename T>
class UniqueVector
{
private:
	T* _elements;
	int _size = 0;
	int _capacity;
	void copy(const T* arr, int size);
	void setCapacity(int capacity);
	void resize();
	void destroy();
	bool repeat(const T& other);

public:
	const int  getCapacity()const;
	const int getSize()const;
	UniqueVector<T>& operator=(const UniqueVector<T>& other);
	UniqueVector();
	UniqueVector(int n);
	UniqueVector(const UniqueVector<T>& other);
	~UniqueVector();
	void addNewElem(const T& other);
	void addElemIndex(int index, const T& other);
	void removeElemByIndex(int index);
	void reverse();
	T& operator[](int index);
	const T& operator[](int index) const;
	bool operator !=(const UniqueVector<T>& other)const;
	friend std::ostream& operator<<(std::ostream& os, const UniqueVector<T>& object);
	template<typename U>
	UniqueVector<U> map(std::function<U(const T&)> mapper);
	UniqueVector<T> filter(std::function<bool(const T&)> predicate);

	template <typename R>
	R reduce(const R& init, std::function<R(const R&, const T&)> reducer);
	UniqueVector<T> partition(std::function<bool(const T&)>predicate);
};
