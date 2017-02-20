//
// Created by ayy on 2/18/17.
//

#ifndef OOP_LAB2_NTREE_H
#define OOP_LAB2_NTREE_H

#include "NTreeNode.h"
#include "Hexagon.h"

class NTree {
public:
    NTree();
    NTree(const NTree& orig);
    void DeleteNode(char *path);
    void AddNode(Hexagon hexagon, char *path);
    friend std::ostream& operator<<(std::ostream& os, const NTree& tree);
    NTreeNode* FindNode(char* path);
    bool empty();
    virtual ~NTree();
private:
    NTreeNode *root;
};


#endif //OOP_LAB2_NTREE_H
