#pragma once

template <typename T>
class Node {
public:
    T data;
    Node<T>* right;
    Node<T>* left;
    explicit Node<T>(T item) : data(item), right(nullptr), left(nullptr) {};
    ~Node() {
        delete left;
        delete right;
    }
};