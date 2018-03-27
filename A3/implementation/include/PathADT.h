/**
 * @file PathADT.h
 * @author Harry Fu
 * @brief Provides the PathT class declaration
 * @date 3/24/2018
 */

#ifndef PATHADT_H
#define PATHADT_H

#include "PointADT.h"
#include "LineADT.h"
#include "MapTypes.h"

#include <vector>
#include <set>

/**
 * @brief PathT class
 */
class PathT {
public:
    /**
     * @brief PathT constructor
     * @details Initializes a PathT object.
     *          The constructor PathT is called for each object instance before any other access
     *          routine is called for that object. The constructor cannot be called on an existing object.
     * @param st The start point
     * @param ornt The orientation
     * @param l The length
     */
    PathT(PointT st, CompassT ornt, unsigned l);
    /**
     * @brief Appends a new segment
     * @param ornt The orientation
     * @param l The length
     * @exception invalid_argument raises for overlapped segments
     */
    void append(CompassT ornt, unsigned l);
    /**
     * @brief Gets the start point
     * @return The start point
     */
    PointT strt() const;
    /**
     * @brief Gets the end point
     * @return The end point
     */
    PointT end() const;
    /**
     * @brief Gets the segment by index
     * @param i The index
     * @return The segment (LineT object)
     * @exception outside_bounds raises for invalid index
     */
    LineT line(unsigned i) const;
    /**
     * @brief Gets the number of segments
     * @return The number of segments
     */
    unsigned size() const;
    /**
     * @brief Gets the number of points
     * @return The number of points
     */
    unsigned len() const;
    /**
     * @brief Translates the whole path by delta
     * @param dx The delta x
     * @param dy The delta y
     * @return The translated new PathT object
     */
    PathT translate(int dx, int dy) const;
private:
    /**
     * @brief vector of segments (LineT objects)
     */
    std::vector<LineT> s;
    /**
     * @brief Gets all points on a line (lineT object)
     * @param l The line
     * @return All points on the given line (PointT objects)
     */
    std::set<PointT> pointsInLine(LineT l) const;
    /**
     * @brief Gets adjacent point near the path end
     * @param ornt The orientation
     * @return The adjacent point (PointT object)
     */
    PointT adjPt(CompassT ornt) const;
};

#endif // PATHADT_H
