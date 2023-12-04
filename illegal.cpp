#include "illegal.hpp"
char * illegal_exception::what(){
        return "illegal argument";
    }