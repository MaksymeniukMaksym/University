#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
 
 
int main ()
{
    string comand;
    int n;
    vector<int> arr(0);
    while(true)
    {
        cin>>comand;
        if(comand == "push")
        {   n = 0;
            cin>>n;
            arr.push_back(n);
            cout<<"ok"<<endl;
 
        }else if(comand == "pop")
        {
            cout<<arr[arr.size() - 1]<<endl;
            arr.pop_back();
        }else if(comand == "back")
        {
           cout<<arr[arr.size() - 1]<<endl;
        }else if(comand == "size")
        {
           cout<<arr.size()<<endl;
        }else if(comand == "clear")
        {
           arr.clear();
           cout<<"ok"<<endl;
        }else if(comand == "exit")
        {
           cout<<"bye"<<endl;
           return 0;
        }
    }
}
