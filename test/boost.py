""" Boost """

import numpy as np
import matplotlib.pyplot as plt
from liblinal import vect, lvect

def boost_test():
    """ Boost unit test """
    boost_list = np.linspace(0.0001, 0.9, 500)
    txprime = np.array([lvect(1., 0, 0, 0).boost(vect(bx, 0, 0)).as_list[:2]
                        for bx in boost_list])

    tprime, xprime = txprime[:, 0], txprime[:, 1]

    plt.rc('text', usetex=True)
    plt.rc('font', family='serif')
    plt.rc('font', size=22)
    plt.style.use('seaborn-white')
    label_size = 28

    plt.figure(num=1, figsize=(6, 4), dpi=100)
    plt.plot(boost_list, tprime, 'b-', markersize=12)
    plt.ylabel(r'$t^{\prime}$', fontsize=label_size)
    plt.xlabel(r'$\beta$', fontsize=label_size)
    plt.tight_layout(pad=.2)

    plt.figure(num=2, figsize=(6, 4), dpi=100)
    # plt.semilogy(boost_list, xprime, 'b-', markersize=12)
    # plt.loglog(boost_list, xprime, 'b-', markersize=12)
    plt.plot(boost_list, xprime, 'b-', markersize=12)
    plt.ylabel(r'$x^{\prime}$', fontsize=label_size)
    plt.xlabel(r'$\beta$', fontsize=label_size)
    plt.tight_layout(pad=.2)

    plt.show()

boost_test()
