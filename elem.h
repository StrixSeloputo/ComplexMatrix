#ifndef ELEM_H
#define ELEM_H

#define     NOTHING     0x100
#define     DOUBLE      0x101
#define     VECTOR      0x102
#define     OPERATOR    0x104
#define     ANY         0x107

#define     DIM         3
#define     SIZE        DIM*DIM
#define     ORD         DIM

class Elem
{
private:
    int _indicator;

    double _number;
    double _vector[DIM];
//    Elem _operator[SIZE];

    Elem(int ind, double numb, double vect[]);
public:
    Elem(int ind = DOUBLE);
    Elem(const Elem &orig);
    Elem(double numb);
    Elem(double vect[]);
//    Elem(Elem op[]);

    Elem &operator- () const;
    Elem &operator+ (const Elem &) const;
    Elem &operator- (const Elem &) const;
    Elem &operator* (const Elem &) const;
    Elem &operator/ (const Elem &) const;

    Elem &operator* (const double);
    Elem &operator/ (const double);
    Elem &operator ^ (const int);

    bool operator== (const Elem &) const;
    bool operator!= (const Elem &) const;

    Elem &operator = (const Elem &);

    Elem &operator += (const Elem &);
    Elem &operator -= (const Elem &);
    Elem &operator *= (const Elem &);
    Elem &operator/= (const Elem &);
    Elem &operator *= (const double);

    static Elem zero();
    static Elem unity();

    double numb();
};

#endif // ELEM_H
