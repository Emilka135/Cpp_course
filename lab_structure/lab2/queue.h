#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <cstdint>
#include <stdexcept>

template<typename T>
class queue {
private:
    stack<T>* input_stack; // стэк для добавления
    stack<T>* output_stack; // стэк для извлечения
    std::int64_t max_size;
    std::int64_t current_size;
    
    void moveInputToOutput(); // это чтобы переворачивать элементы: из input в output
    
public:
    queue();
    queue(std::int64_t capacity);
    queue(queue& other);
    ~queue();

    void enqueue(T x);
    T dequeue();
    bool isEmpty();
    std::int64_t size();
};

#endif
