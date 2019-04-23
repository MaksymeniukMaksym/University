#include<bits/stdc++.h>
 
using namespace std;
 
int main (void)
{  
    //input size of arr
    int size;
    cin>>size;
    //create arr
    int arr[size];
    //enter the array
    for(int i = 0;i < size; i++)
    {
        cin>>arr[i];
    }
    //enter the number that we will search
    int search_numb;
    cin>>search_numb;
    //number counter in array
   int counter = 0;
   for(int i=0;i<size;i++)
   {
       if(arr[i] == search_numb)
       {
           counter = counter + 1;
       }
 
   }
    cout<<counter;
    return 0;
}
 