#include <cstdlib>
#include <iostream>
#include <string>
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"
#include "NTreeNode.h"
#include "NTree.h"

void PrintMenu();

int main(int argc, char** argv) {
    char path[32];
    std::shared_ptr<NTreeNode> node;
    NTree nTree;

    while (1) {
        PrintMenu();
        int number;
        std::cin >> number;

        switch (number) {
            case 1: {
                std::cout << "Enter path: ";
                std::cin >> path;
                std::cout << "Enter type of figure (1 - triangle, 2 - hexagon, 3 - octagon): ";
                int tof;
                std::cin >> tof;
                switch (tof){
                    case 1: {
                        std::cout << "Enter size(3 numbers): ";
                        int a,b,c;
                        std::cin >> a >> b >> c;
                        std::shared_ptr<Figure> figure(new Triangle(a, b, c));
                        nTree.AddNode(figure, path);
                        std::cout << "Triangle's area = " << figure->Square() << std::endl;
                        break;
                    }
                    case 2: {
                        std::cout << "Enter size: ";
                        int a;
                        std::cin >> a;
                        std::shared_ptr<Figure> figure(new Hexagon(a));
                        nTree.AddNode(figure, path);
                        std::cout << "Hexagon's area = " << figure->Square() << std::endl;
                        break;
                    }
                    case 3: {
                        std::cout << "Enter size: ";
                        int a;
                        std::cin >> a;
                        std::shared_ptr<Figure> figure(new Octagon(a));
                        nTree.AddNode(figure, path);
                        std::cout << "Octagon's area = " << figure->Square() << std::endl;
                        break;
                    }
                    default: {
                        std::cout << "Wrong number." << std::endl;
                        break;
                    }
                }
            }
            case 2: {
                std::cout << "Enter path: ";
                std::cin >> path;
                node = nTree.FindNode(path);
                if (node != nullptr) {
                    //Hexagon hexagon(node->GetFigure());
                    std::cout << node->GetChild() << std::endl;
                    std::cout << "Figure's area = " << node->GetChild()->GetFigure()->Square() << std::endl;
                    //std::cout << hexagon << std::endl;
                    //std::cout << "Hexagon's area = " << hexagon.Square() << std::endl;
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
    std::cout << "| 1 - Push Figure                  |" << std::endl;
    std::cout << "| 2 - Get Figure                   |" << std::endl;
    std::cout << "| 3 - Delete Figure                |" << std::endl;
    std::cout << "| 4 - Check if tree is empty       |" << std::endl;
    std::cout << "| 5 - Print tree                   |" << std::endl;
    std::cout << "| 6 - Quit                         |" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Please enter a number: ";
}
