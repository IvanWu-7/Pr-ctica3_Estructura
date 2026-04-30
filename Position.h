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
      
#endif //POSITION_H

