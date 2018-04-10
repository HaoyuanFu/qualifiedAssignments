/**
 * @file Pile.cpp
 * @author Harry Fu
 * @brief Provides the Pile class definition
 * @date 4/6/2018
 */

#include "Pile.h"
#include "Exceptions.h"

Pile::Pile() {
    //
}

unsigned Pile::size() {
    return cards.size();
}

bool Pile::empty() {
    return cards.empty();
}

void Pile::assignCard(const Card& c) {
    cards.push_back(c);
}

bool Pile::chkAcceptCard(const Card& c) {
    if (cards.empty()) {
        return true;
    }
    Card& _c_ = cards.back();
    return c.smallerByOne(_c_) && !c.sameColor(_c_);
}

bool Pile::acceptCard(const Card& c) {
    if (cards.empty()) {
        cards.push_back(c);
        return true;
    }
    Card& _c_ = cards.back();
    if (c.smallerByOne(_c_) && !c.sameColor(_c_)) {
        cards.push_back(c);
        return true;
    }

    return false;
}

Card Pile::getCard(int i) {
    if (cards.empty()) {
        throw emtpy_source();
    }
    if (i < 0 || i > cards.size() - 1) {
        throw invalid_index();
    }

    return cards[i];
}

void Pile::popCard() {
    if (cards.empty()) {
        throw emtpy_source();
    }

    cards.pop_back();
}