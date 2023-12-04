#include <iostream>
#include "vertex_list.hpp"
#include "graph.hpp"

int main(){
    std::string cmd{};
    int a{};
    int b{};
    double d{};
    double s{};
    double A{};
    Graph * graph{};

    graph = new Graph();
    while(std::cin >> cmd){
        if (cmd == "INSERT"){
            std::cin>>a;
            std::cin>>b;
            std::cin>>d;
            std::cin>>s;
            std::cout<<graph->insert(a,b,d,s)<<std::endl;
        }
        else if (cmd == "PRINT"){
            std::cin>>a;
            graph->print(a);
        }

        else if (cmd == "DELETE"){
            std::cin>>a;
            std::cout<<graph->remove(a)<<std::endl;
        }

        else if (cmd == "TRAFFIC"){
            std::cin>>a;
            std::cin>>b;
            std::cin>>A;
            graph->update_traffic(a,b,A);

        }

        else if (cmd == "PATH"){
            std::cin>>a;
            std::cin>>b;
            graph->path(a,b);
        }

        else if (cmd == "LOWEST"){
            std::cin>>a;
            std::cin>>b;
            graph->lowest(a,b);
        }

       
    }
    delete graph;
}