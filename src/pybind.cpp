/** Copyright 2017 Vitaly Vorobyev
 ** @file pybind.cpp
 **
 ** @brief This message displayed in Doxygen Files index
 **
 ** @author Vitaly Vorobyev
 ** Contact: vit.vorobiev@gmail.com
 **
 **/

#include "./pyvect.h"
#include "./pylvect.h"

BOOST_PYTHON_MODULE(liblinal) {
    wrapVect();
    wrapLVect();
}
