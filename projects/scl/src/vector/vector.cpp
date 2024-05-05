#include "vector.hpp"
#include <iostream>

using IBusko::Vector;

template <typename T>
Vector<T>::Vector() noexcept{
    arr = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() noexcept{
    delete[] arr;
}

template <typename T>
void Vector<T>::change_size() noexcept {
	capacity *= 2;
    T* arr_copy = new T[capacity];
    for(int i = 0; i < size_; i++){
        arr_copy[i] = arr[i];
    }
    delete[] arr;
    arr = arr_copy;
}

template <typename T>
void Vector<T>::push_back(const T& value) noexcept{
    if(size_ >= capacity){
        change_size();
    }
    arr[size_] = value;

    size_ += 1;
}

template <typename T>
bool Vector<T>::has_item(const T& value) const noexcept{
    for (int i = 0; i < size_; i++){
        if (arr[i] == value){
            return true;
        }
    }
    return false;
}

template <typename T>
bool Vector<T>::insert(const int position, const T& value){
    if(size_ >= capacity){
        change_size();
    }
    for (int i = size_; i > position; i--) {
		arr[i] = arr[i - 1];
	}
	arr[position] = value;
    return true;
}

template <typename T>
void Vector<T>::print() const noexcept{
    for(int i = 0; i < size_; i++){
        std::cout << arr[i] << "\n";
    }
}

template <typename T>
int Vector<T>::size() const noexcept{
    return size_;
}

template <typename T>
bool Vector<T>::remove_first(const T& value) noexcept{
    if (has_item(value)) {
		size_--;
		T* arr_copy = new T[size_];
		int index = 0;
		while (arr[index] != value) {
			arr_copy[index] = arr[index];
			index++;
		}
		for (int i = index; i < size_; i++) {
			arr_copy[i] = arr[i + 1];
		}
		arr = arr_copy;
		delete arr;
		return true;
	}
	return false;
}

