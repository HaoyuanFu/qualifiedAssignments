/**
 * @file Foundation.cpp
 * @author Harry Fu
 * @brief Provides the Foundation class definition
 * @date 4/6/2018
 */

#include "Foundation.h"

#include "Pile.h"
#include "Exceptions.h"

Foundation::Foundation() {
    //
}

unsigned Foundation::size() {
    return cards.size();
}

bool Foundation::empty() {
    return cards.empty();
}

bool Foundation::chkAcceptCard(const Card& c) {
    if (cards.empty()) {
        return c.getRank() == Card::RA;
    }
    Card& _c_ = cards.back();
    return _c_.smallerByOne(c) && _c_.getSuit() == c.getSuit();
}

bool Foundation::acceptCard(const Card& c) {
    if (cards.empty()) {
        if (c.getRank() != Card::RA) {
            return false;
        }
        cards.push_back(c);
        return true;
    }
    Card& _c_ = cards.back();
    if (_c_.smallerByOne(c) && _c_.getSuit() == c.getSuit()) {
        cards.push_back(c);
        return true;
    }

    return false;
}

Card Foundation::getCard(int i) {
    if (cards.empty()) {
        throw emtpy_source();
    }
    if (i < 0 || i > cards.size() - 1) {
        throw invalid_index();
    }

    return cards[i];
}

void Foundation::popCard() {
    if (cards.empty()) {
        throw emtpy_source();
    }

    cards.pop_back();
}