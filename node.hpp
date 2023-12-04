#ifndef CHILDNODE_HPP
#define CHILDNODE_HPP
class Node{
public: 
    Node(int index, double d, double s, double A);
    int get_index();
    double get_d();
    double get_s();
    double get_A();
    double get_weight();

    void set_index(int index);
    void set_d(double d);
    void set_s(double s);
    void set_A(double A);



    void set_next(Node * node);
    Node * get_next();
    void set_prev(Node * node);
    Node * get_prev();
    
 
private:
    int _index{};
    double _d{};
    double _s{};
    double _A{};
    Node *next{};
    Node *prev{};

};

#endif