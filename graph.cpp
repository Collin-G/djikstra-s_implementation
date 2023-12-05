#include "node.hpp"
#include "graph.hpp"
#include "heap.hpp"
#include "vertex_list.hpp"
#include <iostream>
#include <limits.h>

Graph::Graph(){
    vertices = new vertex_list*[500001];
    for (int i = 0; i < 500001; ++i){
        vertices[i] = nullptr;
    }
}

Graph::~Graph(){
    for (int i = 0; i < 500001; ++i){
        if(vertices[i]){
        delete vertices[i];}

    }
    delete [] vertices;
}

void Graph::path(int a, int b){
    if (!(vertices[a] && vertices[b])){
        std::cout<<"failure"<<std::endl;
        return;
    }
    Heap * priorityq = new Heap(vertices);
    priorityq->get_cost_list()[a] = 0;
    scan_vertex(a, priorityq);
     if(priorityq->get_cost_list()[b] == INT_MAX){
        std::cout<<"failure"<<std::endl;
        return;
    }
    std::cout<<b<< " ";

    int prev = priorityq->get_prev()[b];
    while(prev != a){
        std::cout<<prev<< " ";
        prev = priorityq->get_prev()[prev];
    }
    std::cout<<a<<std::endl;
    delete priorityq;

}

void Graph::lowest(int a, int b){
    if (!(vertices[a] && vertices[b])){
        std::cout<<"failure"<<std::endl;
        return;
    }
    Heap * priorityq = new Heap(vertices);
     priorityq->get_cost_list()[a] = 0; 
    scan_vertex(a, priorityq);
    if(priorityq->get_cost_list()[b] == INT_MAX){
        std::cout<<"failure"<<std::endl;
        return;
    }
    std::cout<<priorityq->get_cost_list()[b]<<std::endl;
    delete priorityq;
}

void Graph::scan_vertex(int a, Heap * heap){
    // update 
    vertex_list * vertex = vertices[a];
    if(!vertex){
        return;
    }
    Node * cur = vertices[a]->get_head();
    while(cur){
        int ind = cur->get_index();
        if(cur->get_weight()+heap->get_cost_list()[a] < heap->get_cost_list()[ind]){
            
            // if(heap->get_cost_list()[ind] == INT_MAX){
                heap->increment();
                int i = heap->get_size()-1;
                while (i > 0 && cur->get_weight()+heap->get_cost_list()[a] < heap->get_cost_list()[heap->get_heap()[i/2]]){
                    heap->get_heap()[i] = heap->get_heap()[i/2];
                    i = i/2;
                }
                heap->get_heap()[i] = ind;
            // }
            // else{
            //     for(int k = 0; k < heap->get_size(); ++k){
            //         if(heap->get_heap()[k] == a){
            //             int i = k;
            //             while (i > 0 && cur->get_weight()+heap->get_cost_list()[a] < heap->get_cost_list()[heap->get_heap()[i/2]]){
            //                 heap->get_heap()[i] = heap->get_heap()[i/2];
            //                 i = i/2;
            //             }
            //             heap->get_heap()[i] = ind;
            //             heap->heapify(0, heap->get_size());
            //         }
            //     }
            // }
            // else{

            // }
            heap->get_cost_list()[ind] = cur->get_weight()+heap->get_cost_list()[a];
            heap->get_prev()[ind] = a;
        }
        cur = cur->get_next();
    }


    // std::cout<<a<<std::endl;
    int min = heap->extract_min();
    if (min == -1){
        return;
    }
    // else{}
    
    scan_vertex(min, heap);
    
}

std::string Graph::insert(int a, int b, double d, double s){
    if (!vertices[a]){
        vertices[a] = new vertex_list();
        vertices[a]->add(b, d,s,1);

    }
    else{
        vertices[a]->add(b,d,s,1);
    }

    if(!vertices[b]){
        vertices[b] = new vertex_list();
        vertices[b]->add(a, d,s,1);
    }
    else{
        vertices[b]->add(a,d,s,1);
    }
    return "success";
}

void Graph::remove_from_lists(vertex_list * vertex, int pos){
    if(!vertex){
        std::cout<<"failure"<<std::endl;
        return;
    }
    Node * cur = vertex->get_head();
    while(cur){
        int ind = cur->get_index();
        vertices[ind]->find_and_remove(pos);
        cur = cur->get_next();
    }
}

std::string Graph::remove(int a){
    vertex_list * vertex = vertices[a];
    if(!vertex){
        return "failure";
    }
    else{
        Node * cur = vertex->get_head();
        while(cur){
            int ind = cur->get_index();
            remove_from_lists(vertices[ind], ind);
            delete vertices[ind];
            vertices[ind] = nullptr;
            cur = cur->get_next();
        }
        delete vertices[a];
        vertices[a] = nullptr;
        return "success";
    }
}


void Graph::print(int a){
    vertex_list * vertex = vertices[a];
    if (vertex){
        vertex->prt();
    }
    else{
        std::cout<<"failure"<<std::endl;
    }
}

void Graph::update_traffic(int a, int b, double A){
    if (!(vertices[a] && vertices[b])){
        std::cout<<"failure"<<std::endl;
        return; 
    }
    else{
    vertex_list * vertex = vertices[a];
    vertex->update_traffic(b,A);

    vertex_list * vertex2 = vertices[b];
    std::cout<<vertex2->update_traffic(a,A)<<std::endl;
    }
}



