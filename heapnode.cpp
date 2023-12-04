#include "heapnode.hpp"

HeapNode::HeapNode(int index, double cost){
    _index = index;
    _cost = cost;
}

int HeapNode::get_index(){
    return _index;
}

double HeapNode::get_cost(){
    return _cost;
}

void HeapNode::set_cost(double cost){
    _cost = cost;
}

bool HeapNode::operator>(HeapNode * a){
    if (_cost < a->get_cost()){
        return true;
    }
    else{
        return false;
    }

}
