template <class Key, class Value>
class Position {
public:
    Position(const Key key);
    Position(const Position<Key, Value>& orig);
    virtual ~Position();
    /* Modificadors */
    // Declareu-hi aquí els modificadors (setters) dels atributs que manquen
    const Value Parent setParent() const;


    /* Consultors */
    const Key& getKey() const;
    const vector<Value>& getValues() const;
    const Value& getleft();
    const Value& getright();
    // Declareu-hi aquí els consultors (getters) dels atributs que manquen

    /* Operacions */
    bool isRoot() const;
    bool isLeaf() const;
    int depth() const;
    int height() const;
    void addValue(const Value& value);
    bool operator==(const Position<Key, Value>& other) const;
    
private:
    Key key;
    vector<Value> values;
    Value parent;
    Value left;
    Value right;
    
    // Afegiu-hi aquí els atributs que manquen    
};
      
template<class Key, class Value> Position<Key, Value>:: Position(const Key key){
    this->key = key;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template<class Key, class Value> Position<Key, Value>:: Position(const Position<Key, Value>& orig){
    this->key = orig.key;
    this->values = orig.values;
    this->parent = orig.parent;
    this->left = orig.left;
    this->right = orig.right;
}

template<class Key, class Value> Position<Key, Value>:: ~Position(){}



