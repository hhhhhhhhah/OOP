#include "NTreeNode.h"
#include <iostream>

NTreeNode::NTreeNode(const Hexagon& hexagon):hexagon(hexagon) {
    this->child = nullptr;
    this->sibling = nullptr;
    this->parent = nullptr;
}

NTreeNode* NTreeNode::GetChild() {
    return this->child;
}
NTreeNode* NTreeNode::GetParent() {
    return this->parent;
}
NTreeNode* NTreeNode::GetSibling() {
    return this->sibling;
}

void NTreeNode::SetChild(NTreeNode* child) {
    this->child = child;
}
void NTreeNode::SetParent(NTreeNode* parent) {
    this->parent = parent;
}
void NTreeNode::SetSibling(NTreeNode* sibling) {
    this->sibling = sibling;
}
void NTreeNode::SetHexagon(Hexagon hexagon) {
    this->hexagon = hexagon;
}
Hexagon NTreeNode::GetHexagon() const {
    return this->hexagon;
}


NTreeNode::~NTreeNode() {

    delete sibling;
}

void NTreeNode::print(int indent) {
    for (int i = 0; i < indent; ++i) {
        std::cout << "-";
    }
    std::cout << this->hexagon << std::endl;
    if (this->GetChild() != nullptr)
        this->GetChild()->print(indent + 1);
    if (this->GetSibling() != nullptr)
        this->GetSibling()->print(indent);
}

std::ostream& operator<<(std::ostream& os, const NTreeNode& obj) {
    os << obj.hexagon << std::endl;
    return os;
}