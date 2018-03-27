/**
 * @file LineADT.cpp
 * @author Harry Fu
 * @brief Provides the LineT class definition
 * @date 3/24/2018
 */

#include "LineADT.h"
#include "Exceptions.h"


LineT::LineT(PointT st, CompassT ornt, unsigned l) : s(st.x(), st.y()), o(ornt), L(l) {
    if (l == 0) {
        throw invalid_argument();
    }
}

PointT LineT::strt() const {
    return s;
}

PointT LineT::end() const {
    int new_x = s.x();
    int new_y = s.y();
    switch (o) {
        case W:
            new_x -= (L - 1);
            break;
        case E:
            new_x += (L - 1);
            break;
        case N:
            new_y += (L - 1);
            break;
        case S:
            new_y -= (L - 1);
            break;
    }
    return PointT(new_x, new_y);
}

CompassT LineT::orient() const {
    return o;
}

unsigned LineT::len() const {
    return L;
}

LineT LineT::flip() const {
    CompassT new_o;

    switch (o) {
        case N:
            new_o = S;
            break;
        case S:
            new_o = N;
            break;
        case W:
            new_o = E;
            break;
        case E:
            new_o = W;
            break;
    }

    return LineT(s, new_o, L);
}

LineT LineT::rotate(RotateT r) const {
    CompassT new_o;

    if (r == CW) {
        switch (o) {
            case N:
                new_o = E;
                break;
            case S:
                new_o = W;
                break;
            case W:
                new_o = N;
                break;
            case E:
                new_o = S;
                break;
        }
    } else {
        switch (o) {
            case N:
                new_o = W;
                break;
            case S:
                new_o = E;
                break;
            case W:
                new_o = S;
                break;
            case E:
                new_o = N;
                break;
        }
    }

    return LineT(s, new_o, L);
}

LineT LineT::translate(int dx, int dy) const {
    return LineT(s.translate(dx, dy), o, L);
}
