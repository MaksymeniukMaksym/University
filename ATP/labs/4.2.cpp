#include<iostream>
#include<list>
#include<string>
#include<iterator>
  
int main ()
{
    std::string comand;
    int n;
    std::list<int> arr(0);
    while(true)
    {
        std::cin>>comand;
        if(comand == "push")
        {   n = 0;
            std::cin>>n;
            arr.push_back(n);
            std::cout<<"ok"<<std::endl;
 
        }else if(comand == "pop")
        {
            std::cout<<arr.front()<<std::endl;
            arr.pop_front();
                            
        }else if(comand == "front")
        {
        std::cout<<arr.front()<<std::endl;       
        
         }else if(comand == "size")
        {
           std::cout<<arr.size()<<std::endl;        
        }else if(comand == "clear")
        {
           arr.clear();
           std::cout<<"ok"<<std::endl;
        }else if(comand == "exit")
        {
           std::cout<<"bye"<<std::endl;
           return 0;
        }
    }
}