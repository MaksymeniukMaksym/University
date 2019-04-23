#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#include<iostream>
 
 
using namespace std;
 
 int BinSearch(int* arr, int count, int key)
{
  int l = 0;            
  int u = count - 1;    
 
  while (l <= u) {
    int m = (l + u) / 2;
    if (arr[m] == key) return m;
    if (arr[m] < key) l = m + 1;
    if (arr[m] > key) u = m - 1;
  }
  return -1;
}
 
int main ()
{
    int f_size, s_size;
 
cin>>f_size>>s_size;
    int number1[f_size];
 
 
  int number2[s_size];
 
 
 
for(int i= 0;i < f_size;i++)
{
    cin>>number1[i];
}
 
for(int i= 0;i < s_size;i++)
{
    cin>>number2[i];
}
int i = 0;
 
while( i < s_size)
{
   
    if(BinSearch(number1,f_size,number2[i]) != -1)
    {
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;  
    i++;
}
 
 
    return 0;
}
