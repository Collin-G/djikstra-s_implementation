#ifndef CONNECTION_HPP
#define CONNECTION_HPP
class Node;
class Connection{
    private:
        Node * _b = nullptr;
        double _d{};
        double _s{};
        double _A{};
    public:
        Connection(Node * b, double d, double s, double A);
        void update_A(double A);
    
};
#endif