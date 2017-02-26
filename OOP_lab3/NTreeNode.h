//
// Created by ayy on 2/18/17.
//

#ifndef OOP_LAB2_NTREENODE_H
#define OOP_LAB2_NTREENODE_H

#include <memory>
#include "Hexagon.h"
class NTreeNode {
public:
    NTreeNode(const std::shared_ptr<Hexagon>& octagon);
    friend std::ostream& operator<<(std::ostream& os, const NTreeNode& obj);
    void print(int indent);

    std::shared_ptr<NTreeNode> GetChild();
    std::shared_ptr<NTreeNode> GetParent();
    std::shared_ptr<NTreeNode> GetSibling();

    void SetChild(std::shared_ptr<NTreeNode> child);
    void SetParent(std::shared_ptr<NTreeNode> parent);
    void SetSibling(std::shared_ptr<NTreeNode> sibling);
    void SetHexagon(Hexagon hexagon);

    Hexagon GetHexagon() const;

    virtual ~NTreeNode();

private:
    std::shared_ptr<Hexagon> hexagon;
    std::shared_ptr<NTreeNode> parent;
    std::shared_ptr<NTreeNode> child;
    std::shared_ptr<NTreeNode> sibling;
};


#endif //OOP_LAB2_NTREENODE_H
