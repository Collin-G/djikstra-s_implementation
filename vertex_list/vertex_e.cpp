#include "vertex_e.hpp"
vertex_e::vertex_e(double x,double y){
       _x = x;
       _y = y;
       next = nullptr;
       prev = nullptr;
}
void vertex_e::set_x(double x){
    _x = x;
}
double vertex_e::get_x(){
    return _x;
}
void vertex_e::set_y(double y){
    _y = y;
}
double vertex_e::get_y(){
    return _y;
}
void vertex_e::set_next(vertex_e * node){
    next = node;
}
vertex_e * vertex_e::get_next(){
    return next;
}
void vertex_e::set_prev(vertex_e * node){
    prev = node;
}
vertex_e * vertex_e::get_prev(){
    return prev;
}