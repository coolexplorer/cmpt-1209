#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
public:
    Stack();
    bool empty() const;
    T peek() const;
    void push(T value);
    T pop();
    int getSize() const;

private:
    T elements[100];
    int size;
};

template<typename T>
Stack<T>::Stack() {
    size = 0;
}

template<typename T>
bool Stack<T>::empty() const {
    return size == 0;
}

template<typename T>
T Stack<T>::peek() const {
    if (!empty()) {
        return elements[size - 1];
    } else {
        return (T)0;
    }
}

template<typename T>
void Stack<T>::push(T value) {
    if (size < 100) {
        elements[size++] = value;
    }
}

template<typename T>
T Stack<T>::pop() {
    if (size > 0) {
        int value = elements[size - 1];
        size--;
        return value;
    } else {
        return (T)0;
    }
}

template<typename T>
int Stack<T>::getSize() const {
    return size;
}
#endif

