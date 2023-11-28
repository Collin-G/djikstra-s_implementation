#include <iostream>
#include <cmath>
#include "connection_e.hpp"
#include "connection_list.hpp"

connection_list::connection_list(){
        first = nullptr;
        last = nullptr;
        count = 0;
}
connection_list::~connection_list(){
    connection_e * cur;
    while(first){
        cur = first;
        first = cur->get_next();
        delete cur;
        cur = nullptr;

    }
}
std::string connection_list::add(double x,double y){
    // Adds node to end of linked list at last
    if (x >0 and y> 0){
        ++count;
        connection_e * connection = new connection_e(x,y);
        
        if(first == nullptr){
            first = connection;
            last = connection;
        }
        else{
            connection->set_prev(last);
            last->set_next(connection);
            last = last->get_next();
        }
        return "success";
    }
    else{
        return "failure";
    }
}

void connection_list::remove(connection_e * connection){
    // Delete node
    connection_e *temp{};
    -- count;
    if (connection == first){
        temp = first;
        first = temp->get_next();
        delete temp;
        temp = nullptr;
    }
    else if (connection == last){
        temp = connection;
        last = connection->get_prev();
        connection->get_prev()->set_next(nullptr);
        delete connection;
        connection = nullptr;

    }
    else{
        connection->get_prev()->set_next(connection->get_next());
        connection->get_next()->set_prev(connection->get_prev());
        delete connection;
        connection = nullptr;
        
    }
}

void connection_list::prt(double D){
    connection_e * cur = first;
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

int connection_list::time(double t){
    connection_e * cur = first;
    connection_e * next;
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

void connection_list::eat(){
            
    connection_e * cur = first;
    connection_e *next{};
    while (cur){
        next = cur->get_next();
        if (sqrt(cur->get_x()*cur->get_x() + cur->get_y()*cur->get_y()) < 1){
            remove(cur);
            
        }   
        cur = next;
    
    }
}

int connection_list::num(){
    return count;
}

std::string connection_list::over(){
    if (count > 0){
        return "the players win";
    }
    else{
        return "the wolf wins";
    }
}