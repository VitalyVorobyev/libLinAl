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

#include "./vect.h"

namespace linal {

///
/// \brief The LVect class
///
class LVect {
 public:
    LVect();
    LVect(const double& d, const double& a, const double& b, const double& c);
    LVect(const double& a, const Vect& vec);

    Vect Vec(void) const {return m_vec;}
    Vect BoostVec(void) const;
    LVect& Boost(const Vect& bv);

    void t(const double& a) {m_t = a;}
    void x(const double& a) {m_vec.x(a);}
    void y(const double& a) {m_vec.y(a);}
    void z(const double& a) {m_vec.z(a);}

    double x(void)     const;
    double y(void)     const;
    double z(void)     const;
    double t(void)     const;

    double m2(void)    const;
    double m(void)     const;
    double beta(void)  const;
    double beta2(void) const;
    double gamma(void) const;

    LVect& operator=(const LVect& vec);
    LVect& operator+=(const LVect& vec);
    LVect& operator-=(const LVect& vec);
    LVect& operator+(const LVect& vec) const;
    LVect& operator-(const LVect& vec) const;
    LVect operator-(void);
    LVect& operator*=(const double& a);
    LVect& operator/=(const double& a);
    LVect& operator*(const double& a) const;
    LVect& operator/(const double& a) const;

    static double dot(const LVect& lv1, const LVect& lv2);

    friend std::ostream& operator<<(std::ostream& os, const LVect& v);

 private:
    double m_t;
    Vect m_vec;
};

std::ostream& operator<<(std::ostream& os, const LVect& v);

}  // namespace linal

#endif  // _HOME_VITALY_MYLIBS_LIBLINAL_SRC_LVECT_H_
