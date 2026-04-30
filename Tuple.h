#ifndef TUPLE_H
#define TUPLE_H

template <class Key, class Value>
class Tuple{
public:
    Tuple(const Key key, const Value value);
    Tuple(const Tuple<Key, Value>& orig);
    virtual ~Tuple();
    getText() const;


private:
        

}

endif TUPLE_H 