#include <iostream>
#include "vertex_list.hpp"
#include "graph.hpp"
#include "illegal.hpp"
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
            try{

                std::cin>>a;
                std::cin>>b;
                std::cin>>d;
                std::cin>>s;
                if (a>0 && a < 500001 && b > 0 && b< 500001 && d > 0 && s > 0){
                     std::cout<<graph->insert(a,b,d,s)<<std::endl;
                }
                else{
                    illegal_exception ex;
                    throw ex;
                   }
                
            }
            catch(std::exception &e){
                std::cout<<"illegal argument"<<std::endl;
            }

        }
        else if (cmd == "PRINT"){
              try{

                std::cin>>a;
                if (a>0 && a < 500001){
                   graph->print(a);
                }
                else{
                     illegal_exception ex;
                    throw ex;
                    }
                
            }
            catch(std::exception &e){
                std::cout<<"illegal argument"<<std::endl;
            }
        }

        else if (cmd == "DELETE"){
            try{
            std::cin>>a;
            if (a>0 && a < 500001){
                std::cout<<graph->remove(a)<<std::endl;
            }
            else{
               illegal_exception ex;
                    throw ex;  
            }
            }
             catch(std::exception &e){
                std::cout<<"illegal argument"<<std::endl;
            }
        }

        else if (cmd == "TRAFFIC"){
             try{

                std::cin>>a;
                std::cin>>b;
                std::cin>>A;
                if (a>0 && a < 500001 && b > 0 && b< 500001 && A >0){
                    graph->update_traffic(a,b,A);
                }
                else{
                    illegal_exception ex;
                    throw ex;
                   }
                
            }
            catch(std::exception &e){
                std::cout<<"illegal argument"<<std::endl;
            }

        }

        else if (cmd == "PATH"){
            try{

                std::cin>>a;
                std::cin>>b;
                
                if (a>0 && a < 500001 && b > 0 && b< 500001){
                     graph->path(a,b);
                }
                else{
                    illegal_exception ex;
                    throw ex;
                   }
                
            }
            catch(std::exception &e){
                std::cout<<"illegal argument"<<std::endl;
            }
            
            
        }

        else if (cmd == "LOWEST"){
             try{

                std::cin>>a;
                std::cin>>b;
                
                if (a>0 && a < 500001 && b > 0 && b< 500001){
                     graph->lowest(a,b);
                }
                else{
                    illegal_exception ex;
                    throw ex;
                   }
                
            }
            catch(std::exception &e){
                std::cout<<"illegal argument"<<std::endl;
            }
        }
     else if (cmd == "END"){break;}
    }
   
    delete graph;
}