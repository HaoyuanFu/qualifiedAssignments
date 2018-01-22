## @file testSeqs.py
#  @author Haoyuan(Harry) Fu
#  @brief Provides the testcase suite for SeqADT.py and CurveADT.py
#  @date 1/22/2018

from SeqADT import SeqT
from CurveADT import CurveT

# for testing floating point equality after arithmetic
# from Python development documentation:
#   https://www.python.org/dev/peps/pep-0485/#proposed-implementation
#       I used this web to check my polynomial data: https://arachnoid.com/polysolve/
def isClose(a, b, rel_tol = 1e-09, abs_tol = 0.0):
    return abs(a - b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)

# @brief Tests the add method of the SeqT ADT class
# @details Checks if the SeqT.add method works with
#          the assumption that the SeqT.get method works fine
def test_SeqT_add():
    try:
        seq = SeqT()
        seq.add(0, 10.0)
        assert seq.get(0) == 10.0
        seq.add(0, 20.0)
        assert (seq.get(0) == 20.0 and seq.get(1) == 10.0)
        seq.add(1, 30.0)
        assert (seq.get(0) == 20.0 and seq.get(1) == 30.0 and
                seq.get(2) == 10.0)
        seq.add(3, 40.0)
        assert (seq.get(0) == 20.0 and seq.get(1) == 30.0 and
                seq.get(2) == 10.0 and seq.get(3) == 40.0)
        try:
            seq.add(-1, 50.0)
            raise AssertionError
        except IndexError:
            pass
        try:
            seq.add(5, 50.0)
            raise AssertionError
        except IndexError:
            pass
        print('test of SeqT.add PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of SeqT.add FAILED.')


# @brief Tests the rm method of the SeqT ADT class
# @details Checks if the SeqT.rm method works with
#          the assumption that the SeqT.get and SeqT.add method works fine
def test_SeqT_rm():
    try:
        seq = SeqT()
        seq.add(0, 10.0)
        seq.add(1, 20.0)
        seq.add(2, 30.0)
        seq.add(3, 40.0)
        seq.rm(0)
        seq.rm(2)
        assert (seq.get(0) == 20.0 and seq.get(1) == 30.0)
        try:
            seq.rm(-1)
            raise AssertionError
        except IndexError:
            pass
        try:
            seq.rm(2)
            raise AssertionError
        except IndexError:
            pass
        print('test of SeqT.rm PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of SeqT.rm FAILED.')


# @brief Tests the set method of the SeqT ADT class
# @details Checks if the SeqT.set method works with
#          the assumption that the SeqT.get and SeqT.add method works fine
def test_SeqT_set():
    try:
        seq = SeqT()
        seq.add(0, 10.0)
        seq.add(1, 20.0)
        seq.add(2, 30.0)
        seq.add(3, 40.0)
        seq.set(0, 50.0)
        seq.set(3, 60.0)
        assert (seq.get(0) == 50.0 and seq.get(3) == 60.0)
        try:
            seq.set(-1, 70.0)
            raise AssertionError
        except IndexError:
            pass
        try:
            seq.set(4, 80.0)
            raise AssertionError
        except IndexError:
            pass
        print('test of SeqT.set PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of SeqT.set FAILED.')


# @brief Tests the get method of the SeqT ADT class
# @details Checks if the SeqT.get method works with
#          the assumption that the SeqT.add method works fine
def test_SeqT_get():
    try:
        seq = SeqT()
        try:
            seq.get(0)
            raise AssertionError
        except IndexError:
            pass
        seq.add(0, 10.0)
        seq.add(1, 20.0)
        seq.add(2, 30.0)
        seq.add(3, 40.0)
        assert (seq.get(0) == 10.0 and seq.get(3) == 40.0)
        try:
            seq.get(-1)
            raise AssertionError
        except IndexError:
            pass
        try:
            seq.get(4)
            raise AssertionError
        except IndexError:
            pass
        print('test of SeqT.get PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of SeqT.get FAILED.')


# @brief Tests the size method of the SeqT ADT class
# @details Checks if the SeqT.size method works with
#          the assumption that the SeqT.add amd SeqT.rm method works fine
def test_SeqT_size():
    try:
        seq = SeqT()
        assert seq.size() == 0
        seq.add(0, 10.0)
        seq.add(1, 20.0)
        seq.add(2, 30.0)
        seq.add(3, 40.0)
        assert seq.size() == 4
        seq.rm(0)
        seq.rm(0)
        seq.rm(0)
        seq.rm(0)
        print('test of SeqT.size PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of SeqT.size FAILED.')


