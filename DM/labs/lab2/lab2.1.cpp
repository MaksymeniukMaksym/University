#include <iostream>
#include <stdio.h>

main()
{
      setlocale(LC_ALL,"Ukrainian");
      int A[100][100],B[100]={0},C[100]={100},K[100]={0};
      int a,b,i,j,n,n1,p,l,cina;
      char ch[12]="АБВГДЕЖ ";   
           printf("ВВЕДiТb КiЛЬКiСТЬ МНОЖИН: \n");
           scanf("%d",&a);
           printf("ВВЕДiТb КiЛЬКiСТЬ СТОВПЦiВ:\n");
           scanf("%d",&b);
           printf(" ");
           for(i=0;i<b;i++)
           {
             printf(" ");                 
             printf("%d",i+1);   
           }
           printf(" цiна");
           printf("\n");
           for (i=0;i<a;i++)
           {
               printf("\n");
               printf("%c",ch[i]);
               for(j=0;j<=b;j++)
               {
                    printf(" ");
                    scanf("%d",&A[i][j]);
               }
           }
           n1=0;l=0; cina=0;
           for(j=0;j<a;j++)
           {    
                n=0;                                         
                for(i=0;i<b;i++)
                {                                 
                     if(A[j][i]==1) n++;             
                     if(n>n1) {n1=n; p=j;
                }           
           }                               
      }                                                                       
      printf("\n");
      while(l!=b)
      { 
          for(i=0;i<b;i++)
          {
               if(C[i]!=i)
               {   
                   if(A[p][i]==1)  
                   {
                        C[i]=i;l++;
                   }  
               }  
          }
          cina+=A[p][b];
          printf("%c",ch[p]);    
          n1=0;    
          for(j=0;j<a;j++)
          {     
                n=0;                       
                for(i=0;i<b;i++)
                {
                     if(i!=C[i])
                     {                       
                           if(A[j][i]==1) n++;    
                           if(n>n1) 
                           {
                                    n1=n; p=j;
                           }}
                 }                     
           }                                      
      }                  
      printf(" - цiна - %d\n",cina);      
     std::cin.get();
}