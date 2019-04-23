/** Copyright 2017 Vitaly Vorobyev
 ** @file pylvect.cpp
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#include "../src/pylvect.h"

#include <string>
#include <sstream>
#include <iostream>

#include <boost/python.hpp>
#include "./lvect.h"

using boost::python::class_;
using boost::python::self;
using boost::python::args;
using boost::python::init;
using boost::python::return_value_policy;
using boost::python::reference_existing_object;
using boost::python::dict;
using boost::python::extract;
using boost::python::list;
using boost::python::len;

using std::cerr;
using std::endl;

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

dict LVectToDict(const LVect& v) {
    dict res;
    res["t"] = v.t();
    res["x"] = v.x();
    res["y"] = v.y();
    res["z"] = v.z();
    return res;
}

void DictToLVect(LVect& v, const dict& d) {
    v.t(d.has_key("t") ? extract<double>(d["t"]) : 0.);
    v.x(d.has_key("x") ? extract<double>(d["x"]) : 0.);
    v.y(d.has_key("y") ? extract<double>(d["y"]) : 0.);
    v.z(d.has_key("z") ? extract<double>(d["z"]) : 0.);
}

list LVectToList(const LVect& v) {
    list res;
    res.append(v.t());
    res.append(v.x());
    res.append(v.y());
    res.append(v.z());
    return res;
}

void ListToLVect(LVect& v, const list& l) {
    if (len(l) != 4) {
        cerr << "ListToLVect: wrong list size " << len(l) << endl;
        return;
    }
    v.t(extract<double>(l[0]));
    v.x(extract<double>(l[1]));
    v.y(extract<double>(l[2]));
    v.z(extract<double>(l[3]));
}

typedef double (LVect::*LVGet)() const;
typedef void (LVect::*LVSet)(const double&);

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
            .add_property("as_dict", LVectToDict, DictToLVect)
            .add_property("as_list", LVectToList, ListToLVect)
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
            .def(double() * self)
            .def(self / double())
            ;
}
