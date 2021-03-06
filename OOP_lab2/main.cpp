#include <cstdlib>
#include <iostream>
#include <string>
#include "Hexagon.h"
#include "NTreeNode.h"
#include "NTree.h"

void PrintMenu();

int main(int argc, char** argv) {
    char path[32];
    NTreeNode *node;
    NTree nTree;

    while (1) {
        PrintMenu();
        int number;
        std::cin >> number;

        switch (number) {
            case 1: {
                std::cout << "Enter path: ";
                std::cin >> path;
                std::cout << "Enter size: ";
                int a;
                std::cin >> a;
                Hexagon hexagon(a);
                nTree.AddNode(hexagon, path);
                std::cout << "Area of a hexagon = " << hexagon.Square() << std::endl;
                break;
            }
            case 2: {
                std::cout << "Enter path: ";
                std::cin >> path;
                node = nTree.FindNode(path);
                if (node != nullptr) {
                    Hexagon hexagon(node->GetHexagon());
                    std::cout << hexagon << std::endl;
                    std::cout << "Area of a hexagon = " << hexagon.Square() << std::endl;
                } else {
                    std::cout << "Wrong path." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Enter path: ";
                std::cin >> path;
                nTree.DeleteNode(path);
                break;
            }
            case 4: {
                if (nTree.empty()) std::cout << "Tree is empty.";
                else std::cout << "Tree is not empty.";
                break;
            }
            case 5: {
                if (nTree.empty()) std::cout << "Tree is empty";
                else std::cout << nTree << std::endl;
                break;
            }
            case 6: { return 0; }

            default: {
                std::cout << "Wrong number. Enter a number from 1 to 6." << std::endl;
                break;
            }
        }
    }
}

void PrintMenu() {
    std::cout << "----------------MENU----------------" << std::endl;
    std::cout << "| 1 - Push hexagon                 |" << std::endl;
    std::cout << "| 2 - Get hexagon                  |" << std::endl;
    std::cout << "| 3 - Delete hexagon               |" << std::endl;
    std::cout << "| 4 - Check if tree is empty       |" << std::endl;
    std::cout << "| 5 - Print tree                   |" << std::endl;
    std::cout << "| 6 - Quit                         |" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Please enter a number: ";
}
