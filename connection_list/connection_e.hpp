#ifndef CHILDNODE_HPP
#define CHILDNODE_HPP
class connection_e{
public: 
    connection_e(double x,double y);
    void set_x(double x);
    double get_x();
    void set_y(double y);
    double get_y();
    void set_next(connection_e * node);
    connection_e * get_next();
    void set_prev(connection_e * node);
    connection_e * get_prev();
    
 
private:
    double _x{};
    double _y{};
    connection_e *next{};
    connection_e *prev{};

};

#endif