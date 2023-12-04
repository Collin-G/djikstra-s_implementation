#include "heap.hpp"
#include "heapnode.hpp"
#include "vertex_list.hpp"
#include "limits.h"

#ifndef HEAP_HPP
#define HEAP_HPP
Heap::Heap(vertex_list ** vertices){
   
    cost_list = new double[500001];
    prev = new int[500001];
    heap = new int[500001];
    size = 0;
    for (int i = 0; i < 500001; ++i){
        // heap[i] = nullptr;
        // cost_list[i];
        if(vertices[i]){
            cost_list[i] = INT_MAX;
            // heap[size] = i;
            // ++size; 
            // HeapNode * heapnode = new HeapNode(i, -1);
            // heap[count] = heapnode;
        }
    }
   
   
    // size = 0;
    // return heap;
}

Heap::~Heap(){
    delete [] heap;
    }


int Heap::get_size(){
    return size;
}

double * Heap::get_cost_list(){
    return cost_list;
}

int * Heap::get_heap(){
    return heap;
}

int * Heap::get_prev(){
    return prev;
}


// void Heap::swap(int * a, int * b)

int Heap::extract_min(){
     if (size <= 0){
        return -1;}
    if (size == 1)
    {
        --size;
        return heap[0];
    }
 
    // Store the minimum value, and remove it from heap
    int root = heap[0];
    heap[0] = heap[size-1];
    --size;
    heapify(0, size);
 
    return root;
}

void Heap::increment(){
    ++size;
}
void Heap::heapify(int i, int n){
    int left = 2*i;
    int right = 2*i+1;
    int largest{};
    
    if (left <= n && cost_list[heap[left]] > cost_list[heap[i]]){
        largest = left;
    }
    else{
        largest = i;
    }

    if (right <= n && cost_list[heap[right]] > cost_list[heap[largest]]){
        largest = right;
    }

    if(largest != i){
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(largest,n);
    }


}

void Heap::swap(int a, int b){
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

#endif