/**
 * @file Seq2D.h
 * @author Harry Fu
 * @brief Provides the Seq2D template class
 * @date 3/24/2018
 */

#ifndef SEQ2D_H
#define SEQ2D_H

#include "Exceptions.h"
#include "LineADT.h"
#include "MapTypes.h"
#include "PathADT.h"
#include "PointADT.h"

#include <list>
#include <set>
#include <vector>

/**
 * @brief Seq2D class
 */
template <class T>
class Seq2D {
   public:
    /**
     * @brief PointT constructor
     * @details Initializes a PointT object.
     *          The Seq2D(T) constructor is called for each object instance before any other access
     *          routine is called for that object. The constructor can only be called once.
     *          Assume that the input to the constructor is a sequence of rows, where each row is
     *          a sequence of elements of type T. The number of columns (number of elements) in
     *          each row is assumed to be equal. That is each row of the grid has the same number
     *          of entries. s[i][j] means the ith row and the jth column. The 0th row is at the
     *          bottom of the map and the 0th column is at the leftmost side of the map.
     * @param s The grid
     * @param scale The scale
     */
    Seq2D(std::vector<std::vector<T>> s, double scale);
    /**
     * @brief Sets value to point on grid
     * @param p The point
     * @param v The value
     * @exception outside_bounds raises for invalid point
     */
    void set(PointT p, T v);
    /**
     * @brief Gets value from point on grid
     * @param p The point
     * @return The value from point on grid
     * @exception outside_bounds raises for invalid point 
     */
    T get(PointT p) const;
    /**
     * @brief Gets the number of rows of grid
     * @return The number of rows of grid
     */
    unsigned getNumRow() const;
    /**
     * @brief Gets the number of columns of grid
     * @return The number of columns of grid
     */
    unsigned getNumCol() const;
    /**
     * @brief Gets the scale of grid
     * @return The scale of grid
     */
    double getScale() const;
    /**
     * @brief Counts the given value in grid
     * @param t The value
     * @return The number of occurances of the given value in grid
     */
    unsigned count(T t) const;
    /**
     * @brief Counts a certain value on line
     * @param l The line
     * @param t The value
     * @return The number of occurances of a certain value on line
     * @exception invalid_argument raises for the given line is not completely inside the grid
     */
    unsigned count(LineT l, T t) const;
    /**
     * @brief Counts a certain value on path
     * @param p The path
     * @param t The value
     * @return The number of occurances of a certain value on path
     * @exception invalid_argument raises for the given path is not completely inside the grid
     */
    unsigned count(PathT p, T t) const;
    /**
     * @brief Gets the length of the given path by considering the scale
     * @param pth The path
     * @return The length of the given path by considering the scale
     * @exception invalid_argument raises for the given path is not completely inside the grid
     */
    double length(PathT pth) const;
    /**
     * @brief Checks if two points are connected
     * @param p1 The first point
     * @param p2 The second point
     * @return True if a path exits between two points and all points of this path have the same value
     * @exception invalid_argument raises for at least one point is not inside the grid
     */
    bool connected(PointT p1, PointT p2) const;

   private:
    /**
     * @brief 2D grid
     */
    std::vector<std::vector<T>> S;
    /**
     * @brief scale
     */
    double scl;
    /**
     * @brief number of columns
     */
    unsigned nCol;
    /**
     * @brief number of rows
     */
    unsigned nRow;

    /**
     * @brief Checks if the given row is valid
     * @param i The row
     * @return True for valid row otherwise false
     */
    bool validRow(unsigned i) const;
    /**
     * @brief Checks if the given column is valid
     * @param i The column
     * @return True for valid column otherwise false
     */
    bool validCol(unsigned i) const;
    /**
     * @brief Checks if the given point is inside the grid
     * @param p The point
     * @return True for point inside the grid otherwise false
     */
    bool validPoint(PointT p) const;
    /**
     * @brief Checks if the given line is inside the grid
     * @param l The line
     * @return True for line inside the grid otherwise false
     */
    bool validLine(LineT l) const;
    /**
     * @brief Checks if the given path is inside the grid
     * @param pth The path
     * @return True for path inside the grid otherwise false
     */
    bool validPath(PathT pth) const;
    /**
     * @brief Gets all points on a line
     * @param l The line
     * @return All points on the given line
     */
    std::set<PointT> pointsInLine(LineT l) const;
    /**
     * @brief Gets all points on a path
     * @param pth The path
     * @return All points on the given path
     */
    std::set<PointT> pointsInPath(PathT pth) const;
};

template <class T>
Seq2D<T>::Seq2D(std::vector<std::vector<T>> s, double scale)
    : S(s), scl(scale), nRow(s.size()) {
    if (scl <= 0 || nRow == 0) {
        throw invalid_argument();
    }

    nCol = S[0].size();
    if (nCol == 0) {
        throw invalid_argument();
    }

    for (auto it = S.begin(); it != S.end(); ++it) {
        if (it->size() != nCol) {
            throw invalid_argument();
        }
    }
}

