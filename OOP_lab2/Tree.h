//
// Created by ayy on 1/19/17.
//

#ifndef OOP_LAB2_TREE_H
#define OOP_LAB2_TREE_H

#include <iostream>

#include "Hexagon.h"


class Tree {
public:
    Tree();
    Tree(const Tree& orig);

    bool Empty();

    void Insert(Hexagon& elem);
    void Delete();
    void PrintTree();

    Hexagon Pull(int pos);
    friend std::ostream& operator<<(std::ostream& os,const Tree& tree);

    ~Tree();

    typedef struct List {
        Tree* elem;
        List* next;

        List() {
            elem = nullptr;
            next = nullptr;
        }

        virtual ~List() {
            next = nullptr;
        }
    }List;
    Tree *root;
    Hexagon node;
    List* children;
    int children_size;
    bool empty;
};

#endif //OOP_LAB2_TREE_H