# @brief Tests the indexInSeq method of the SeqT ADT class
# @details Checks if the SeqT.indexInSeq method works with
#          the assumption that the SeqT.add method works fine
def test_SeqT_indexInSeq():
    try:
        seq = SeqT()
        seq.add(0, 10.0)
        seq.add(1, 20.0)
        seq.add(2, 30.0)
        seq.add(3, 40.0)
        assert (seq.indexInSeq(15.0) == 0 and seq.indexInSeq(25.0) == 1 and
                seq.indexInSeq(35.0) == 2)
        assert (seq.indexInSeq(10.000001) == 0 and seq.indexInSeq(20.000001) == 1 and
                seq.indexInSeq(30.000001) == 2)
        assert (seq.indexInSeq(19.999999) == 0 and seq.indexInSeq(29.999999) == 1 and
                seq.indexInSeq(39.000000) == 2)
        try:
            seq.indexInSeq(0.0)
            raise AssertionError
        except ValueError:
            pass
        try:
            seq.indexInSeq(50.0)
            raise AssertionError
        except ValueError:
            pass
        print('test of SeqT.indexInSeq PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of SeqT.indexInSeq FAILED.')


# @brief Tests the linVal method of the CurveT ADT class
# @details Checks if the CurveT.linVal method works with
#          a temporary date file generated on the fly
def test_CurveT_linVal():
    with open('tmp_file', 'w') as f:
        f.write('\n'.join([
            '1.0, 10.0',
            '2.0, 20.0',
            '3.0, 30.0',
            '4.0, 40.0',
            '5.0, 50.0'
        ]))
    try:
        curve = CurveT('tmp_file')
        assert (isClose(curve.linVal(1.5), 15.0) and
                isClose(curve.linVal(2.5), 25.0) and
                isClose(curve.linVal(3.5), 35.0))
        assert (isClose(curve.linVal(1.001), 10.01) and
                isClose(curve.linVal(2.001), 20.01) and
                isClose(curve.linVal(3.001), 30.01))
        assert (isClose(curve.linVal(1.999), 19.99) and
                isClose(curve.linVal(2.999), 29.99) and
                isClose(curve.linVal(3.999), 39.99))
        try:
            curve.linVal(0.5)
            raise AssertionError
        except ValueError:
            pass
        try:
            curve.linVal(5.5)
            raise AssertionError
        except ValueError:
            pass
        print('test of CurveT.linVal PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of CurveT.linVal FAILED.')


# @brief Tests the quadVal method of the CurveT ADT class
# @details Checks if the CurveT.quadVal method works with
#          a temporary date file generated on the fly
def test_CurveT_quadVal():
    with open('tmp_file', 'w') as f:
        f.write('\n'.join([
            '1.0, 5.0',
            '2.0, 20.0',
            '3.0, 25.0',
            '4.0, 40.0',
            '5.0, 41.0'
        ]))
    try:
        curve = CurveT('tmp_file')
        assert (isClose(curve.quadVal(1.5), 13.75) and
                isClose(curve.quadVal(2.5), 23.75) and
                isClose(curve.quadVal(3.5), 31.25))
        assert (isClose(curve.quadVal(1.01), 5.1995) and
                isClose(curve.quadVal(2.01), 20.0995) and
                isClose(curve.quadVal(3.01), 25.1005))
        assert (isClose(curve.quadVal(1.99), 19.8995) and
                isClose(curve.quadVal(2.99), 24.9995) and
                isClose(curve.quadVal(3.99), 39.8005))
        try:
            curve.quadVal(0.5)
            raise AssertionError
        except ValueError:
            pass
        try:
            curve.quadVal(5.5)
            raise AssertionError
        except ValueError:
            pass
        print('test of CurveT.quadVal PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of CurveT.quadVal FAILED.')

    with open('tmp_file', 'w') as f:
        f.write('\n'.join([
            '1.0, 5.0',
            '2.0, 20.0'
        ]))
    try:
        curve = CurveT('tmp_file')
        try:
            curve.quadVal(1.5)
            raise AssertionError
        except ValueError as e:
            pass
        print('test of CurveT.quadVal PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of CurveT.quadVal FAILED.')


# @brief Tests the npolyVal method of the CurveT ADT class
# @details Checks if the CurveT.npolyVal method works with
#          a temporary date file generated on the fly
def test_CurveT_npolyVal():
    with open('tmp_file', 'w') as f:
        f.write('\n'.join([
            '1.0, 10.0',
            '2.0, 20.0',
            '3.0, 50.0',
            '4.0, 30.0',
            '5.0, 10.0'
        ]))
    try:
        curve = CurveT('tmp_file')
        assert (isClose(curve.npolyVal(1, 1.5), 22.5) and
                isClose(curve.npolyVal(1, 2.5), 23.5) and
                isClose(curve.npolyVal(1, 3.5), 24.5))
        assert (isClose(curve.npolyVal(2, 1.5), 20.5357143) and
                isClose(curve.npolyVal(2, 2.5), 37.25) and
                isClose(curve.npolyVal(2, 3.5), 38.25))
        assert (isClose(curve.npolyVal(3, 1.5), 17.66071429) and
                isClose(curve.npolyVal(3, 2.5), 34.625) and
                isClose(curve.npolyVal(3, 3.5), 40.875))
        print('test of CurveT.npolyVal PASSED.')
    except (AssertionError, ValueError, IndexError):
        print('test of CurveT.npolyVal FAILED.')


test_SeqT_add()
test_SeqT_rm()
test_SeqT_set()
test_SeqT_get()
test_SeqT_size()
test_SeqT_indexInSeq()

test_CurveT_linVal()
test_CurveT_quadVal()
test_CurveT_npolyVal()
