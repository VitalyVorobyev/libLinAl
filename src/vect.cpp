/** Copyright 2017 Vitaly Vorobyev
 ** @file vect.cpp
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#include "/home/vitaly/MyLibs/libLinAl/src/vect.h"

#include <cmath>
#include <limits>

using std::sqrt;
using std::fabs;
using std::cout;
using std::endl;

namespace linal {

Vect::Vect(const double& a, const double& b, const double& c) :
    m_x(a), m_y(b), m_z(c) {}

Vect::Vect() : Vect(0, 0, 0) {}

double Vect::x(void)     const {return m_x;}
double Vect::y(void)     const {return m_y;}
double Vect::z(void)     const {return m_z;}
double Vect::r2(void)    const {return m_x*m_x+m_y*m_y+m_z*m_z;}
double Vect::r(void)     const {return sqrt(r2());}
double Vect::cosTh(void) const {return m_z/r();}
double Vect::pt(void)    const {return sqrt(m_x*m_x+m_y*m_y);}

Vect& Vect::operator+=(const Vect& vec) {
    m_x += vec.x(); m_y += vec.y(); m_z += vec.z();
    return *this;
}

Vect& Vect::operator-=(const Vect& vec) {
    m_x -= vec.x(); m_y -= vec.y(); m_z -= vec.z();
    return *this;
}

Vect& Vect::operator+(const Vect& vec) const {
    auto nvec = new Vect(*this);
    return *nvec += vec;
}

Vect& Vect::operator-(const Vect& vec) const {
    auto* nvec = new Vect(*this);
    return *nvec -= vec;
}

Vect Vect::operator-(void) {
    return Vect(-m_x, -m_y, -m_z);
}

Vect& Vect::operator*=(const double& a) {
    m_x *= a; m_y *= a; m_z *= a;
    return *this;
}

Vect& Vect::operator/=(const double& a) {
    if (fabs(a) < std::numeric_limits<double>::min()) {
        cout << "ThreeVector divided by zero!" << endl;
        return *this;
    }
    m_x /= a; m_y /= a; m_z /= a;
    return *this;
}

Vect& Vect::operator*(const double& a) const {
    auto* nvec = new Vect(*this);
    return *nvec *= a;
}

Vect& Vect::operator/(const double& a) const {
    auto* nvec = new Vect(*this);
    return *nvec /= a;
}

double dot(const Vect& v1, const Vect& v2) {
    return v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z;
}

std::ostream& operator<<(std::ostream& os, const Vect& v) {
    os << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ")";
    return os;
}

}  // namespace linal
