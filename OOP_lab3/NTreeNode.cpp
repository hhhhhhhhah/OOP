#include "NTreeNode.h"
#include <iostream>

NTreeNode::NTreeNode(const std::shared_ptr<Figure>& figure) {
    this->figure = figure;
    this->child = nullptr;
    this->sibling = nullptr;
    this->parent = nullptr;
}

std::shared_ptr<NTreeNode> NTreeNode::GetChild() {
    return this->child;
}
std::shared_ptr<NTreeNode> NTreeNode::GetParent() {
    return this->parent;
}
std::shared_ptr<NTreeNode> NTreeNode::GetSibling() {
    return this->sibling;
}

void NTreeNode::SetChild(std::shared_ptr<NTreeNode> child) {
    this->child = child;
}
void NTreeNode::SetParent(std::shared_ptr<NTreeNode> parent) {
    this->parent = parent;
}
void NTreeNode::SetSibling(std::shared_ptr<NTreeNode> sibling) {
    this->sibling = sibling;
}
void NTreeNode::SetFigure(std::shared_ptr<Figure> figure) {
    this->figure = figure;
}
std::shared_ptr<Figure> NTreeNode::GetFigure() const {
    return figure;
}


NTreeNode::~NTreeNode() {
    sibling = nullptr;
}

void NTreeNode::print(int indent) {
    for (int i = 0; i < indent; ++i) {
        std::cout << "-";
    }
    std::cout << this->figure << std::endl;
    if (this->GetChild() != nullptr)
        this->GetChild()->print(indent + 1);
    if (this->GetSibling() != nullptr)
        this->GetSibling()->print(indent);
}

std::ostream& operator<<(std::ostream& os, const NTreeNode& obj) {
    os << obj.figure << std::endl;
    return os;
}