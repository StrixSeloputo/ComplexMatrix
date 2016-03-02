
#include <stdio.h>
#include <stdexcept>

#include <QtCore/QtGlobal>

#include "elem.h"

Elem::Elem(int ind) :
    _indicator(ind)
    ,_number(0)
    ,_vector{0}
{ }

Elem::Elem(int ind, double numb, double vect[]) :
    _indicator(ind)
    ,_number(numb)
{
    try {
        for (int i = 0; i < DIM; i++)
            _vector[i] = vect[i];
    } catch (...) {
        qFatal ("Expeption during copying to double[SIZE] from double[] (Elem::Elem(int, double, double[]))");
    }
}

Elem::Elem(double numb) :
    _indicator(DOUBLE)
    ,_number(numb)
    ,_vector{0}
{ }

Elem::Elem(double vect[]) :
    _indicator(VECTOR)
    ,_number(0)
{
    try {
        for (int i = 0; i < DIM; i++)
            _vector[i] = vect[i];
    } catch (...) {
        qFatal ("Expeption during copying to double[SIZE] from double[] (Elem::Elem(double[]))");
    }
}

Elem::Elem(const Elem &orig) :
    _indicator(orig._indicator)
    ,_number(orig._number)
//    ,_vector(orig._vector)
//   , _operator(orig._operator)
{
    for (int i = 0; i < SIZE; i++)
        _vector[i] = orig._vector[i];
}

Elem Elem::zero()
{
    double zero_vect[DIM] = { 0 };
    Elem z(ANY, 0, zero_vect);
    return z;
}

Elem Elem::unity()
{
    double unity_vect[DIM] = { 0 };
    Elem z(DOUBLE, 1, unity_vect);
    return z;
}

double Elem::numb()
{
    return (_indicator & DOUBLE != NOTHING) ? _number : 0;
}

bool Elem::operator== (const Elem &other) const
{
    if (_indicator & other._indicator == NOTHING)
        return false;
    switch (_indicator) {
    case ANY:
        switch (other._indicator) {
        case ANY:
            if (_number != other._number)
                return false;
            for (int i = 0; i < DIM; i++)
                if (_vector[i] != other._vector[i])
                    return false;
            ////
            return true;
        case DOUBLE:
            return _number == other._number;
        case VECTOR:
            for (int i = 0; i < DIM; i++)
                if (_vector[i] != other._vector[i])
                    return false;
            return true;
        //// case OPERATOR:
        ////
        }
    case DOUBLE:
        return _number == other._number;
    case VECTOR:
        for (int i = 0; i < DIM; i++)
            if (_vector[i] != other._vector[i])
                return false;
        return true;
    ////case OPERATOR:
    ////
    }
    return false;
}
bool Elem::operator!= (const Elem &other) const
{
    return !(*this == other);
}

Elem &Elem::operator= (const Elem &other)
{
    if (this != &other) {
        _indicator = other._indicator;
        _number = other._number;
        for (int i = 0; i < SIZE; i++)
            _vector[i] = other._vector[i];
        ////
    }
    return *this;
}

Elem &Elem::operator-() const
{
    double v[DIM];
    for (int i = 0; i < DIM; i++)
        v[i] = -_vector[i];
    ////
    //Elem t(_indicator, -_number, v);
    //return Elem (_indicator, -_number, v);
}

Elem &Elem::operator+= (const Elem &other)
{
    if (this != &other) {
        if (_indicator & other._indicator == NOTHING) {
            const char *msg = "Incomplite type in Elem::operator+=";
            throw std::runtime_error(msg);
        }
        _number += other._number;
        for (int i = 0; i < SIZE; i++)
            _vector[i] += other._vector[i];
        ////
    }
    return *this;
}

Elem &Elem::operator-= (const Elem &other)
{
    return (*this += (-other));
}
