
#ifndef OOP_LAB2_NTREE_H
#define OOP_LAB2_NTREE_H

#include "NTreeNode.h"

template<class T> class NTree {
public:
    NTree();
    NTree(const NTree<T>& orig);
    void DeleteNode(char *path);
    void AddNode(const std::shared_ptr<T> &figure, char *path);
    template<class TT> friend std::ostream& operator<<(std::ostream& os, const NTree<TT>& tree);
    std::shared_ptr<NTreeNode<T>> FindNode(char* path);
    bool empty();
    virtual ~NTree();
private:
    std::shared_ptr<NTreeNode<T>> root;
};

template<class T>
NTree<T>::NTree() : root(nullptr) {
}

template<class T>
NTree<T>::NTree(const NTree<T>& orig) {
    root = orig.root;
}

template<class T>
void NTree<T>::DeleteNode(char *path) {
    std::shared_ptr<NTreeNode<T>> node;
    std::shared_ptr<NTreeNode<T>> parent;
    node = this->FindNode(path);
    if (node == this->root) {
        //        delete root;
        root = nullptr;
        return;
    }
    std::cout << node->GetFigure() << std::endl;

    int i = 0;
    while (path[i] != '\0') {
        i++;
    }
    path[i - 1] -= 1;
    if (path[i - 1] == '0') { path[i - 1] = 0; }
    parent = this->FindNode(path);

    if (parent->GetSibling() == node) {
        parent->SetSibling(node->GetSibling());
    }
    if (parent->GetChild() == node) {
        parent->SetChild(node->GetSibling());
    }
    node->SetSibling(nullptr);
    node = nullptr;
}

template<class T>
void NTree<T>::AddNode(const std::shared_ptr<T> &figure, char *path) {
    int i = 0, j;
    std::shared_ptr<NTreeNode<T>> node = root, node1 = root;
    if (path[0] == '0') {
        if (path[1] == '\0') {
            if (root == nullptr) {
                std::shared_ptr<NTreeNode<T>> node(new NTreeNode<T>(figure));
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
        std::shared_ptr<NTreeNode<T>> newNode(new NTreeNode<T>(figure));
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

template<class TT>
std::ostream& operator<<(std::ostream& os, const NTree<TT>& tree) {
    tree.root->print(0);
    return os;
}

template<class T>
std::shared_ptr<NTreeNode<T>> NTree<T>::FindNode(char* path) {
    int i = 0, j;
    std::shared_ptr<NTreeNode<T>> node = root;
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

template<class T>
bool NTree<T>::empty() {
    return root == nullptr;
}

template<class T>
NTree<T>::~NTree() {
    root = nullptr;
}

#endif //OOP_LAB2_NTREE_H
