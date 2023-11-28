#ifndef CHILDNODE_HPP
#define CHILDNODE_HPP
class vertex_e{
public: 
    vertex_e(double x,double y);
    void set_x(double x);
    double get_x();
    void set_y(double y);
    double get_y();
    void set_next(vertex_e * node);
    vertex_e * get_next();
    void set_prev(vertex_e * node);
    vertex_e * get_prev();
    
 
private:
    double _x{};
    double _y{};
    vertex_e *next{};
    vertex_e *prev{};

};

#endif