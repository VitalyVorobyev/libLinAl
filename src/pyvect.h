/** Copyright 2017 Vitaly Vorobyev
 ** @file pyvect.cpp
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#include <string>
#include <sstream>

#include <boost/python.hpp>
#include "./vect.h"

using boost::python::class_;
using boost::python::self;
using boost::python::args;
using boost::python::init;

using linal::Vect;

std::string strVect(const Vect& v) {
    std::stringstream out;
    out << v;
    return out.str();
}

std::string reprVect(const Vect& v) {
    return "vect: " + strVect(v);
}

typedef double (Vect::*VGet)() const;
typedef void (Vect::*VSet)(const double&);

//BOOST_PYTHON_MODULE(liblinal) {
void wrapVect() { class_<Vect>("vect", init<>())
            .def(init<const double&, const double&, const double&>(
                     args("x", "y", "z")))
            .add_property("x", static_cast<VGet>(&Vect::x),
                               static_cast<VSet>(&Vect::x))
            .add_property("y", static_cast<VGet>(&Vect::y),
                               static_cast<VSet>(&Vect::y))
            .add_property("z", static_cast<VGet>(&Vect::z),
                               static_cast<VSet>(&Vect::z))
            .def("r2", &Vect::r2)
            .def("r", &Vect::r)
            .def("costh", &Vect::cosTh)
            .def("pt", &Vect::pt)
            .def("dot", &Vect::dot)
            .def("__str__", &strVect)
            .def("__repr__", &reprVect)
            .def(self += Vect())
            .def(self -= Vect())
            .def(self + Vect())
            .def(self - Vect())
            .def(self *= double())
            .def(self * double())
            ;
}
