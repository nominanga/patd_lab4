#include <iostream>
#include "Tree.h"

void treeMenu() {
    std::cout << "\nBinary Tree Menu:" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Remove" << std::endl;
    std::cout << "3. Contains" << std::endl;
    std::cout << "4. Size" << std::endl;
    std::cout << "5. Serialize (KLP)" << std::endl;
    std::cout << "6. Serialize (LKP)" << std::endl;
    std::cout << "7. Serialize (LPK)" << std::endl;
    std::cout << "8. Clear (reset tree)" << std::endl;
}

void treeRun() {
    BinaryTree<int> tree;
    treeMenu();
    int choice;

    while (std::cin >> choice && choice != 0) {
        int value;
        switch (choice) {
            case 1:
                std::cout << "Enter integer to insert: ";
                std::cin >> value;
                tree.insert(value);
                break;
            case 2:
                std::cout << "Enter integer to remove: ";
                std::cin >> value;
                tree.remove(value);
                break;
            case 3:
                std::cout << "Enter integer to search: ";
                std::cin >> value;
                std::cout << (tree.contains(value) ? "Found\n" : "Not found\n");
                break;
            case 4:
                std::cout << "Tree size: " << tree.size() << std::endl;
                break;
            case 5:
                std::cout << "Preorder (KLP): " << tree.toString("KLP") << std::endl;
                break;
            case 6:
                std::cout << "Inorder (LKP): " << tree.toString("LKP") << std::endl;
                break;
            case 7:
                std::cout << "Postorder (LPK): " << tree.toString("LPK") << std::endl;
                break;
            case 8:
                std::cout << "Clearing tree..." << std::endl;
                tree = BinaryTree<int>(); // Reset tree
                break;
            default:
                std::cout << "Invalid choice\n";
        }
        treeMenu();
    }
}


int main() {


    treeRun();

    return 0;
}
