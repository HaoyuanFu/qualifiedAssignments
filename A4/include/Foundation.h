/**
 * @file Foundation.h
 * @author Harry Fu
 * @brief Provides the Foundation class declaration
 * @date 4/6/2018
 */

#ifndef FOUNDATION_H
#define FOUNDATION_H

#include "Card.h"
#include <vector>

/**
 * @brief Foundation class
 */
class Foundation {
public:
    /**
     * @brief Foundation constructor
     */
    Foundation();
    /**
     * @brief Checks if foundation is empty
     * @return True if foundation is empty
     */
    bool empty();
    /**
     * @brief Gets the size of foundation
     * @return the size of foundation
     */
    unsigned size();
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
     * @brief Gets a card in foundation
     * @param i The index of card in foundation
     * @return the indexed card in foundation
     * @exception emtpy_source raises if foundation is empty
     * @exception invalid_index raises if foundation is not empty but index is invalid
     */
    Card getCard(int i);
    /**
     * @brief Pops the last card
     * @exception emtpy_source raises for foundation is empty
     */
    void popCard();
private:
    /**
     * @brief cards of foundation
     */
    std::vector<Card> cards;
};

#endif
