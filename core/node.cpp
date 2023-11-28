#include "node.hpp"

Node::Node(int index){
    _index = index;
}

int Node::get_index(){
    return _index;
}

void Node::set_index(int index){
    _index = index;
}