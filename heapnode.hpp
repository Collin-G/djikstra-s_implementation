#ifndef HEAPNODE_HPP
#define HEAPNODE_HPP
class HeapNode{
    public:
        HeapNode(int index, double cost);
        int get_index();
        double get_cost();
        void set_cost(double cost);
        bool operator>(HeapNode * a);
    private:
        int _index{};
        double _cost{};
};

#endif