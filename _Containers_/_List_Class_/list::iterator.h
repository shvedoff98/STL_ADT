#include "list.h"

template <typename Elem> class list<Elem>::iterator {

private:
    Link<Elem>* curr;

public:
    iterator(Link* p) :curr{p} {}

    //forward
    iterator& operator++() { curr = curr->succ; return *this; }

    //backward
    iterator& operator--() { curr = curr->prev; return *this; }

    Elem& operator*() { return curr->val; }

    bool operator==(const iterator& b ) const { return curr == b.curr; }

    bool operator!=(const iterator& b) const { return curr != b.curr; }
};
