#pragma once
#include <string>
#include <sstream>
#include "Node.h"

template <typename T>
class BinaryTree {
private:
    Node<T>* root;
    int node_count;

    void insert(Node<T>*& node, T data) {
        if (!node) {
            node = new Node<T>(data);
            node_count++;
        } else if (data < node->data) {
            insert(node->left, data);
        } else {
            insert(node->right, data);
        }
    }

    bool contains(Node<T>* node, T data) const {
        if (!node) return false;
        if (node->data == data) return true;
        return data < node->data ? contains(node->left, data) : contains(node->right, data);
    }

    void clear(Node<T>* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void remove(Node<T>*& node, T data) {
        if (!node) return;
        if (data < node->data)
            remove(node->left, data);
        else if (data > node->data)
            remove(node->right, data);
        else {
            if (!node->left && !node->right) {
                delete node;
                node = nullptr;
                node_count--;
            } else if (!node->left) {
                Node<T>* temp = node->right;
                delete node;
                node = temp;
                node_count--;
            } else if (!node->right) {
                Node<T>* temp = node->left;
                delete node;
                node = temp;
                node_count--;
            } else {
                Node<T>* minRight = findMin(node->right);
                node->data = minRight->data;
                remove(node->right, minRight->data);
            }
        }
    }

    void serialize(Node<T>* node, const std::string& order, std::ostream& out) const {
        if (!node) return;
        for (char c : order) {
            if (c == 'K') out << node->data << " ";
            else if (c == 'L') serialize(node->left, order, out);
            else if (c == 'P') serialize(node->right, order, out);
        }
    }

public:
    explicit BinaryTree() : root(nullptr), node_count(0) {}

    ~BinaryTree() {
        clear(root);
    }

    void insert(T data) {
        insert(root, data);
    }

    bool contains(T data) const {
        return contains(root, data);
    }

    void remove(T data) {
        remove(root, data);
    }

    std::string toString(const std::string& order) const {
        std::ostringstream out;
        serialize(root, order, out);
        return out.str();
    }

    int size() const {
        return node_count;
    }

    void fromString(const std::string& seria) {
        clear(root);
        root = nullptr;
        node_count = 0;
        std::istringstream in(seria);
        T data;
        while (in >> data) {
            insert(data);
        }
    }

    static Node<T>* findMin(Node<T>* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
};
