#ifndef POSITION_H
#define POSITION_H

#include <vector>

template <class Key, class Value>
class Position {
public:
    Position(const Key key);
    Position(const Position<Key, Value> &orig);
    virtual ~Position();
    /* Modificadors */
    // Declareu-hi aquí els modificadors (setters) dels atributs que manquen
    void setParent(Position<Key, Value>* p);
    void setLeft(Position<Key, Value>* l);
    void setRight(Position<Key, Value>* r);


    /* Consultors */
    const Key& getKey() const;
    // Declareu-hi aquí els consultors (getters) dels atributs que manquen
    const std::vector<Value>& getValues() const;
    Position<Key, Value>* getParent() const;
    Position<Key, Value>* getLeft() const;
    Position<Key, Value>* getRight() const;

    /* Operacions */
    bool isRoot() const;
    bool isLeaf() const;
    int depth() const;
    int height() const;
    void addValue(const Value& value);
    bool operator==(const Position<Key, Value>& other) const;
    
private:
    Key key;
    std::vector<Value> values;
    Position<Key, Value>* parent;
    Position<Key, Value>* left;
    Position<Key, Value>* right;
    // Afegiu-hi aquí els atributs que manquen    
};
    
template <class Key, class Value>
Position<Key, Value>::Position(const Key key)
{
    this->key    = key;
    this->parent = nullptr;
    this->left   = nullptr;
    this->right  = nullptr;
}

template <class Key, class Value>
Position<Key, Value>::Position(const Position<Key, Value>& orig)
{
    this->key    = orig.key;
    this->values = orig.values;
    this->parent = nullptr;   
    this->left   = nullptr;  
    this->right  = nullptr;
}

template <class Key, class Value>
Position<Key, Value>::~Position() {
    delete left;
    delete right;
}

template <class Key, class Value>
void Position<Key, Value>::setParent(Position<Key, Value>* p) {
    parent = p;
}

template <class Key, class Value>
void Position<Key, Value>::setLeft(Position<Key, Value>* l) {
    left = l;
}

template <class Key, class Value>
void Position<Key, Value>::setRight(Position<Key, Value>* r) {
    right = r;
}

template <class Key, class Value>
const Key& Position<Key, Value>::getKey() const {
    return key;
}

template <class Key, class Value>
const std::vector<Value>& Position<Key, Value>::getValues() const {
    return values;
}

template <class Key, class Value>
Position<Key, Value>* Position<Key, Value>::getParent() const {
    return parent;
}

template <class Key, class Value>
Position<Key, Value>* Position<Key, Value>::getLeft() const {
    return left;
}

template <class Key, class Value>
Position<Key, Value>* Position<Key, Value>::getRight() const {
    return right;
}

template <class Key, class Value>
bool Position<Key, Value>::isRoot() const {
    return parent == nullptr;
}

template <class Key, class Value>
bool Position<Key, Value>::isLeaf() const {
    return left == nullptr && right == nullptr;
}

template <class Key, class Value>
int Position<Key, Value>::depth() const {
    if (isRoot()) return 0;
    return 1 + getParent()->depth();
}

template <class Key, class Value>
int Position<Key, Value>::height() const {
    if (isLeaf()) return 0;
    int hLeft = (left != nullptr) ? left->height() : -1;
    int hRight = (right != nullptr) ? right->height() : -1;
    return 1 + std::max(hLeft, hRight);
}

template <class Key, class Value>
void Position<Key, Value>::addValue(const Value& value) {
    values.push_back(value);
}

template <class Key, class Value>
bool Position<Key, Value>::operator==(const Position<Key, Value>& other) const {
    if (key != other.key) return false;
    if (values.size() != other.values.size()) return false;
    return values == other.values;
}

#endif /* POSITION_H */