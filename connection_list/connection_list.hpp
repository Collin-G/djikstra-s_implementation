#ifndef CHILDREN_HPP
#define CHILDREN_HPP
#include <iostream>
class connection_e;
class connection_list{
private:
    connection_e *first,*last;
    int count{};
    
public:
    connection_list();
    ~connection_list();
    std::string add(double x,double y);
    int num();
    void eat();
    void prt(double D);
    void remove(connection_e * connection);
    int time(double t);
    std::string over();
};

#endif
