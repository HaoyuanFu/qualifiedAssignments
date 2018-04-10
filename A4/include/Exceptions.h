/**
 * @file Exceptions.h
 * @author Harry Fu
 * @brief Provides several exception types
 * @date 4/6/2018
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

/**
 * @brief emtpy_source class
 */
class emtpy_source : public std::exception {
    const char* what() const throw() { return "source is empty"; }
};

/**
 * @brief invalid_index class
 */
class invalid_index : public std::exception {
    const char* what() const throw() { return "index is invalid"; }
};

#endif
