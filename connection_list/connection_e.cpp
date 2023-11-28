#include "connection_e.hpp"
connection_e::connection_e(double x,double y){
       _x = x;
       _y = y;
       next = nullptr;
       prev = nullptr;
}
void connection_e::set_x(double x){
    _x = x;
}
double connection_e::get_x(){
    return _x;
}
void connection_e::set_y(double y){
    _y = y;
}
double connection_e::get_y(){
    return _y;
}
void connection_e::set_next(connection_e * node){
    next = node;
}
connection_e * connection_e::get_next(){
    return next;
}
void connection_e::set_prev(connection_e * node){
    prev = node;
}
connection_e * connection_e::get_prev(){
    return prev;
}