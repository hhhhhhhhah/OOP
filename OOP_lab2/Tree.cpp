//
// Created by ayy on 1/19/17.
//
#include "Tree.h"

Tree::Tree() {
    root->children = nullptr;
    children_size = 0;
    empty = true;

}

Tree::Tree(const Tree& orig) {
    root->node = orig.node;
    root->children = orig.children;
    root->children_size = orig.children_size;
    root->empty = orig.empty;
}

bool Tree::Empty() {
    return ( empty && !children_size );
}


void Tree::Insert(Hexagon &elem) {
    if(empty) {
        node = elem;
        empty = false;
    }
    else {
        Tree* el = new Tree;
        el->node = elem;

        List* newElem = new List;
        newElem->elem = el;
        newElem->next = nullptr;

        newElem->next = this->children;
        this->children = newElem;
        children_size++;
    }
}

Hexagon Tree::Pull(int pos) {
    if(empty) {
        std::cout << "Tree is empty\n";
        return nullptr;
    }
    else {
        Hexagon res = this->node;
        if( children_size > 1) {
            this->node = this->children->elem->node;
            children_size--;

            List *toDel = this->children;
            this->children = this->children->next;
            delete (toDel);
        }
        else if( children_size == 0 ){
            this->empty = true;
        }
        else if( children_size == 1) {
            this->node = this->children->elem->node;
            delete(this->children);
            children_size--;
        }
        return res;
    }
}


void Tree::Delete() {
    while( !this->Empty()) {
        this->Pull(1);
    }
}

template <class T> Tree<T>::~Tree() {

}

std::ostream &operator<<(std::ostream &os, const Tree &tree) {
    if(empty) {
        std::cout << "The tree is empty" << std::endl;
        return os;
    }
    else {
        Hexagon temp = this->node;

    }
}

void Tree::PrintTree() {
    if(empty) {
        std::cout << "The tree is empty" << std::endl;
    } else {

    }
}

