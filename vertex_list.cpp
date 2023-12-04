#include <iostream>
#include <cmath>
#include "node.hpp"
#include "vertex_list.hpp"

vertex_list::vertex_list(){
        first = nullptr;
        last = nullptr;
        count = 0;
}

vertex_list::~vertex_list(){
    Node * cur;
    while(first){
        cur = first;
        first = cur->get_next();
        delete cur;
        cur = nullptr;

    }
}

Node * vertex_list::get_head(){
    return first;
}

std::string vertex_list::add(int b,double d, double s, double A){
    // Adds node to end of linked list at last
    // if (x >0 and y> 0){
        Node * cur = first;
        while(cur){
            if (cur->get_index() == b){
                cur->set_A(A);
                cur->set_d(d);
                cur->set_s(s);
                return "success";
            }
            cur = cur->get_next();
        }
        
        ++count;
        
        Node * node = new Node(b,d,s,A);
        
        if(first == nullptr){
            first = node;
            last = node;
        }
        else{
            node->set_prev(last);
            last->set_next(node);
            last = last->get_next();
        }
        return "success";
    // }
    // else{
    //     return "failure";
    // }
}

void vertex_list::remove(Node * node){
    // Delete node
    Node *temp{};
    -- count;
    if (node == first){
        temp = first;
        first = temp->get_next();
        delete temp;
        temp = nullptr;
    }
    else if (node == last){
        temp = node;
        last = node->get_prev();
        node->get_prev()->set_next(nullptr);
        delete node;
        node = nullptr;

    }
    else{
        node->get_prev()->set_next(node->get_next());
        node->get_next()->set_prev(node->get_prev());
        delete node;
        node = nullptr;
        
    }
}

void vertex_list::prt(){
    Node * cur = first;
    bool empty = true;
    while (cur){
        std::cout<<cur->get_index()<<" ";
        
        cur = cur->get_next(); 
    }
    
    if (empty == false){
        std::cout<<std::endl;
    }
    else{
        std::cout<<" "<<std::endl;
    }  
}

std::string vertex_list::update_traffic(int b, double A){
    Node * cur = first;
    while(cur){
        if (cur->get_index() == b){
            cur->set_A(A);
            return "success";
        }
    }

    return "failure";

}

void vertex_list::find_and_remove(int pos){
    Node * cur = first;
    while (cur){
        if(cur->get_index() == pos){
            remove(cur);
        }
        cur = cur ->get_next();
    }
}

int vertex_list::num(){
    return count;
}

