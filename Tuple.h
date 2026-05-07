#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>

class Tuple {
private:
    int linea;
    int posicio;

public:
    Tuple(int lin = 0, int pos = 0);

    int getLinea() const;
    int getPosicio() const;

    void setLinea(int lin);
    void setPosicio(int pos);

    bool operator==(const Tuple& other) const;
    bool operator<(const Tuple& other) const;
};

#endif // TUPLE_H
