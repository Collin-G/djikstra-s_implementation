#ifndef CHILDREN_HPP
#define CHILDREN_HPP
#include <iostream>
class Node;
class vertex_list{
private:
    Node *first,*last;
    int count{};
    
public:
    vertex_list();
    ~vertex_list();
    Node * get_head();
    std::string add(int b, double d, double s, double A);
    std::string update_traffic(int b, double A);
    int num();
    void eat();
    void prt();
    void remove(Node * node);
    void find_and_remove(int ind);
    int time(double t);
    std::string over();
};

#endif
