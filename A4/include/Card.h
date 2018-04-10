/**
 * @file Card.h
 * @author Harry Fu
 * @brief Provides the Card class declaration
 * @date 4/6/2018
 */

#ifndef CARD_H
#define CARD_H

/**
 * @brief Card class
 */
class Card {
   public:
    /**
     * @brief Card Suits type
     */
    enum Suits { SC, SD, SH, SS };
    /**
     * @brief Card Ranks type
     */
    enum Ranks { RA, R2, R3, R4, R5, R6, R7, R8, R9, R10, RJ, RQ, RK };
    /**
     * @brief Card constructor
     * @param S The card suit
     * @param R The card rank
     */
    Card(enum Suits S, enum Ranks R);
    /**
     * @brief Gets the card suit
     * @return The card suit
     */
    Suits getSuit() const;
    /**
     * @brief Gets the card rank
     * @return The card rank
     */
    Ranks getRank() const;
    /**
     * @brief Checks if two cards have the same color
     * @param c The another card
     * @return True if two cards have the same color
     */
    bool sameColor(const Card& c) const;
    /**
     * @brief Checks if another card has smaller-by-one rank than this one
     * @param c The another card
     * @return True if another card has smaller-by-one rank than this one
     */
    bool smallerByOne(const Card& c) const;
   private:
    /**
     * @brief card suit
     */
    Suits s;
    /**
     * @brief card rank
     */
    Ranks r;
};

#endif
