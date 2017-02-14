/** Copyright 2017 Vitaly Vorobyev
 ** @file vect.h
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#ifndef _HOME_VITALY_MYLIBS_LIBLINAL_SRC_VECT_H_
#define _HOME_VITALY_MYLIBS_LIBLINAL_SRC_VECT_H_

#include <iostream>

namespace linal {

/**
 * @brief The Vect class. An implementation of Euclidian three-vector.
 */
class Vect {
 public:
    Vect(void);
    Vect(const double& a, const double& b, const double& c);

    void x(const double& a) {m_x = a;}
    void y(const double& a) {m_y = a;}
    void z(const double& a) {m_z = a;}

    double x(void)     const;
    double y(void)     const;
    double z(void)     const;
    double r2(void)    const;
    double r(void)     const;
    double cosTh(void) const;
    double pt(void)    const;

    Vect& operator=(const Vect& vec);
    Vect& operator+=(const Vect& vec);
    Vect& operator-=(const Vect& vec);
    Vect& operator+(const Vect& vec) const;
    Vect& operator-(const Vect& vec) const;
    Vect  operator-(void);
    Vect& operator*=(const double& a);
    Vect& operator/=(const double& a);
    Vect& operator*(const double& a) const;
    Vect& operator/(const double& a) const;

    friend double dot(const Vect& v1, const Vect& v2);
    friend std::ostream& operator<<(std::ostream& os, const Vect& v);

 protected:
    double m_x, m_y, m_z;
};

}  // namespace linal

#endif  // _HOME_VITALY_MYLIBS_LIBLINAL_SRC_VECT_H_
