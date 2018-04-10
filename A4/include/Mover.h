/**
 * @file Mover.h
 * @author Harry Fu
 * @brief Provides the Mover class declaration
 * @date 4/6/2018
 */

#ifndef MOVER_H
#define MOVER_H

#include "Cell.h"
#include "Pile.h"
#include "Foundation.h"

/**
 * @brief Mover class
 */
class Mover {
public:
    /**
     * @brief Checks if it's valid to move a card from a pile to another pile
     * @param s The source pile
     * @param d The destination pile
     * @return True if the movement is valid
     */
    static bool chkPileToPile(Pile& s, Pile& d);
    /**
     * @brief Moves a card from a pile to another pile
     * @param s The source pile
     * @param d The destination pile
     * @return True if card is moved
     */
    static bool pileToPile(Pile& s, Pile& d);
    /**
     * @brief Checks if it's valid to move a card from a pile to a cell
     * @param s The source pile
     * @param d The destination cell
     * @return True if the movement is valid
     */
    static bool chkPileToCell(Pile& s, Cell& d);
    /**
     * @brief Moves a card from a pile to a cell
     * @param s The source pile
     * @param d The destination cell
     * @return True if card is moved
     */
    static bool pileToCell(Pile& s, Cell& d);
    /**
     * @brief Checks if it's valid to move a card from a cell to a pile
     * @param s The source cell
     * @param d The destination pile
     * @return True if the movement is valid
     */
    static bool chkCellToPile(Cell& s, Pile& d);
    /**
     * @brief Moves a card from a cell to a pile
     * @param s The source cell
     * @param d The destination pile
     * @return True if card is moved
     */
    static bool cellToPile(Cell& s, Pile& d);
    /**
     * @brief Checks if it's valid to move a card from a pile to a foundation
     * @param s The source pile
     * @param d The destination foundation
     * @return True if the movement is valid
     */
    static bool chkPileToFoundation(Pile& s, Foundation& d);
    /**
     * @brief Moves a card from a pile to a foundation
     * @param s The source pile
     * @param d The destination foundation
     * @return True if card is moved
     */
    static bool pileToFoundation(Pile& s, Foundation& d);
    /**
     * @brief Checks if it's valid to move a card from a foundation to a pile
     * @param s The source foundation
     * @param d The destination pile
     * @return True if the movement is valid
     */
    static bool chkFoundationToPile(Foundation& s, Pile& d);
    /**
     * @brief Moves a card from a foundation to a pile
     * @param s The source foundation
     * @param d The destination pile
     * @return True if card is moved
     */
    static bool foundationToPile(Foundation& s, Pile& d);
    /**
     * @brief Checks if it's valid to move a card from a cell to a foundation
     * @param s The source cell
     * @param d The destination foundation
     * @return True if the movement is valid
     */
    static bool chkCellToFoundation(Cell& s, Foundation& d);
    /**
     * @brief Moves a card from a cell to a foundation
     * @param s The source cell
     * @param d The destination foundation
     * @return True if card is moved
     */
    static bool cellToFoundation(Cell& s, Foundation& d);
    /**
     * @brief Checks if it's valid to move a card from a foundation to a cell
     * @param s The source foundation
     * @param d The destination cell
     * @return True if the movement is valid
     */
    static bool chkFoundationToCell(Foundation& s, Cell& d);
    /**
     * @brief Moves a card from a foundation to a cell
     * @param s The source foundation
     * @param d The destination cell
     * @return True if card is moved
     */
    static bool foundationToCell(Foundation& s, Cell& d);
private:
};

#endif