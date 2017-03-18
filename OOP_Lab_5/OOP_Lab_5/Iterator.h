#ifndef ITERATOR_H
#define ITERATOR_H
#include <memory>

template <class node, class T>
class Iterator {
public:

	Iterator(std::shared_ptr<node> n) {
		node_ptr = n;
	}

	std::shared_ptr<T> operator * () {
		return node_ptr->GetFigure();
	}

	std::shared_ptr<T> operator -> () {
		return node_ptr->GetFigure();
	}

	void operator ++ (){
		node_ptr = node_ptr->Next();
	}

	Iterator operator ++ (int) {
		Iterator iter(*this);
		++(*this);
		return iter;
	}

	bool operator == (Iterator const& i) {
		return node_ptr == i.node_ptr;
	}

	bool operator != (Iterator const& i) {
		return !(*this == i);
	}

private:
	std::shared_ptr<node> node_ptr;

};

#endif