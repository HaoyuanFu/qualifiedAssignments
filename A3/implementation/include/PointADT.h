/**
 * @file PointADT.h
 * @author Harry Fu
 * @brief Provides the PointT class declaration
 * @date 3/24/2018
 */

#ifndef POINTADT_H
#define POINTADT_H

/**
 * @brief PointT class
 */
class PointT {
public:
    /**
     * @brief PointT constructor
     * @details Initializes a PointT object.
     *          The constructor PointT is called for each object instance before any other access routine
     *          is called for that object. The constructor cannot be called on an existing object.
     * @param x The x coordinate
     * @param y The y coordinate
     */
    PointT(int x, int y);
    /**
     * @brief Gets the x coordinate
     * @return The x coordinate
     */
    int x() const;
    /**
     * @brief Gets the y coordinate
     * @return The y coordinate
     */
    int y() const;
    /**
     * @brief Translates by delta
     * @param dx The delta x
     * @param dy The delta y
     * @return The translated point
     */
    PointT translate(int dx, int dy) const;
    /**
     * @brief == operator
     * @param p Another PointT object
     * @return True if the coordinates are the same
     *         as another PointT object has
     */
    bool operator==(const PointT& p) const;
    /**
     * @brief != operator
     * @param p Another PointT object
     * @return True if the coordinates are not the same
     *         as another PointT object has
     */
    bool operator!=(const PointT& p) const;
    /**
     * @brief < operator
     * @param p Another PointT object
     * @return True if the y coordinate is less than another PointT
     *         object's, or the y coordinates are the same but the y
     *         coordinate is less than another PointT oject's, otherwise
     *         false
     */
    bool operator<(const PointT& p) const;
private:
    /**
     * @brief x coordinate
     */
    int xc;
    /**
     * @brief y coordinate
     */
    int yc;
};

#endif // POINTADT_H
