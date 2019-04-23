#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int size;
    cin>>size;
    vector<int>arr(size);
 
    for(int i = 0; i < size;i++)
    {
        cin>>arr[i];
    }
 
    for(int i = 0; i < size; i++)
    {
        for(int j = size - 1; j > i;j--)
        {
            if(arr[j-1] > arr[j])
            {
                swap(arr[j-1],arr[j]);
            }
        }
    }
 
 
    for(int i = 0; i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
 
 
 
 
 
 
 
    return 0;
}
