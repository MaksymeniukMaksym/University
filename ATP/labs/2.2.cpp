#include<bits/stdc++.h>
#include<iostream>
#include<iterator>
#include<vector>
 
using namespace std;
 
int main()
{  
    int size;
    cin>>size;
    vector<int> arr(size);
    vector<int> sort(size);
 
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
   
    int max;
    int x,k;
     for(int i = size-1; i >= 0; --i)
     {  k=i;
        max = arr[i];
           for(int j = 0; j < i; j++)
           {
               if(arr[j]>max)
               {    
                   k=j;
                   max = arr[j];
               }
 
           }
        swap(arr[i],arr[k]);
       
         
     }
 
    copy( arr.begin(),   // итератор начала массива
          arr.end(),     // итератор конца массива
          ostream_iterator<int>(cout," ")   //итератор потока вывода
        );
   
 
 
    return 0;
}
