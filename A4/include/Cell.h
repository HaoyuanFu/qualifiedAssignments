/**
 * @file Cell.h
 * @author Harry Fu
 * @brief Provides the Cell class declaration
 * @date 4/6/2018
 */

#ifndef CELL_H
#define CELL_H

#include "Card.h"

/**
 * @brief Cell class
 */
class Cell {
public:
    /**
     * @brief Cell constructor
     */
    Cell();
    /**
     * @brief Checks if cell is empty
     * @return True if cell is empty
     */
    bool empty() const;
    /**
     * @brief Gets the card in cell
     * @return the card in cell
     * @exception emtpy_source raises if cell is empty
     */
    Card getCard() const;
    /**
     * @brief Checks if it's valid to accept a card
     * @param C The card to be accepted
     * @return True if the card can be accepted
     */
    bool chkAcceptCard(const Card& C);
    /**
     * @brief Accepts a card
     * @param C The card to be accepted
     * @return True if the card is accepted
     */
    bool acceptCard(const Card& C);
    /**
     * @brief Pops a card
     * @exception emtpy_source raises for cell is empty
     */
    void popCard();
private:
    /**
     * @brief cell empty indicator
     */
    bool e;
    /**
     * @brief card in cell
     */
    Card c;
};

#endif
