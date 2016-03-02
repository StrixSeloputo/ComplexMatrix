#ifndef ROW_H
#define ROW_H

#include <iostream>

class Elem;

class Row
{
private:
    Elem *_row;
    unsigned _size;

public:
    Row();
    Row(unsigned);
    Row(const Row &);
    ~Row();

    unsigned size() const;

    void resize(unsigned = 1);

    Elem &operator[](unsigned);
    const Elem &operator[](unsigned) const;

//    friend std::istream &operator>>(std::istream &, Row &);
//    friend std::ostream &operator<<(std::ostream &, const Row &);

    bool operator==(const Row &) const;
    bool operator!=(const Row &) const;

    Row &operator=(const Row &);
};

#endif
