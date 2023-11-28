#include "node.hpp"
#include "connection.hpp"

Connection::Connection(Node * b, double d, double s, double A){
    _b = b;
    _d = d;
    _s = s;
    _A = A;
}

void Connection::update_A(double A){
    _A = A;
}

