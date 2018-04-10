/**
 * @file Card.cpp
 * @author Harry Fu
 * @brief Provides the Card class definition
 * @date 4/6/2018
 */

#include "Card.h"

Card::Card(enum Suits S, enum Ranks R) : s(S), r(R) {
    //
}

bool Card::sameColor(const Card& c) const {
    switch (s) {
        case SC:
            return c.s == SC || c.s == SS;
        case SD:
            return c.s == SD || c.s == SH;
        case SH:
            return c.s == SD || c.s == SH;
        case SS:
            return c.s == SC || c.s == SS;
    }
}

bool Card::smallerByOne(const Card& c) const {
    return c.r - r == 1;
}

Card::Suits Card::getSuit() const {
    return s;
}

Card::Ranks Card::getRank() const {
    return r;
}