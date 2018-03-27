/**
 * @file LineADT.h
 * @author Harry Fu
 * @brief Provides the LineT class declaration
 * @date 3/24/2018
 */

#ifndef LINEADT_H
#define LINEADT_H

#include "PointADT.h"
#include "MapTypes.h"

/**
 * @brief LineT class
 */
class LineT {
public:
    /**
     * @brief LineT constructor
     * @details Initializes a LineT object.
     *          The constructor LineT is called for each object instance before any other access routine
     *          is called for that object. The constructor cannot be called on an existing object.
     * @param st The start point
     * @param ornt The orientation
     * @param l The length
     * @exception invalid_argument raises for any invalid argument
     */
    LineT(PointT st, CompassT ornt, unsigned l);
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
     * @brief Gets the orientation
     * @return The orientation
     */
    CompassT orient() const;
    /**
     * @brief Gets the length
     * @return The length
     */
    unsigned len() const;
    /**
     * @brief Create a new LineT object with flipping
     * @return The flipped new LineT object
     */
    LineT flip() const;
    /**
     * @brief Create a new LineT object with rotation
     * @param r The rotation
     * @return The rotated new LineT object
     */
    LineT rotate(RotateT r) const;
    /**
     * @brief Create a new LineT object with translation
     * @param dx The delta x
     * @param dy The delta y
     * @return The translated new LineT object
     */
    LineT translate(int dx, int dy) const;
private:
    /**
     * @brief start point
     */
    PointT s;
    /**
     * @brief orientation
     */
    CompassT o;
    /**
     * @brief length
     */
    unsigned L;
};

#endif // LINEADT_H
