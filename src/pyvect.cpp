/** Copyright 2017 Vitaly Vorobyev
 ** @file pyvect.cpp
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#include "../src/pyvect.h"

#include <string>
#include <sstream>
#include <iostream>

#include <boost/python.hpp>
#include "./vect.h"

using boost::python::class_;
using boost::python::self;
using boost::python::args;
using boost::python::init;
using boost::python::dict;
using boost::python::extract;
using boost::python::list;
using boost::python::len;

using linal::Vect;

using std::cerr;
using std::endl;

std::string strVect(const Vect& v) {
    std::stringstream out;
    out << v;
    return out.str();
}

std::string reprVect(const Vect& v) {
    return "vect: " + strVect(v);
}

dict VectToDict(const Vect& v) {
    dict res;
    res["x"] = v.x();
    res["y"] = v.y();
    res["z"] = v.z();
    return res;
}

void DictToVect(Vect& v, const dict& d) {
    v.x(d.has_key("x") ? extract<double>(d["x"]) : 0.);
    v.y(d.has_key("y") ? extract<double>(d["y"]) : 0.);
    v.z(d.has_key("z") ? extract<double>(d["z"]) : 0.);
}

list VectToList(const Vect& v) {
    list res;
    res.append(v.x());
    res.append(v.y());
    res.append(v.z());
    return res;
}

void ListToVect(Vect& v, const list& l) {
    if (len(l) != 3) {
        cerr << "ListToVect: wrong list size " << len(l) << endl;
        return;
    }
    v.x(extract<double>(l[0]));
    v.y(extract<double>(l[1]));
    v.z(extract<double>(l[2]));
}

typedef double (Vect::*VGet)() const;
typedef void (Vect::*VSet)(const double&);

void wrapVect() { class_<Vect>("vect", init<>())
            .def(init<const double&, const double&, const double&>(
                     args("x", "y", "z")))
            .add_property("x", static_cast<VGet>(&Vect::x),
                               static_cast<VSet>(&Vect::x))
            .add_property("y", static_cast<VGet>(&Vect::y),
                               static_cast<VSet>(&Vect::y))
            .add_property("z", static_cast<VGet>(&Vect::z),
                               static_cast<VSet>(&Vect::z))
            .add_property("as_dict", &VectToDict, &DictToVect)
            .add_property("as_list", &VectToList, &ListToVect)
            .def("r2", &Vect::r2)
            .def("costh", &Vect::cosTh)
            .def("pt", &Vect::pt)
            .def("unit", &Vect::unit)
            .def("dot", &Vect::dot)
            .def("__abs__", &Vect::r)
            .def("__str__", &strVect)
            .def("__repr__", &reprVect)
            .def(self == Vect())
            .def(self != Vect())
            .def(self += Vect())
            .def(self -= Vect())
            .def(self + Vect())
            .def(self - Vect())
            .def(self *= double())
            .def(self * double())
            .def(double() * self)
            .def(self / double())
            .def(-self)
            ;
}
