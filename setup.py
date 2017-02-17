#!/usr/bin/env python

""" Build libLinAl library """

import glob
from distutils.core import setup
from distutils.extension import Extension

SRC = "./src/"

SOURCES = glob.glob(SRC + "*.cpp")
LIBS = ["boost_python"]

setup(name="Kinematics",
      author='Vitaly Vorobyev',
      author_email='vit.vorobiev@gmail.com',
      extra_compile_args=["-O2"],
      include_dirs=['./'],
      ext_modules=[
          Extension("liblinal", SOURCES,
                    libraries=LIBS)
          ])
