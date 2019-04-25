/** Copyright 2017 Vitaly Vorobyev
 ** @file lvect.cpp
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#include "lvect.h"

#include <cmath>
#include <limits>

namespace linal {

using std::sqrt;
using std::fabs;
using std::pow;
using std::cerr;
using std::endl;

LVect::LVect() : m_t(0), m_vec(), m_idMap {
        {0, [&](){return this->t();}},
        {1, [&](){return this->x();}},
        {2, [&](){return this->y();}},
        {3, [&](){return this->z();}}
    } {}
LVect::LVect(double d, double a, double b, double c) : m_t(d), m_vec(a, b, c), m_idMap {
        {0, [&](){return this->t();}},
        {1, [&](){return this->x();}},
        {2, [&](){return this->y();}},
        {3, [&](){return this->z();}}
    } {}
LVect::LVect(double a, const Vect& vec): m_t(a), m_vec(vec), m_idMap {
        {0, [&](){return this->t();}},
        {1, [&](){return this->x();}},
        {2, [&](){return this->y();}},
        {3, [&](){return this->z();}}
    } {}

Vect LVect::BoostVec(void) const {
    return m_vec / m_t;
}

LVect& LVect::Boost(const Vect& bv) {
    const double bbeta = bv.r();
    if (bbeta >= 1) {
        cerr << "LVect::Boost: space-like vector boost!" << endl;
        return *this;
    }
    const double bgamma = 1./sqrt(1.-pow(bbeta, 2));
    const Vect bdirect = -bv / bbeta;
    const double dotnr = dot(m_vec, bdirect);
    *this = LVect(bgamma * (m_t - bbeta * dotnr), 
                  m_vec + ((bgamma-1.)*dotnr - bgamma*m_t*bbeta) * bdirect);
//  const double bt = gm*(m_t - Vect::dot(bv, m_vec));
//  const double bx = x() - gm*bv.z()*m_t +
//          (gm-1)*bv.x()*(bv.x()*x() + bv.y()*y()+bv.z()*z())/bt2;
//  const double by = y() - gm*bv.y()*m_t +
//          (gm-1)*bv.y()*(bv.y()*y() + bv.x()*x()+bv.z()*z())/bt2;
//  const double bz = z() - gm*bv.z()*m_t +
//          (gm-1)*bv.z()*(bv.z()*z() + bv.x()*x()+bv.y()*y())/bt2;
//  *this = LVect(bt, bx, by, bz);
  return *this;
}

double LVect::t(void)     const {return m_t;}
double LVect::x(void)     const {return m_vec.x();}
double LVect::y(void)     const {return m_vec.y();}
double LVect::z(void)     const {return m_vec.z();}
double LVect::m2(void)    const {return dot(*this, *this);}
double LVect::m(void)     const {return sqrt(fabs(m2()));}
double LVect::beta(void)  const {return BoostVec().r();}
double LVect::beta2(void) const {return BoostVec().r2();}
double LVect::gamma(void) const {return 1./sqrt(1-BoostVec().r2());}

bool LVect::operator==(const LVect& vec) const {
    if (fabs(m_t - vec.m_t) > std::numeric_limits<double>::min()) return false;
    if (fabs(x() - vec.x()) > std::numeric_limits<double>::min()) return false;
    if (fabs(y() - vec.y()) > std::numeric_limits<double>::min()) return false;
    if (fabs(z() - vec.z()) > std::numeric_limits<double>::min()) return false;
    return true;
}

bool LVect::operator!=(const LVect& vec) const {
    return !(*this == vec);
}

LVect& LVect::operator+=(const LVect& vec) {
    m_t += vec.m_t; m_vec += vec.m_vec;
    return *this;
}

LVect& LVect::operator-=(const LVect& vec) {
    m_t -= vec.m_t; m_vec -= vec.m_vec;
    return *this;
}

LVect LVect::operator+(const LVect& vec) const {
    return LVect(*this) += vec;
}

LVect LVect::operator-(const LVect& vec) const {
    return LVect(*this) -= vec;
}

LVect LVect::operator-(void) const {
    return LVect(-m_t, -m_vec);
}

LVect& LVect::operator*=(double a) {
    m_t *= a; m_vec *= a;
    return *this;
}

LVect operator*(double a, LVect& vec) {
    return vec*a;
}

LVect& LVect::operator/=(double a) {
    if (fabs(a) < std::numeric_limits<double>::min()) {
        cerr << "LorentzVector divided by zero!" << endl;
        return *this;
    }
    m_t /= a; m_vec /= a;
    return *this;
}

LVect LVect::operator*(double a) const {
    return LVect(*this) *= a;
}

LVect LVect::operator/(double a) const {
    return LVect(*this) /= a;
}

double LVect::at(int i) const {
    return m_idMap.find(i)->second();
}

double dot(const LVect& lv1, const LVect& lv2) {
    return lv1.m_t*lv2.m_t - dot(lv1.m_vec, lv2.m_vec);
}

std::ostream& operator<<(std::ostream& os, const LVect& v) {
    os << "(" << v.m_t << ", " << v.x() << ", "
       << v.y() << ", " << v.z() << ")";
    return os;
}

}  // namespace linal
