#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <cstdint>
#include <stdexcept>

template<typename T> // чтобы разные типы данных можно было юзать, а не только float
class stack {
private:
    DynamicArray* array;
    std::int64_t max_size;
    std::int64_t current_size;
    
    static float toFloat(T value); // Т в float
    static T fromFloat(float value); // float в T
    
public:
    stack();
    stack(std::int64_t capacity);
    stack(stack& other);
    ~stack();

    void push(T x);
    T top();
    T pop();
    bool isEmpty();
};

#endif
