#include "doubly_linked_list.hpp"

using IBusko::DoublyLinkedList;

template <typename T>
void DoublyLinkedList<T>::push_back(const T &value) noexcept {
    Node* new_elem = new Node(value);
	if (begin == nullptr) {
		begin = new_elem;
	} else if (end == nullptr) {
		end = new_elem;
		end->prev = begin;
		begin->next = end;
	} else {
		new_elem->prev = end;
		end->next = new_elem;
		end = elem;
		
	}
}

template <typename T>
void DoublyLinkedList<T>::print() const noexcept {
    Node* current = begin;
	while (current != nullptr) {
		std::cout << current->value << "\n";
		current = current->next;
	}
}

template <typename T>
bool DoublyLinkedList<T>::remove_first(const T &value) noexcept {
    Node* current = begin;
	while (current != nullptr) {
		if (current->value == value) {
			if(current == begin){
                current->next->prev = nullptr;
                begin = current->next;
            } else if(current == end){
                current->prev->next = nullptr;
                end = current->prev;
            } else{
				if(current->prev != nullptr) {
					current->prev->next = current->next;
				}
				if(current->next != nullptr) {
					current->next->prev = current->prev;
				}
            }
			сurrent = nullptr;
			return true;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
std::size_t DoublyLinkedList<T>::size() const noexcept {
    Node* current = begin;
	int size = 0;
    while (current != nullptr){
        size++;
		current = current->next;
    }
    return size;
}

template <typename T>
bool DoublyLinkedList<T>::has_item(const T &value) const noexcept {
    Node* current = begin;
    while (current != nullptr){
        if(current->value == value){
            return true;
        }
		current = current->next;
    }
    return false;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() noexcept {
	bool result;
	while (True) {
		result = this->remove_first(begin.value);
		if (not result) {
			break;
		}
	}
}