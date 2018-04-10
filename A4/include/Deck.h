/**
 * @file Deck.h
 * @author Harry Fu
 * @brief Provides the Deck class declaration
 * @date 4/6/2018
 */

#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"
#include "Cell.h"
#include "Foundation.h"
#include "Mover.h"
#include "Pile.h"

/**
 * @brief Deck class
 */
class Deck {
   public:
    /**
     * @brief number of piles
     */
    const unsigned NUM_P = 8;
    /**
     * @brief number of cells
     */
    const unsigned NUM_C = 4;
    /**
     * @brief number of foundations
     */
    const unsigned NUM_F = 4;
    /**
     * @brief Deck constructor
     */
    Deck();
    /**
     * @brief Deck constructor with parameters
     * @details The cards and their order in foundations must meet the corresponding game rules.
     *  The cards and their order in piles must meet the corresponding game rules.
     *  The number of all cards must be 52. No duplicate card allowed.
     * @param cs The cells
     * @param fs The foundations
     * @param ps The piles
     */
    Deck(const std::vector<Cell>& cs, const std::vector<Foundation>& fs,
         const std::vector<Pile>& ps);
    /**
     * @brief Checks if player is won
     * @return True if player is won
     */
    bool isPlayerWon();
    /**
     * @brief Checks if any valid moves available
     * @return True if any valid moves available
     */
    bool hasValidMoves();
    /**
     * @brief Checks if cell is empty
     * @param i The index of cell
     * @return True if cell is empty
     * @exception invalid_index raises if index is invalid
     */
    bool isCellEmpty(int i);
    /**
     * @brief Checks if pile is empty
     * @param i The index of pile
     * @return True if pile is empty
     * @exception invalid_index raises if index is invalid
     */
    bool isPileEmpty(int i);
    /**
     * @brief Checks if foundation is empty
     * @param i The index of foundation
     * @return True if foundation is empty
     * @exception invalid_index raises if index is invalid
     */
    bool isFoundationEmpty(int i);
    /**
     * @brief Gets pile size
     * @param i The index of pile
     * @return The indexed pile size
     * @exception invalid_index raises if index is invalid
     */
    unsigned getPileSize(int i);
    /**
     * @brief Gets foundation size
     * @param i The index of foundation
     * @return The indexed foundation size
     * @exception invalid_index raises if index is invalid
     */
    unsigned getFoundationSize(int i);
    /**
     * @brief Gets a card from cell
     * @param i The index of cell
     * @return The card in indexed cell
     * @exception invalid_index raises if index is invalid
     * @exception emtpy_source raises if indexed cell is empty
     */
    Card getCardFromCell(int i);
    /**
     * @brief Gets a card from pile
     * @param i The index of pile
     * @param j The index of card in pile
     * @return The indexed card in indexed pile
     * @exception invalid_index raises if any index is invalid
     * @exception emtpy_source raises if indexed pile is empty
     */
    Card getCardFromPile(int i, int j);
    /**
     * @brief Gets a card from foundation
     * @param i The index of foundation
     * @param j The index of card in foundation
     * @return The indexed card in indexed foundation
     * @exception invalid_index raises if any index is invalid
     * @exception emtpy_source raises if indexed foundation is empty
     */
    Card getCardFromFoundation(int i, int j);
    /**
     * @brief Checks if it's valid to move a card from a pile to another pile
     * @param si The index of source pile
     * @param di the index of destination pile
     * @return True if card can be moved
     * @exception invalid_index raises if any index is invalid
     */
    bool chkPileToPile(int si, int di);
    /**
     * @brief Moves a card from a pile to another pile
     * @param si The index of source pile
     * @param di the index of destination pile
     * @return True if card is moved
     * @exception invalid_index raises if any index is invalid
     */
    bool pileToPile(int si, int di);
    /**
     * @brief Checks if it's valid to move a card from a pile to a cell
     * @param si The index of source pile
     * @param di the index of destination cell
     * @return True if card can be moved
     * @exception invalid_index raises if any index is invalid
     */
    bool chkPileToCell(int si, int di);
    /**
     * @brief Moves a card from a pile to a cell
     * @param si The index of source pile
     * @param di the index of destination cell
     * @return True if card is moved
     * @exception invalid_index raises if any index is invalid
     */
    bool pileToCell(int si, int di);
    /**
     * @brief Checks if it's valid to move a card from a cell to a pile
     * @param si The index of source cell
     * @param di the index of destination pile
     * @return True if card can be moved
     * @exception invalid_index raises if any index is invalid
     */
    bool chkCellToPile(int si, int di);
    /**
     * @brief Moves a card from a cell to a pile
     * @param si The index of source cell
     * @param di the index of destination pile
     * @return True if card is moved
     * @exception invalid_index raises if any index is invalid
     */
    bool cellToPile(int si, int di);
    /**
     * @brief Checks if it's valid to move a card from a cell to a foundation
     * @param si The index of source cell
     * @param di the index of destination foundation
     * @return True if card can be moved
     * @exception invalid_index raises if any index is invalid
     */
    bool chkPileToFoundation(int si, int di);
    /**
     * @brief Moves a card from a cell to a foundation
     * @param si The index of source cell
     * @param di the index of destination foundation
     * @return True if card is moved
     * @exception invalid_index raises if any index is invalid
     */
    bool pileToFoundation(int si, int di);
    /**
     * @brief Checks if it's valid to move a card from a cell to a foundation
     * @param si The index of source cell
     * @param di the index of destination foundation
     * @return True if card can be moved
     * @exception invalid_index raises if any index is invalid
     */
    bool chkCellToFoundation(int si, int di);
    /**
     * @brief Moves a card from a cell to a foundation
     * @param si The index of source cell
     * @param di the index of destination foundation
     * @return True if card is moved
     * @exception invalid_index raises if any index is invalid
     */
    bool cellToFoundation(int si, int di);

   private:
    /**
     * @brief cells
     */
    std::vector<Cell> cs;
    /**
     * @brief foundations
     */
    std::vector<Foundation> fs;
    /**
     * @brief piles
     */
    std::vector<Pile> ps;
    /**
     * @brief mover
     */
    Mover m;
    /**
     * @brief Deal cards to piles
     * @details Shuffle 52 cards then deal them all into 8 piles
     *  Assume this method only gets executed once right after the default construction
     */
    void dealCards();
};

#endif
