/**
 * @file PointADT.cpp
 * @author Harry Fu
 * @brief Provides the PointT class definition
 * @date 3/24/2018
 */

#include "PointADT.h"

PointT::PointT(int x, int y) : xc(x), yc(y) {
    // do nothing here
}

int PointT::x() const {
    return xc;
}

int PointT::y() const {
    return yc;
}

PointT PointT::translate(int dx, int dy) const {
    return PointT(xc + dx, yc + dy);
}

bool PointT::operator==(const PointT& p) const {
    return xc == p.x() && yc == p.y();
}

bool PointT::operator!=(const PointT& p) const {
    return xc != p.x() || yc != p.y();
}

bool PointT::operator<(const PointT& p) const {
    if (yc < p.yc) {
        return true;
    }

    return (yc == p.yc && xc < p.xc);
}
