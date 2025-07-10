#pragma once
#include <string>
#include <sstream>

#include "Node.h"

template <typename T>
class BinaryTree {
private:
    Node<T>* root;
    int node_count;

    void insert(Node<T>*& node, T value) {
        if (!node) {
            node = new Node<T>(value);
            node_count++;
        } else {
            if (value < node->value) {
                insert(node->left, value);
            }
            else
                insert(node->right, value);
        }
    }

    bool contains(Node<T> *node, T value) {
        if (!node) {
            return false;
        }
        if (node->value == value) {
            return true;
        }

        if (value < node->value)
            return contains(node->left, value);
        return contains(node->right, value);
    }

    void clear(Node<T>* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void remove(Node<T>*& node, T value) {
        if (!node) return;
        if (value < node->value)
            remove(node->left, value);
        else if (value > node->value)
            remove(node->right, value);
        else {
            if (!node->left && !node->right) {
                delete node;
                node = nullptr;
                node_count--;
                return;
            }
            if (!node->left) {
                Node<T>* temp = node->right;
                delete node;
                node = temp;
                node_count--;
                return;
            }
            if (!node->right) {
                Node<T>* temp = node->left;
                delete node;
                node = temp;
                node_count--;
                return;
            }

            Node<T>* min_in_right = BinaryTree::findMin(node->right);
            node->data = min_in_right->data;
            remove(node->right, min_in_right->data);
        }

    }

    void serialize(Node<T>* node, std::string& order, std::ostream& out) {
        if (!node) return;

        for (const char c : order) {
            if (c == 'K') out << node->data << "(";
            else if (c == 'L') serialize(node->left, order, out);
            else if (c == 'P') serialize(node->right, order, out);
            out << ")";
        }
    }


public:
    static Node<T>* findMin(Node<T>* node) {
        if (!node) return nullptr;
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    explicit BinaryTree() : root(nullptr), node_count(0) {};
    ~BinaryTree() {
        clear(root);
    }

    void insert(T value) {
        insert(root, value);
    }

    bool contains(T value) const {
        return contains(root, value);
    }

    void remove(T value) {
        remove(root, value);
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
        std::istringstream in(seria);
        T value;
        while (in >> value) {
            insert(root, value);
        }
    }


};
