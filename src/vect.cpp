/** Copyright 2017 Vitaly Vorobyev
 ** @file vect.cpp
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#include "vect.h"

#include <cmath>
#include <limits>
#include <iostream>

namespace linal {

using std::sqrt;
using std::fabs;
using std::endl;
using std::cerr;

Vect::Vect(double a, double b, double c) : m_x(a), m_y(b), m_z(c) {}
Vect::Vect() : Vect(0, 0, 0) {}

double Vect::x(void)     const {return m_x;}
double Vect::y(void)     const {return m_y;}
double Vect::z(void)     const {return m_z;}
double Vect::r2(void)    const {return m_x*m_x+m_y*m_y+m_z*m_z;}
double Vect::r(void)     const {return sqrt(r2());}
double Vect::cosTh(void) const {return m_z/r();}
double Vect::pt(void)    const {return sqrt(m_x*m_x+m_y*m_y);}

Vect Vect::unit(void) const {
    const double len = this->r();
    if (len < std::numeric_limits<double>::min()) {
        cerr << "Vect::unit for zero vect" << endl;
        return *this;
    }
    return *this / this->r();
}

bool Vect::operator==(const Vect& vec) const {
    if (fabs(m_x - vec.m_x) > std::numeric_limits<double>::min()) return false;
    if (fabs(m_y - vec.m_y) > std::numeric_limits<double>::min()) return false;
    if (fabs(m_z - vec.m_z) > std::numeric_limits<double>::min()) return false;
    return true;
}

bool Vect::operator!=(const Vect& vec) const {
    return !(*this == vec);
}

Vect& Vect::operator+=(const Vect& vec) {
    m_x += vec.m_x; m_y += vec.m_y; m_z += vec.m_z;
    return *this;
}

Vect& Vect::operator-=(const Vect& vec) {
    m_x -= vec.m_x; m_y -= vec.m_y; m_z -= vec.m_z;
    return *this;
}

Vect Vect::operator+(const Vect& vec) const {
    return Vect(*this) += vec;
}

Vect Vect::operator-(const Vect& vec) const {
    return Vect(*this) -= vec;
}

Vect Vect::operator-(void) const {
    return Vect(-m_x, -m_y, -m_z);
}

Vect& Vect::operator*=(double a) {
    m_x *= a; m_y *= a; m_z *= a;
    return *this;
}

Vect& Vect::operator/=(double a) {
    if (fabs(a) < std::numeric_limits<double>::min()) {
        cerr << "Vect divided by zero!" << endl;
        return *this;
    }
    m_x /= a; m_y /= a; m_z /= a;
    return *this;
}

Vect Vect::operator*(double a) const {
    return Vect(*this) *= a;
}

Vect operator*(double a, const Vect& vec) {
    return vec*a;
}

Vect Vect::operator/(double a) const {
    return Vect(*this) /= a;
}

double dot(const Vect& v1, const Vect& v2) {
    return v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z;
}

std::ostream& operator<<(std::ostream& os, const Vect& v) {
    os << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ")";
    return os;
}

}  // namespace linal
