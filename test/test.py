""" Unit tests """

from liblinal import vect

def vect_unit_test():
    """ Wrapped Vect C++ class unit tests """
    print "Unit tests for liblinal.vect:"
    print "1. Defaulf constructor:"
    print vect()

    print "2. Constructor (1, 2, 3):"
    v = vect(1, 2, 3)
    print v

    print "3. Getters:"
    print "x:", v.x, "y", v.y, "z", v.z

    print "4. Setters (3, 2, 1):"
    v.x, v.y, v.z = 3, 2, 1
    print v

    print "5.1 Get unit vector:"
    print v.unit()
    print "5.2 Get unit vector for zero vector:"
    print vect().unit()

    print "6. Absolute value (1.0):"
    print abs(vect(1., 2., 3.).unit())

    print "7. Vector norm (14.0 and 1.0):"
    print vect(1., 2., 3.).r2()
    print vect(1., 2., 3.).unit().r2()

    print "8. dot product (10.0):"
    v = vect(1, 2, 3)
    w = vect(3, 2, 1)
    print vect.dot(v, w)

    print "9. Unary minus:"
    print v, -v

    print "10. pt, cosTh:"
    print v.pt(), v.costh()

    print "11. vect as dict:"
    vdict = v.as_dict
    for dim in vdict:
        print dim, vdict[dim]

    print "12. vect as list:"
    print v.as_list

    print "13. list to vect:"
    alist = [1, 3, 4]
    print vect(*(alist))

    print "14. == operator:"
    w = v
    z = 2*v
    print w, v, w==v
    print v, z, v==z

    print "15. != operator:"
    print w, v, w!=v
    print z, v, z!=v

    print "16.1 double * vect:"
    a = 2.1
    print v, a, a*v
    print "16.2 vect * double:"
    print v, a, v*a

    print "17. vect / double:"
    print v, a, v/a
    print v, 0, v/0

    print "18.1 vect1 + vect2:"
    print v, z, v + z
    print "18.2 vect1 - vect2:"
    print v, z, v - z

    print "19.1 vect1 += vect2:"
    print v, z
    v += z
    print v
    print "19.2 vect1 -= vect2:"
    print v, z
    v -= z
    print v

vect_unit_test()
