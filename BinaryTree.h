#include "Position.h"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

template <class Key, class Value>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree<Key, Value>& orig);
    virtual ~BinaryTree();
    void deleteSubtree(Position<Key, Value> *node);
    bool isEmpty() const;
    Position<Key, Value>* getRoot() const;
    int size() const;
    int height() const;
    virtual Position<Key, Value>* insert(const Key& key, const Value& value);
    bool contains(const Key& key) const;
    const std::vector<Value>& getValues(const Key& key) const;
    void printPreOrder(const Position<Key, Value> *node = nullptr) const;
    void printPostOrder(const Position<Key, Value> *node = nullptr) const;
    bool identicalTree(const BinaryTree<Key, Value>& other) const;
    Position<Key, Value>* search(const Key& key) cont; 
protected:
    Position<Key, Value>* root;
private:
    int _size;
    /* Mètodes auxiliars definiu aquí els que necessiteu */   
    Position<Key, Value>* searchHelper(Position<Key, Value>* node, const Key& key) const;
    bool identicalHelper(const Position<Key, Value>* a, const Position<Key, Value>* b) const;
};

template <class Key, class Value>
BinaryTree<Key, Value>::BinaryTree()
{
    root = nullptr;
    _size = 0;
}

template <class Key, class Value>
BinaryTree<Key, Value>::BinaryTree(const BinaryTree<Key, Value>& orig)
{
    if (node == nullptr) return;
    deleteSubtree(node->getLeft());
    deleteSubtree(node->getRight());
    delete node;
}


template <class Key, class Value>
BinaryTree<Key, Value>::~BinaryTree()
{
    deleteSubtree(root);
}

template <class Key, class Value>
void BinaryTree<Key, Value>::deleteSubtree(Position<Key, Value>* node)
{
    if (node == nullptr) return;
    
    deleteSubtree(node->getLeft());
    deleteSubtree(node->getRight());
    delete node;
}

template <class Key, class Value>
bool BinaryTree<Key, Value>::isEmpty() const
{
    return root == nullptr;
}

template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>::getRoot() const
{
    return root;
}

template <class Key, class Value>
int BinaryTree<Key, Value>::size() const
{
    return _size;
}

template <class Key, class Value>
int BinaryTree<Key, Value>::height() const
{
    if (isEmpty()) return 0;
    return root->height();
}

template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>::insert(const Key& key, const Value& value) {
    if (isEmpty()) {
        root = new Position<Key, Value>(key);
        root->addValue(value);
        _size = 1;
        return root;
    }

    Position<Key, Value>* current = root;
    Position<Key, Value>* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key < current->getKey()) {
            current = current->getLeft();
        } else if (key > current->getKey()) {
            current = current->getRight();
        } else {
            current->addValue(value);  
            return current;
        }
    }
    Position<Key, Value>* newNode = new Position<Key, Value>(key);
    newNode->addValue(value);

    if (key < parent->getKey()) {
        parent->setLeft(newNode);
    } else {
        parent->setRight(newNode);
    }

    newNode->setParent(parent);
    _size++;

    return newNode;
}

template <class Key, class Value>
bool BinaryTree<Key, Value>::contains(const Key& key) const {
    return search(key) != nullptr;       
}

template <class Key, class Value>
const std::vector<Value>& BinaryTree<Key, Value>::getValues(const Key& key) const {
    Position<Key, Value>* node = search(key);
    if (node == nullptr) {
        throw std::runtime_error("Key not found"); 
    }
    return node->getValues();
}

template <class Key, class Value>
void BinaryTree<Key, Value>::printPreOrder(const Position<Key, Value>* node) const {
    if (node == nullptr) {
        if (root == nullptr) return;
        node = root;
    }
    std::cout << node->getKey() << " ";
    printPreOrder(node->getLeft());
    printPreOrder(node->getRight());
}

template <class Key, class Value>
void BinaryTree<Key, Value>::printPostOrder(const Position<Key, Value>* node) const {
    if (node == nullptr) {
        if (root == nullptr) return;
        node = root;
    }
    printPostOrder(node->getLeft());
    printPostOrder(node->getRight());
    std::cout << node->getKey() << " ";
}

template <class Key, class Value>
bool BinaryTree<Key, Value>::identicalTree(const BinaryTree<Key, Value>& other) const {
    return identicalHelper(root, other.root);
}

template <class Key, class Value>
bool BinaryTree<Key, Value>::identicalHelper(const Position<Key, Value>* a,
                                             const Position<Key, Value>* b) const {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return (a->getKey() == b->getKey()) &&
           (a->getValues() == b->getValues()) &&
           identicalHelper(a->getLeft(), b->getLeft()) &&
           identicalHelper(a->getRight(), b->getRight());
}

template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>::search(const Key& key) const {
    return searchHelper(root, key);
}

template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>::searchHelper(Position<Key, Value>* node, const Key& key) const
{
    if (node == nullptr) return nullptr;

    if (key == node->getKey()) {
        return node;
    }
    else if (key < node->getKey()) {
        return searchHelper(node->getLeft(), key);
    }
    else {
        return searchHelper(node->getRight(), key);
    }
}



