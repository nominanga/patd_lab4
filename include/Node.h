#pragma once

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T data) : data(data), left(nullptr), right(nullptr) {}
};
