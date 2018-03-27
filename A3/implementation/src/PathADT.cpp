/**
 * @file PathADT.cpp
 * @author Harry Fu
 * @brief Provides the PathT class definition
 * @date 3/24/2018
 */

#include "PathADT.h"
#include "Exceptions.h"

#include <algorithm>

using namespace std;

PathT::PathT(PointT st, CompassT ornt, unsigned l) {
    s.push_back(LineT(st, ornt, l));
}

void PathT::append(CompassT ornt, unsigned l) {
    LineT ll(adjPt(ornt), ornt, l);

    set<PointT> pts1 = pointsInLine(ll);

    set<PointT> pts2;
    for (auto it = s.begin(); it != s.end(); ++it) {
        set<PointT> pts = pointsInLine(*it);
        pts2.insert(pts.begin(), pts.end());
    }

    set<PointT> common;
    set_intersection(pts1.begin(), pts1.end(), pts2.begin(), pts2.end(),
                     inserter(common, common.begin()));

    if (!common.empty()) {
        throw invalid_argument();
    }

    s.push_back(LineT(ll));
}

PointT PathT::strt() const { return s[0].strt(); }

PointT PathT::end() const { return s.back().end(); }

LineT PathT::line(unsigned i) const {
    if (i > s.size() - 1) {
        throw outside_bounds();
    }
    return s[i];
}

unsigned PathT::size() const { return s.size(); }

unsigned PathT::len() const {
    unsigned l = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
        l += it->len();
    }
    return l;
}

PathT PathT::translate(int dx, int dy) const {
    LineT ll = s[0];
    PathT p(ll.strt().translate(dx, dy), ll.orient(), ll.len());

    for (auto it = s.begin() + 1; it != s.end(); ++it) {
        p.append(it->orient(), it->len());
    }

    return p;
}

set<PointT> PathT::pointsInLine(LineT l) const {
    int fac_dx = 0;
    int fac_dy = 0;

    switch (l.orient()) {
        case W:
            fac_dx = -1;
            break;
        case E:
            fac_dx = 1;
            break;
        case N:
            fac_dy = 1;
            break;
        case S:
            fac_dy = -1;
            break;
    }

    set<PointT> pts;

    for (int i = 0; i < l.len(); ++i) {
        int dx = fac_dx * i;
        int dy = fac_dy * i;
        pts.insert(l.strt().translate(dx, dy));
    }

    return pts;
}

PointT PathT::adjPt(CompassT ornt) const {
    int dx = 0;
    int dy = 0;

    switch (ornt) {
        case N:
            dy = 1;
            break;
        case S:
            dy = -1;
            break;
        case W:
            dx = -1;
            break;
        case E:
            dx = 1;
            break;
    }

    return s.back().end().translate(dx, dy);
}
