## @file test_All.py
#  @author Harry Fu
#  @brief Provides the Pytest cases
#  @date 2/14/2018


import pytest
import random
from SeqServices import *
from CurveADT import CurveT
from Data import Data
from Exceptions import *


def test_SeqServices_isAscending():
    for X, result in (
        ([0.1, 0.1], True),
        ([0.1, 0.2], True),
        ([0.1, 0.0], False),
        ([2.3, 2.4, 2.4], True),
        ([2.3, 2.3, 2.4], True),
        ([2.4, 2.4, 2.4], True),
        ([2.4, 2.5, 2.4], False),
        ([2.5, 2.4, 2.4], False),
        ([2.5, 2.5, 2.4], False),
    ):
        assert isAscending(X) is result


def test_SeqServices_isInBounds():
    for X, x, result in (
        ([0.3, 0.3], 0.3, True),
        ([0.3, 0.3], 0.2, False),
        ([0.3, 0.3], 0.4, False),
        ([2.4, 2.4, 2.4], 2.4, True),
        ([2.4, 2.4, 2.5], 2.5, True),
        ([2.4, 2.5, 2.5], 2.4, True),
        ([2.4, 2.5, 2.5], 2.5, True),
        ([2.4, 2.5, 2.5], 2.45, True),
        ([2.4, 2.5, 2.5], 2.3, False),
        ([2.4, 2.5, 2.5], 2.6, False),
    ):
        assert isInBounds(X, x) is result


def test_SeqServices_interpLin():
    for x1, y1, x2, y2, x, y in (
        (0, 1, 1, 3, 0, 1),
        (0, 1, 1, 3, 1, 3),
        (0, 1, 1, 3, 0.5, 2),
    ):
        assert abs(interpLin(x1, y1, x2, y2, x) - y) < 1e-6


def test_SeqServices_interpQuad():
    for x0, y0, x1, y1, x2, y2, x, y in (
        (-1.0, 0.0, 0.0, 1.0, 1.0, 3.0, -1.0, 0.0),
        (-1.0, 0.0, 0.0, 1.0, 1.0, 3.0, 0.0, 1.0),
        (-1.0, 0.0, 0.0, 1.0, 1.0, 3.0, 1.0, 3.0),
        (-1.0, 0.0, 0.0, 1.0, 1.0, 3.0, -0.5, 0.375),
        (-1.0, 0.0, 0.0, 1.0, 1.0, 3.0, 0.5, 1.875),
    ):
        assert abs(interpQuad(x0, y0, x1, y1, x2, y2, x) - y) < 1e-6


def test_SeqServices_index():
    for X, x, i in (
        ([0, 1, 2, 3], 0, 0),
        ([0, 1, 2, 3], 0.5, 0),
        ([0, 1, 2, 3], 0.9, 0),
        ([0, 1, 2, 3], 2, 2),
        ([0, 1, 2, 3], 2.5, 2),
        ([0, 1, 2, 3], 2.9, 2),
    ):
        assert index(X, x) == i


def test_CurveT_init():
    for X, Y, i, exp in (
        ([1, 2], [3, 4], 1, None),
        ([2, 1], [1, 1], 1, IndepVarNotAscending),
        ([1, 1, 3], [1, 1], 1, SeqSizeMismatch),
        ([1, 1], [1, 1, 1], 1, SeqSizeMismatch),
        ([1, 2], [1, 1], 0, InvalidInterpOrder),
        ([1, 2], [1, 1], 3, InvalidInterpOrder),
    ):
        if exp:
            with pytest.raises(exp):
                CurveT(X, Y, i)
        else:
            try:
                CurveT(X, Y, i)
            except Exception:
                pytest.fail('Must have no exceptions')


def test_CurveT_minD():
    X = [0.4, 1.8, 2.5, 3.1]
    Y = [1, 1, 1, 1]
    assert CurveT(X, Y, 1).minD() == 0.4
    assert CurveT(X, Y, 2).minD() == 0.4
    X = [1, 1, 1, 1]
    assert CurveT(X, Y, 1).minD() == 1
    assert CurveT(X, Y, 2).minD() == 1


