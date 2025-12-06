#include "stack.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

template<typename T>
float stack<T>::toFloat(T value) {
    return static_cast<float>(value);
}

template<typename T>
T stack<T>::fromFloat(float value) {
    return static_cast<T>(value);
}

template<typename T>
stack<T>::stack() {
    this->max_size = 8;
    this->current_size = 0;
    this->array = new DynamicArray(this->max_size);
}

template<typename T>
stack<T>::stack(std::int64_t capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("Capacity must be positive");
    }
    this->max_size = capacity;
    this->current_size = 0;
    this->array = new DynamicArray(this->max_size);
}

template<typename T>
stack<T>::stack(stack& other) {
    this->max_size = other.max_size;
    this->current_size = other.current_size;
    this->array = new DynamicArray(*other.array);
}

template<typename T>
stack<T>::~stack() {
    if (this->array) {
        delete this->array;
    }
}

template<typename T>
void stack<T>::push(T x) {
    if (this->current_size >= this->max_size) {
        throw std::overflow_error("Stack overflow");
    }
    this->array->push_back(toFloat(x));
    this->current_size++;
}

template<typename T>
T stack<T>::top() {
    if (this->isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return fromFloat(this->array->back());
}

template<typename T>
T stack<T>::pop() {
    if (this->isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    T value = fromFloat(this->array->back());
    std::int64_t last_index = this->current_size - 1;
    this->array->delete_el(last_index);
    this->current_size--;
    return value;
}

template<typename T>
bool stack<T>::isEmpty() {
    return this->current_size == 0;
}

template class stack<float>;
template class stack<int>;
template class stack<double>;
