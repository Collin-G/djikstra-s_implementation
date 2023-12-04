
#ifndef ILLEGAL_HPP
#define ILLEGAL_HPP
#include<iostream>
class illegal_exception: public std::exception{
    public:
    char * what();
};
#endif