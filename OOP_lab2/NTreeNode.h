//
// Created by ayy on 2/18/17.
//

#ifndef OOP_LAB2_NTREENODE_H
#define OOP_LAB2_NTREENODE_H

#include "Hexagon.h"
class NTreeNode {
public:
    NTreeNode(const Hexagon& octagon);
    friend std::ostream& operator<<(std::ostream& os, const NTreeNode& obj);
    void print(int indent);
    NTreeNode* GetChild();
    NTreeNode* GetParent();
    NTreeNode* GetSibling();
    void SetChild(NTreeNode* child);
    void SetParent(NTreeNode* parent);
    void SetSibling(NTreeNode* sibling);
    void SetHexagon(Hexagon hexagon);
    Hexagon GetHexagon() const;
    virtual ~NTreeNode();

private:
    Hexagon hexagon;
    NTreeNode *parent;
    NTreeNode *child;
    NTreeNode *sibling;
};


#endif //OOP_LAB2_NTREENODE_H
