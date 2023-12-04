#include "node.hpp"
Node::Node(int index, double d, double s, double A){
       _index = index;
       _d = d;
       _s = s;
       _A = A;
       next = nullptr;
       prev = nullptr;
}


double Node::get_d(){
    return _d;
}

double Node::get_s(){
    return _s;
}

double Node::get_A(){
    return _A;
}

double Node::get_weight(){
    return _d/(_s*_A);
}
void Node::set_index(int index){
    _index = index;
}
int Node::get_index(){
    return _index;
}

void Node::set_d(double d){
    _d = d;
}

void Node::set_s(double s){
    _s = s;
}

void Node::set_A(double A){
    _A = A;
}

void Node::set_next(Node * node){
    next = node;
}
Node * Node::get_next(){
    return next;
}
void Node::set_prev(Node * node){
    prev = node;
}
Node * Node::get_prev(){
    return prev;
}