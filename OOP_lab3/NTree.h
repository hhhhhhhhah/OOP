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
    void AddNode(const std::shared_ptr<Figure> &figure, char *path);
    friend std::ostream& operator<<(std::ostream& os, const NTree& tree);
    std::shared_ptr<NTreeNode> FindNode(char* path);
    bool empty();
    virtual ~NTree();
private:
    std::shared_ptr<NTreeNode> root;
};


#endif //OOP_LAB2_NTREE_H
