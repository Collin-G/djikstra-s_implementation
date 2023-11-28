#ifndef CHILDREN_HPP
#define CHILDREN_HPP
#include <iostream>
class vertex_e;
class vertex_list{
private:
    vertex_e *first,*last;
    int count{};
    
public:
    vertex_list();
    ~vertex_list();
    std::string add(double x,double y);
    int num();
    void eat();
    void prt(double D);
    void remove(vertex_e * vertex);
    int time(double t);
    std::string over();
};

#endif
