/**
 * @file Cell.cpp
 * @author Harry Fu
 * @brief Provides the Cell class definition
 * @date 4/6/2018
 */

#include "Cell.h"
#include "Exceptions.h"

Cell::Cell() : e(true), c({Card::SC, Card::RA}) {
    //
}

bool Cell::empty() const {
    return e;
}

Card Cell::getCard() const {
    if (e) {
        throw emtpy_source();
    }
    return c;
}

bool Cell::chkAcceptCard(const Card& C) {
    return e;
}

bool Cell::acceptCard(const Card& C) {
    if (!e) {
        return false;
    }
    e = false;
    c = C;
    return true;
}

void Cell::popCard() {
    if (e) {
        throw emtpy_source();
    }
    e = true;
}
