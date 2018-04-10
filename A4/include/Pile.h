/**
 * @file Pile.h
 * @author Harry Fu
 * @brief Provides the Pile class declaration
 * @date 4/6/2018
 */

#ifndef PILE_H
#define PILE_H

#include "Card.h"
#include <vector>

/**
 * @brief Pile class
 */
class Pile {
public:
    /**
     * @brief Pile constructor
     */
    Pile();
    /**
     * @brief Checks if pile is empty
     * @return True if pile is empty
     */
    bool empty();
    /**
     * @brief Gets the size of pile
     * @return the size of pile
     */
    unsigned size();
    /**
     * @brief Assigns a card to pile
     * @param c The card to be assigned
     */
    void assignCard(const Card& c);
    /**
     * @brief Checks if it's valid to accept a card
     * @param c The card to be accepted
     * @return True if the card can be accepted
     */
    bool chkAcceptCard(const Card& c);
    /**
     * @brief Accepts a card
     * @param c The card to be accepted
     * @return True if the card is accepted
     */
    bool acceptCard(const Card& c);
    /**
     * @brief Gets a card in pile
     * @param i The index of card in pile
     * @return the indexed card in pile
     * @exception emtpy_source raises if pile is empty
     * @exception invalid_index raises if pile is not empty but index is invalid
     */
    Card getCard(int i);
    /**
     * @brief Pops the last card
     * @exception emtpy_source raises for pile is empty
     */
    void popCard();
private:
    /**
     * @brief cards of pile
     */
    std::vector<Card> cards;
};

#endif
