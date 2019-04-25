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
    Vect(double a, double b, double c);

    void x(double a) {m_x = a;}
    void y(double a) {m_y = a;}
    void z(double a) {m_z = a;}

    double x(void)     const;
    double y(void)     const;
    double z(void)     const;
    double r2(void)    const;
    double r(void)     const;
    double cosTh(void) const;
    double pt(void)    const;

    Vect unit(void) const;

    bool operator==(const Vect& vec) const;
    bool operator!=(const Vect& vec) const;
    Vect& operator+=(const Vect& vec);
    Vect& operator-=(const Vect& vec);
    Vect operator+(const Vect& vec) const;
    Vect operator-(const Vect& vec) const;
    Vect  operator-(void) const;
    Vect& operator*=(double a);
    Vect& operator/=(double a);
    Vect operator*(double a) const;
    Vect operator/(double a) const;

    friend Vect cross(const Vect& v1, const Vect& v2);
    friend double dot(const Vect& v1, const Vect& v2);
    friend Vect operator*(double a, const Vect& vec);
    friend std::ostream& operator<<(std::ostream& os, const Vect& v);

 protected:
    double m_x, m_y, m_z;
};

std::ostream& operator<<(std::ostream& os, const Vect& v);
Vect operator*(double a, const Vect& vec);
double dot(const Vect& v1, const Vect& v2);
Vect cross(const Vect& v1, const Vect& v2);

}  // namespace linal

#endif  // _HOME_VITALY_MYLIBS_LIBLINAL_SRC_VECT_H_
