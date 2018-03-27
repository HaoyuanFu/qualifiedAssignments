/**
 * @file Exceptions.h
 * @author Harry Fu
 * @brief Provides several exception types
 * @date 3/24/2018
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

/**
 * @brief invalid_argument class
 */
class invalid_argument : public std::exception {
   const char * what () const throw () {
      return "invalid argument";
   }
};

/**
 * @brief outside_bounds class
 */
class outside_bounds : public std::exception {
   const char * what () const throw () {
      return "outside bounds";
   }
};

#endif
