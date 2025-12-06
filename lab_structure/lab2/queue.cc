#include "queue.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

template<typename T> 
void queue<T>::moveInputToOutput() {
    while (!this->input_stack->isEmpty()) {
        this->output_stack->push(this->input_stack->pop());
    }
}

template<typename T>
queue<T>::queue() {
    this->max_size = 8;
    this->current_size = 0;
    this->input_stack = new stack<T>(this->max_size);
    this->output_stack = new stack<T>(this->max_size);
}

template<typename T>
queue<T>::queue(std::int64_t capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("Capacity must be positive");
    }
    this->max_size = capacity;
    this->current_size = 0;
    this->input_stack = new stack<T>(this->max_size);
    this->output_stack = new stack<T>(this->max_size);
}

template<typename T>
queue<T>::queue(queue& other) {
    this->max_size = other.max_size;
    this->current_size = other.current_size;
    this->input_stack = new stack<T>(*other.input_stack);
    this->output_stack = new stack<T>(*other.output_stack);
}

template<typename T>
queue<T>::~queue() {
    if (this->input_stack) {
        delete this->input_stack;
    }
    if (this->output_stack) {
        delete this->output_stack;
    }
}

template<typename T>
void queue<T>::enqueue(T x) {
    if (this->current_size >= this->max_size) {
        throw std::overflow_error("Queue overflow");
    }
    this->input_stack->push(x);
    this->current_size++;
}

template<typename T>
T queue<T>::dequeue() {
    if (this->isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    
    // если output пуст, то перемещаем элементы из input
    if (this->output_stack->isEmpty()) {
        this->moveInputToOutput();
    }
    
    this->current_size--;
    return this->output_stack->pop();
}

template<typename T>
bool queue<T>::isEmpty() {
    return this->current_size == 0;
}

template<typename T>
std::int64_t queue<T>::size() {
    return this->current_size;
}


template class queue<float>;
template class queue<int>;
template class queue<double>;