template <class T>
void Seq2D<T>::set(PointT p, T v) {
    if (!validPoint(p)) {
        throw outside_bounds();
    }

    S[p.y()][p.x()] = v;
}

template <class T>
T Seq2D<T>::get(PointT p) const {
    if (!validPoint(p)) {
        throw outside_bounds();
    }

    return S[p.y()][p.x()];
}

template <class T>
unsigned Seq2D<T>::getNumRow() const {
    return nRow;
}

template <class T>
unsigned Seq2D<T>::getNumCol() const {
    return nCol;
}

template <class T>
double Seq2D<T>::getScale() const {
    return scl;
}

template <class T>
unsigned Seq2D<T>::count(T t) const {
    unsigned cnt = 0;

    for (auto it = S.begin(); it != S.end(); ++it) {
        for (auto it_ = it->begin(); it_ != it->end(); ++it_) {
            if (*it_ == t) {
                ++cnt;
            }
        }
    }

    return cnt;
}

template <class T>
unsigned Seq2D<T>::count(LineT l, T t) const {
    unsigned cnt = 0;

    std::set<PointT> pts = pointsInLine(l);

    for (auto it = pts.begin(); it != pts.end(); ++it) {
        if (validPoint(*it) && S[it->y()][it->x()] == t) {
            ++cnt;
        }
    }

    return cnt;
}

template <class T>
unsigned Seq2D<T>::count(PathT pth, T t) const {
    unsigned cnt = 0;

    std::set<PointT> pts = pointsInPath(pth);

    for (auto it = pts.begin(); it != pts.end(); ++it) {
        if (validPoint(*it) && S[it->y()][it->x()] == t) {
            ++cnt;
        }
    }

    return cnt;
}

template <class T>
double Seq2D<T>::length(PathT pth) const {
    if (!validPath(pth)) {
        throw invalid_argument();
    }

    return pth.len() * scl;
}

template <class T>
bool Seq2D<T>::connected(PointT p1, PointT p2) const {
    if (!validPoint(p1) || !validPoint(p2)) {
        throw invalid_argument();
    }

    T t = S[p1.y()][p1.x()];

    if (S[p2.y()][p2.x()] != t) {
        return false;
    }

    std::vector<std::vector<bool>> visited(nRow,
                                           std::vector<bool>(nCol, false));

    std::list<PointT> que(1, p1);

    while (!que.empty()) {
        PointT p = que.front();
        que.pop_front();
        int x = p.x();
        int y = p.y();
        if (S[y][x] != t || visited[y][x]) {
            continue;
        }
        visited[y][x] = true;
        if (p == p2) {
            return true;
        }
        if (validCol(x - 1)) {
            que.push_back(p.translate(-1, 0));
        }
        if (validCol(x + 1)) {
            que.push_back(p.translate(1, 0));
        }
        if (validRow(y - 1)) {
            que.push_back(p.translate(0, -1));
        }
        if (validRow(y + 1)) {
            que.push_back(p.translate(0, 1));
        }
    }

    return false;
}

template <class T>
bool Seq2D<T>::validRow(unsigned i) const {
    return i < nRow;
}

template <class T>
bool Seq2D<T>::validCol(unsigned i) const {
    return i < nCol;
}

template <class T>
bool Seq2D<T>::validPoint(PointT p) const {
    return p.y() > -1 && validRow(p.y()) && p.x() > -1 && validCol(p.x());
}

template <class T>
bool Seq2D<T>::validLine(LineT l) const {
    std::set<PointT> pts = pointsInLine(l);
    for (auto it = pts.begin(); it != pts.end(); ++it) {
        if (!validPoint(*it)) {
            return false;
        }
    }
    return true;
}

template <class T>
bool Seq2D<T>::validPath(PathT pth) const {
    std::set<PointT> pts = pointsInPath(pth);
    for (auto it = pts.begin(); it != pts.end(); ++it) {
        if (!validPoint(*it)) {
            return false;
        }
    }
    return true;
}

template <class T>
std::set<PointT> Seq2D<T>::pointsInLine(LineT l) const {
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
        case CompassT::S:
            fac_dy = -1;
            break;
    }

    std::set<PointT> pts;

    for (unsigned i = 0; i < l.len(); ++i) {
        int dx = fac_dx * i;
        int dy = fac_dy * i;
        pts.insert(l.strt().translate(dx, dy));
    }

    return pts;
}

template <class T>
std::set<PointT> Seq2D<T>::pointsInPath(PathT p) const {
    std::set<PointT> pts;

    for (unsigned i = 0; i < p.size(); ++i) {
        LineT l = p.line(i);
        std::set<PointT> pts_ = pointsInLine(l);
        pts.insert(pts_.begin(), pts_.end());
    }

    return pts;
}

#endif  // SEQ2D_H
