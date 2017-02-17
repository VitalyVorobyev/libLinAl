/** Copyright 2017 Vitaly Vorobyev
 ** @file pylvect.cpp
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
#include "./lvect.h"

using boost::python::class_;
using boost::python::self;
using boost::python::args;
using boost::python::init;
using boost::python::return_value_policy;
using boost::python::reference_existing_object;

using linal::Vect;
using linal::LVect;

std::string strLVect(const LVect& v) {
    std::stringstream out;
    out << v;
    return out.str();
}

std::string reprLVect(const LVect& v) {
    return "lvect: " + strLVect(v);
}

typedef double (LVect::*LVGet)() const;
typedef void (LVect::*LVSet)(const double&);

// BOOST_PYTHON_MODULE(lvect) {
void wrapLVect() { class_<LVect>("lvect", init<>())
            .def(init<const double&, const double&,
                      const double&, const double&>(
                     args("t", "x", "y", "z")))
            .def(init<const double&, const Vect&>(args("t" ,"r")))
            .add_property("t", static_cast<LVGet>(&LVect::t),
                               static_cast<LVSet>(&LVect::t))
            .add_property("x", static_cast<LVGet>(&LVect::x),
                               static_cast<LVSet>(&LVect::x))
            .add_property("y", static_cast<LVGet>(&LVect::y),
                               static_cast<LVSet>(&LVect::y))
            .add_property("z", static_cast<LVGet>(&LVect::z),
                               static_cast<LVSet>(&LVect::z))
            .def("r", &LVect::Vec)
            .def("boost_vect", &LVect::BoostVec)
            .def("boost", &LVect::Boost,
                 return_value_policy<reference_existing_object>())
            .def("m2", &LVect::m2)
            .def("__abs__", &LVect::m)
            .def("dot", &LVect::dot)
            .def("__str__", &strLVect)
            .def("__repr__", &reprLVect)
            .def(self += LVect())
            .def(self -= LVect())
            .def(self + LVect())
            .def(self - LVect())
            .def(self *= double())
            .def(self * double())
            ;
}
