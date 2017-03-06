//
// Created by ayy on 2/18/17.
//

#include "NTree.h"

NTree::NTree() : root(nullptr) {
}

NTree::NTree(const NTree& orig) {
    root = orig.root;
}

void NTree::DeleteNode(char *path) {
    std::shared_ptr<NTreeNode> node;
    std::shared_ptr<NTreeNode> parent;
    node = this->FindNode(path);
    if (node == this->root) {
//        delete root;
        root = nullptr;
        return;
    }
    std::cout<<node->GetFigure()<<std::endl;

        int i = 0;
        while (path[i] != '\0') {
        i++;}
        path[i-1]-=1;
         if (path[i-1] == '0') {path[i-1] = 0;}
        parent = this->FindNode(path);

    if (parent->GetSibling() == node) {
    parent->SetSibling(node->GetSibling());}
    if (parent->GetChild() == node) {
    parent->SetChild(node->GetSibling());}
    node->SetSibling(nullptr);
    node = nullptr;
}

void NTree::AddNode(const std::shared_ptr<Figure> &figure, char *path) {
    int i = 0, j;
    std::shared_ptr<NTreeNode> node = root, node1 = root;
    if (path[0] == '0') {
        if (path[1] == '\0') {
            if (root == nullptr) {
                std::shared_ptr<NTreeNode> node(new NTreeNode(figure));
                root = node;
            }
            else {
                root->SetFigure(figure);
            }
        }
        else {
            std::cout << "Wrong Path" << std::endl;
        }
        return;
    }
    while (path[i] != '\0') {
        if (node != nullptr) {
            node1 = node;
            node = node->GetChild();
        }
        else {
            std::cout << "Wrong path" << std::endl;
            return;
        }
        j = path[i] - '0';
        if (1 <= j && j <= 9) {
            while (j > 1) {
                if (node != nullptr) {
                    node1 = node;
                    node = node->GetSibling();
                    j--;
                }
                else {
                    std::cout << "Wrong path" << std::endl;
                    return;
                }
            }

        }
        else {
            std::cout << "Wrong path" << std::endl;
            return;
        }
        ++i;
    }
    if (node != nullptr) {
        node->SetFigure(figure);
    }
    else {
        std::shared_ptr<NTreeNode> newNode(new NTreeNode(figure));
        node = newNode;
        if (path[i - 1] == '1') {
            node1->SetChild(node);
            node->SetParent(node1);
        }
        else {
            node1->SetSibling(node);
            node->SetParent(node1->GetParent());
        }
    }
}

std::ostream& operator<<(std::ostream& os, const NTree& tree) {
    tree.root->print(0);
    return os;
}

std::shared_ptr<NTreeNode> NTree::FindNode(char* path) {
    int i = 0, j;
    std::shared_ptr<NTreeNode> node = root;
    if (path[0] == '0') {
        return root;
    }
    while (path[i] != '\0') {
        if (node != nullptr) {
            node = node->GetChild();
        }
        else {
            std::cout << "Wrong path" << std::endl;
            break;
        }

        j = path[i] - '0';
        if (1 <= j && j <= 9) {
            while (j > 1) {
                node = node->GetSibling();
                if (node != nullptr) {
                    j--;
                }
                else {
                    std::cout << "Wrong path" << std::endl;
                    break;
                }
            }
        }
        else {
            std::cout << "Wrong path" << std::endl;
            node = nullptr;
            break;
        }
            ++i;
    }
    return node;
}

bool NTree::empty() {
    return root == nullptr;
}

NTree::~NTree() {
    root = nullptr;
}