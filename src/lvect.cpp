/** Copyright 2017 Vitaly Vorobyev
 ** @file lvect.cpp
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#include "/home/vitaly/MyLibs/libLinAl/src/lvect.h"

#include <cmath>
#include <limits>

using std::sqrt;
using std::fabs;
using std::cout;
using std::endl;

namespace linal {

LVect::LVect() : m_t(0), m_vec() {}
LVect::LVect(const double& d, const double& a,
             const double& b, const double& c) : m_t(d), m_vec(a, b, c) {}
LVect::LVect(const double& a, const Vect& vec): m_t(a), m_vec(vec) {}

Vect LVect::BoostVec(void) const {
    return m_vec/m_t;
}

LVect& LVect::Boost(const Vect& bv) {
  const double bt2 = bv.r2();
  const double gm = 1./sqrt(1.-bt2);
  const double bt = gm*(m_t - dot(bv, m_vec));
  const double bx = x() - gm*bv.z()*m_t +
          (gm-1)*bv.x()*(bv.x()*x() + bv.y()*y()+bv.z()*z())/bt2;
  const double by = y() - gm*bv.y()*m_t +
          (gm-1)*bv.y()*(bv.y()*y() + bv.x()*x()+bv.z()*z())/bt2;
  const double bz = z() - gm*bv.z()*m_t +
          (gm-1)*bv.z()*(bv.z()*z() + bv.x()*x()+bv.y()*y())/bt2;
  m_t = bt; m_vec.x(bx); m_vec.y(by); m_vec.z(bz);
  return *this;
}

double LVect::t(void)     const {return m_t;}
double LVect::x(void)     const {return m_vec.x();}
double LVect::y(void)     const {return m_vec.y();}
double LVect::z(void)     const {return m_vec.z();}
double LVect::m2(void)    const {return m_t*m_t - m_vec.r2();}
double LVect::m(void)     const {return sqrt(fabs(m2()));}
double LVect::beta(void)  const {return BoostVec().r();}
double LVect::beta2(void) const {return BoostVec().r2();}
double LVect::gamma(void) const {return 1./sqrt(1-BoostVec().r2());}

LVect& LVect::operator+=(const LVect& vec) {
    m_t += vec.m_t; m_vec += vec.m_vec;
    return *this;
}

LVect& LVect::operator-=(const LVect& vec) {
    m_t -= vec.m_t; m_vec -= vec.m_vec;
    return *this;
}

LVect& LVect::operator+(const LVect& vec) const {
    auto* nlv = new LVect(*this);
    return *nlv += vec;
}

LVect& LVect::operator-(const LVect& vec) const {
    auto* nlv = new LVect(*this);
    return *nlv -= vec;
}

LVect LVect::operator-(void) {
    return LVect(-m_t, -m_vec);
}

LVect& LVect::operator*=(const double& a) {
    m_t *= a; m_vec *= a;
    return *this;
}
LVect& LVect::operator/=(const double& a) {
    if (fabs(a) < std::numeric_limits<double>::min()) {
        cout << "LorentzVector divided by zero!" << endl;
        return *this;
    }
    m_t /= a; m_vec /= a;
    return *this;
}

LVect& LVect::operator*(const double& a) const {
    auto* nlv = new LVect(*this);
    return *nlv *= a;
}

LVect& LVect::operator/(const double& a) const {
    auto* nlv = new LVect(*this);
    return *nlv /= a;
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
