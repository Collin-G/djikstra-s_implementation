#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
class vertex_list;
class Heap;
class Graph{
    private:
    vertex_list ** vertices = nullptr; 
    public:
    Graph();
    ~Graph();
    void path(int a, int b);
    void lowest(int a,int b);
    void scan_vertex(int a, Heap * heap);
    void remove_from_lists(vertex_list * vertex, int pos);
    std::string insert(int a, int b, double d, double s);
    void print(int a);
    std::string remove(int a);
    void update_traffic(int a, int b, double A);

};
#endif