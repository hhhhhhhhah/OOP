
#ifndef OOP_LAB2_NTREENODE_H
#define OOP_LAB2_NTREENODE_H

#include <memory>

template <class T> class NTreeNode : public std::enable_shared_from_this<NTreeNode<T>> {
public:
    NTreeNode(const std::shared_ptr<T>& figure);
    template<class TT> friend std::ostream& operator<<(std::ostream& os, const NTreeNode<TT>& obj);
    void print(int indent);

    std::shared_ptr<NTreeNode<T>> GetChild();
    std::shared_ptr<NTreeNode<T>> GetParent();
    std::shared_ptr<NTreeNode<T>> GetSibling();

    void SetChild(std::shared_ptr<NTreeNode<T>> child);
    void SetParent(std::shared_ptr<NTreeNode<T>> parent);
    void SetSibling(std::shared_ptr<NTreeNode<T>> sibling);
    void SetFigure(std::shared_ptr<T> figure);

    std::shared_ptr<T> GetFigure() const;

    std::shared_ptr<NTreeNode<T>> Getptr();
    std::shared_ptr<NTreeNode<T>> Begin();
    std::shared_ptr<NTreeNode<T>> Next();

    virtual ~NTreeNode();

private:
    std::shared_ptr<T> figure;
    std::weak_ptr<NTreeNode<T>> parent;
    std::shared_ptr<NTreeNode<T>> child;
    std::shared_ptr<NTreeNode<T>> sibling;
};

template <class T>
NTreeNode<T>::NTreeNode(const std::shared_ptr<T>& figure) {
    this->figure = figure;
    this->child = nullptr;
    this->sibling = nullptr;
}

template <class T>
std::shared_ptr<NTreeNode<T>> NTreeNode<T>::GetChild() {
    return this->child;
}

template <class T>
std::shared_ptr<NTreeNode<T>> NTreeNode<T>::GetParent() {
    return this->parent.lock();
}

template <class T>
std::shared_ptr<NTreeNode<T>> NTreeNode<T>::GetSibling() {
    return this->sibling;
}

template <class T>
void NTreeNode<T>::SetChild(std::shared_ptr<NTreeNode<T>> child) {
    this->child = child;
}

template <class T>
void NTreeNode<T>::SetParent(std::shared_ptr<NTreeNode<T>> parent) {
    this->parent = parent;
}

template <class T>
void NTreeNode<T>::SetSibling(std::shared_ptr<NTreeNode<T>> sibling) {
    this->sibling = sibling;
}

template <class T>
void NTreeNode<T>::SetFigure(std::shared_ptr<T> figure) {
    this->figure = figure;
}

template <class T>
std::shared_ptr<T> NTreeNode<T>::GetFigure() const {
    return this->figure;
}

template <class T>
NTreeNode<T>::~NTreeNode() {
    sibling = nullptr;
}

template <class T>
void NTreeNode<T>::print(int indent) {
    for (int i = 0; i < indent; ++i) {
        std::cout << "-";
    }
    this->GetFigure()->Print();
    if (this->GetChild() != nullptr)
        this->GetChild()->print(indent + 1);
    if (this->GetSibling() != nullptr)
        this->GetSibling()->print(indent);
}

template <class TT>
std::ostream& operator<<(std::ostream& os, const NTreeNode<TT>& obj) {
    os << obj.figure << std::endl;
    return os;
}

template<class T> std::shared_ptr<NTreeNode<T>> NTreeNode<T>::Getptr() {
    return this->shared_from_this();
}

template<class T> std::shared_ptr<NTreeNode<T>> NTreeNode<T>::Begin() {
    if (!this->child)
        return Getptr();
    else {
        auto iter = this->child;
        while (iter->child)
            iter = iter->child;
        return iter;
    }
}

template<class T> std::shared_ptr<NTreeNode<T>> NTreeNode<T>::Next() {
    if (this->sibling)
        return this->sibling->Begin();
    else
        if (this->parent.expired())
            return nullptr;
        else
            return this->parent.lock();
}

#endif //OOP_LAB2_NTREENODE_H