def test_CurveT_maxD():
    X = [0.4, 1.8, 2.5, 3.1]
    Y = [1, 1, 1, 1]
    assert CurveT(X, Y, 1).maxD() == 3.1
    assert CurveT(X, Y, 2).maxD() == 3.1
    X = [1, 1, 1, 1]
    assert CurveT(X, Y, 1).maxD() == 1
    assert CurveT(X, Y, 2).maxD() == 1


def test_CurveT_order():
    X = [0, 1]
    Y = [1, 1]
    assert CurveT(X, Y, 1).order() == 1
    assert CurveT(X, Y, 2).order() == 2


def test_CurveT_eval():
    X = [0, 1]
    Y = [2, 0]
    s = CurveT(X, Y, 1)
    with pytest.raises(OutOfDomain):
        s.eval(-1.0)
    with pytest.raises(OutOfDomain):
        s.eval(2.0)
    assert s.eval(0.0) == 2.0
    assert s.eval(0.5) == 1.0
    X = [-1, 0, 1]
    Y = [0, 1, 3]
    s = CurveT(X, Y, 2)
    with pytest.raises(OutOfDomain):
        s.eval(-2.0)
    with pytest.raises(OutOfDomain):
        s.eval(4.0)
    assert s.eval(-0.5) == 0.375
    assert s.eval(0.0) == 1.0
    assert s.eval(0.5) == 1.875


def test_CurveT_dfdx():
    X = [0, 1]
    Y = [2, 0]
    s = CurveT(X, Y, 1)
    with pytest.raises(OutOfDomain):
        s.dfdx(-1.0)
    with pytest.raises(OutOfDomain):
        s.dfdx(2.0)
    assert abs(s.dfdx(0.0) - -2.0) < 1e-6
    assert abs(s.dfdx(0.5) - -2.0) < 1e-6
    X = [-1, 0, 1]
    Y = [0, 1, 3]
    s = CurveT(X, Y, 2)
    with pytest.raises(OutOfDomain):
        s.eval(-2.0)
    with pytest.raises(OutOfDomain):
        s.eval(4.0)
    assert abs(s.dfdx(0.0) - 1.5005) < 1e-6
    assert abs(s.dfdx(0.5) - 2.0005) < 1e-6


def test_CurveT_d2fdx2():
    X = [0, 1]
    Y = [2, 0]
    s = CurveT(X, Y, 1)
    with pytest.raises(OutOfDomain):
        s.d2fdx2(-1.0)
    with pytest.raises(OutOfDomain):
        s.d2fdx2(2.0)
    assert s.d2fdx2(0.0) == 0.0
    assert s.d2fdx2(0.5) == 0.0
    X = [-1, 0, 1]
    Y = [0, 1, 3]
    s = CurveT(X, Y, 2)
    with pytest.raises(OutOfDomain):
        s.eval(-2.0)
    with pytest.raises(OutOfDomain):
        s.eval(4.0)
    assert abs(s.d2fdx2(0.0) - 1.0) < 1e-6
    assert abs(s.d2fdx2(0.5) - 1.0) < 1e-6


def test_Data_init():
    Data.init()
    with pytest.raises(InvalidIndex):
        Data.getC(0)
    Data.add(CurveT([0, 1], [2, 0], 1), -1.0)
    Data.getC(0)
    Data.init()
    with pytest.raises(InvalidIndex):
        Data.getC(0)


