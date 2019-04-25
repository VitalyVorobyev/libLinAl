/** Copyright 2017 Vitaly Vorobyev
 ** @file lvect.h
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#ifndef _HOME_VITALY_MYLIBS_LIBLINAL_SRC_LVECT_H_
#define _HOME_VITALY_MYLIBS_LIBLINAL_SRC_LVECT_H_

#include "vect.h"

#include <map>
#include <functional>

namespace linal {

///
/// \brief The LVect class
///
class LVect {
    std::map<int, std::function<double()>> m_idMap;

 public:

    LVect();
    LVect(double d, double a, double b, double c);
    LVect(double a, const Vect& vec);

    Vect Vec(void) const {return m_vec;}
    Vect BoostVec(void) const;
    LVect& Boost(const Vect& bv);

    void t(double a) {m_t = a;}
    void x(double a) {m_vec.x(a);}
    void y(double a) {m_vec.y(a);}
    void z(double a) {m_vec.z(a);}

    double t(void)     const;
    double x(void)     const;
    double y(void)     const;
    double z(void)     const;

    double m2(void)    const;
    double m(void)     const;
    double beta(void)  const;
    double beta2(void) const;
    double gamma(void) const;
    double at(int i) const;

    // Static methods //
    friend double dot(const LVect& lv1, const LVect& lv2);

    // Operators overloading //
    bool operator==(const LVect& vec) const;
    bool operator!=(const LVect& vec) const;
    LVect& operator+=(const LVect& vec);
    LVect& operator-=(const LVect& vec);
    LVect operator+(const LVect& vec) const;
    LVect operator-(const LVect& vec) const;
    LVect operator-(void) const;
    LVect& operator*=(double a);
    LVect& operator/=(double a);
    LVect operator*(double a) const;
    // double& operator[](int i);
    friend LVect operator*(double a, LVect& vec);
    LVect operator/(double a) const;

    friend std::ostream& operator<<(std::ostream& os, const LVect& v);

 private:
    double m_t;
    Vect m_vec;
};

std::ostream& operator<<(std::ostream& os, const LVect& v);
LVect operator*(double a, LVect& vec);
double dot(const LVect& lv1, const LVect& lv2);

}  // namespace linal

#endif  // _HOME_VITALY_MYLIBS_LIBLINAL_SRC_LVECT_H_
