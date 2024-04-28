#include "vector.hpp"

using IBusko::Vector;

template <typename T>
Vector<T>::Vector() noexcept{
    arr = new T[this->capacity];
}

template <typename T>
Vector<T>::~Vector() noexcept{
    delete[] arr;
}

template <typename T>
void Vector<T>::change_size() noexcept {
	this->capacity *= 2;
    T* arr_copy = new T[this->capacity];
    for(std::size_t i = 0; i < this->get_size(); i++){
        arr_copy[i] = arr[i];
    }
    delete[] arr;
    arr = arr_copy;
}

template <typename T>
void Vector<T>::push_back(const T& value) noexcept{
    if(this->get_size() >= this->capacity){
        change_size();
    }
    arr[get_size()] = value;

    this->size += 1;
}

template <typename T>
bool Vector<T>::has_item(const T& value) const noexcept{
    for (size_t i = 0; i < this->get_size(); i++){
        if (arr[i] == value){
            return true;
        }
    }
    return false;
}

template <typename T>
bool Vector<T>::insert(const int position, const T& value){
    if(this->get_size() >= this->capacity){
        change_size();
    }
    for (size_t i = this->get_size(); i > position); i--) {
		arr[i] = arr[i - 1];
	}
	arr[position] = value;
    return true;
}

template <typename T>
void Vector<T>::print() const noexcept{
    for(std::size_t i = 0; i < this->get_size(); i++){
        std::cout << arr[i] << "\n";
    }
}

template <typename T>
std::size_t Vector<T>::get_size() const noexcept{
    return this->size;
}

template <typename T>
bool Vector<T>::remove_first(const T& value) noexcept{
    // need realize
}

