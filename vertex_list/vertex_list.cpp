#include <iostream>
#include <cmath>
#include "vertex_e.hpp"
#include "vertex_list.hpp"

vertex_list::vertex_list(){
        first = nullptr;
        last = nullptr;
        count = 0;
}
vertex_list::~vertex_list(){
    vertex_e * cur;
    while(first){
        cur = first;
        first = cur->get_next();
        delete cur;
        cur = nullptr;

    }
}
std::string vertex_list::add(double x,double y){
    // Adds node to end of linked list at last
    if (x >0 and y> 0){
        ++count;
        vertex_e * vertex = new vertex_e(x,y);
        
        if(first == nullptr){
            first = vertex;
            last = vertex;
        }
        else{
            vertex->set_prev(last);
            last->set_next(vertex);
            last = last->get_next();
        }
        return "success";
    }
    else{
        return "failure";
    }
}

void vertex_list::remove(vertex_e * vertex){
    // Delete node
    vertex_e *temp{};
    -- count;
    if (vertex == first){
        temp = first;
        first = temp->get_next();
        delete temp;
        temp = nullptr;
    }
    else if (vertex == last){
        temp = vertex;
        last = vertex->get_prev();
        vertex->get_prev()->set_next(nullptr);
        delete vertex;
        vertex = nullptr;

    }
    else{
        vertex->get_prev()->set_next(vertex->get_next());
        vertex->get_next()->set_prev(vertex->get_prev());
        delete vertex;
        vertex = nullptr;
        
    }
}

void vertex_list::prt(double D){
    vertex_e * cur = first;
    bool empty = true;
    while (cur){
        if (sqrt(cur->get_x()*cur->get_x() + cur->get_y()*cur->get_y()) < D){
            std::cout<<cur->get_x()<<" "<<cur->get_y()<<" ";
            empty = false;
        }
        cur = cur->get_next(); 
    }
    
    if (empty == false){
        std::cout<<std::endl;
    }
    else{
        std::cout<<"no children within distance"<<std::endl;
    }  
}

int vertex_list::time(double t){
    vertex_e * cur = first;
    vertex_e * next;
    if (num()==0){
        return 0;
    }
    if (t<0){
        eat();
    }
    else{
        
        while (cur){
            double x = cur->get_x();
            double y = cur->get_y();
            double delt_x = t*cos(atan2(y,x));
            double delt_y = t*sin(atan2(y,x));
            next = cur->get_next();
            if (x-delt_x <= 0 || y-delt_y <= 0){
                remove(cur);
                
            }
            else{
                cur->set_x(x-delt_x);
                cur->set_y(y-delt_y);
            }
            
            cur = next;    
        }
        
    }
    return num();

}

void vertex_list::eat(){
            
    vertex_e * cur = first;
    vertex_e *next{};
    while (cur){
        next = cur->get_next();
        if (sqrt(cur->get_x()*cur->get_x() + cur->get_y()*cur->get_y()) < 1){
            remove(cur);
            
        }   
        cur = next;
    
    }
}

int vertex_list::num(){
    return count;
}

std::string vertex_list::over(){
    if (count > 0){
        return "the players win";
    }
    else{
        return "the wolf wins";
    }
}