def test_Data_add():
    Data.init()
    Data.add(CurveT([0, 1], [2, 0], 1), -1.0)
    with pytest.raises(IndepVarNotAscending):
        Data.add(CurveT([0, 1], [2, 0], 1), -1.0)
    for z in range(9):
        Data.add(CurveT([-1, 0, 1], [0, 1, 3], 2), z)
    with pytest.raises(Full):
        Data.add(CurveT([-1, 0, 1], [0, 1, 3], 2), z)
    assert (Data.getC(0).minD() == 0.0 and Data.getC(
        0).maxD() == 1.0 and Data.getC(0).order() == 1)
    assert (Data.getC(1).minD() == -1.0 and Data.getC(
        1).maxD() == 1.0 and Data.getC(1).order() == 2)
    assert (Data.getC(9).minD() == -1.0 and Data.getC(
        9).maxD() == 1.0 and Data.getC(9).order() == 2)


def test_Data_getC():
    Data.init()
    X = [0.0, 1.0]
    Y = [0.0, 10.0]
    z = 0.0
    Orders = []
    for i in range(10):
        X.append(X[-1] + 1.0)
        Y.append(Y[-1] ** .5 + 10.0)
        z += 0.1
        o = random.randint(1, 2)
        Orders.append(o)
        Data.add(CurveT(list(X), list(Y), o), z)
    for i in range(10):
        s = Data.getC(i)
        assert (s.minD() == 0.0 and
                s.maxD() == X[i + 2] and
                s.order() == Orders[i])
    with pytest.raises(InvalidIndex):
        Data.getC(-1)
    with pytest.raises(InvalidIndex):
        Data.getC(10)


def test_Data_eval():
    Data.init()
    X = [0.0, 1.0]
    Y = [0.0, 10.0]
    z = 0.0
    for i in range(10):
        X.append(X[-1] + 1.0)
        Y.append(Y[-1] + 10.0)
        z += 0.1
        Data.add(CurveT(list(X), list(Y), 1), z)
    with pytest.raises(OutOfDomain):
        Data.eval(0.0, 0.0)
    with pytest.raises(OutOfDomain):
        Data.eval(0.0, 1.0)
    z = 0.0
    for x in range(9):
        z += 0.1
        assert Data.eval(x, z) == Y[x]
        assert Data.eval(x + 0.5, z) == Y[x] + 5.0
    Data.init()
    X = [0.0, 1.0]
    Y = [0.0, 10.0]
    z = 0.0
    for i in range(10):
        X.append(X[-1] + 1.0)
        Y.append(Y[-1] ** .5 + 10.0)
        z += 0.1
        Data.add(CurveT(list(X), list(Y), 2), z)
    with pytest.raises(OutOfDomain):
        Data.eval(0.0, 0.0)
    with pytest.raises(OutOfDomain):
        Data.eval(0.0, 1.0)
    z = 0.0
    delta = 999999
    Y_ = []
    for x in range(9):
        z += 0.1
        assert Data.eval(x, z) == Y[x]
        delta_ = Data.eval(x + 0.5, z) - Y[x]
        assert delta_ < delta
        delta = delta_
        Y_.append(Data.eval(x + 0.5, z))
    assert delta < 1e-5
    Y_expected = [5.854715, 12.435854, 13.732203,
                  13.710058, 13.702791, 13.701730,
                  13.701585, 13.701565, 13.701563]
    for y_, y_expected in zip(Y_, Y_expected):
        assert abs(y_ - y_expected) < 1e-6


def test_Data_slice():
    Data.init()
    X = [i * 1.0 for i in range(10)]
    Y = [i ** 0.5 * 10.0 for i in range(10)]
    z = [i ** 2 for i in range(10)]

    for i in range(10):
        Data.add(CurveT(list(X), list(Y), 1), z[i])
        Y = [y + 5.0 for y in Y]
    s = Data.slice(0.0, 1)
    assert (s.minD() == 0.0 and
            s.maxD() == 81.0 and
            s.order() == 1)
    assert s.eval(0.0) == 0.0
    assert s.eval(64.0) == 40.0

    s = Data.slice(8.0, 2)
    assert (s.minD() == 0.0 and
            s.maxD() == 81.0 and
            s.order() == 2)
    assert abs(s.eval(1.0) - 33.284271) < 1e-6
    assert abs(s.eval(64.0) - 68.284271) < 1e-6
