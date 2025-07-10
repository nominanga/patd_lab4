#include <iostream>
#include <cassert>
#include "Tree.h"

void TestBinaryTree() {
    BinaryTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    assert(tree.size() == 5);
    assert(tree.contains(10));
    assert(tree.contains(5));
    assert(tree.contains(15));
    assert(tree.contains(3));
    assert(tree.contains(7));
    assert(!tree.contains(100));

    tree.remove(3);
    assert(!tree.contains(3));
    assert(tree.size() == 4);

    tree.remove(5);
    assert(!tree.contains(5));
    assert(tree.size() == 3);

    tree.remove(10);
    assert(!tree.contains(10));
    assert(tree.size() == 2);

    assert(tree.contains(7));
    assert(tree.contains(15));

    tree.remove(7);
    tree.remove(15);
    assert(tree.size() == 0);

    tree.insert(20);
    tree.insert(10);
    tree.insert(30);

    std::string preorder = tree.toString("KLP");
    std::string inorder  = tree.toString("LKP");
    std::string postorder= tree.toString("LPK");

    std::cout << "Preorder:  " << preorder << std::endl;
    std::cout << "Inorder:   " << inorder << std::endl;
    std::cout << "Postorder: " << postorder << std::endl;

    assert(preorder.find("20") != std::string::npos);
    assert(inorder.find("10") != std::string::npos);
    assert(postorder.find("30") != std::string::npos);

    std::cout << "BinaryTree passed all tests" << std::endl;
}

int main() {
    TestBinaryTree();
    return 0;
}
