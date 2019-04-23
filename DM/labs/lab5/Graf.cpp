#include <iostream>
#include<iomanip>



using namespace std;
int v;
int main() {
	int i,j;
	int infinity=1000;                    
	int VES[100][100];                         

	int x[100];                       

	int DlinaPuti[100];                    

	int PredVertex[100];                   
	int VERTEX;
	int p;
	cout<<"Ввести количество вершин в графе "<<endl;
	cin>>VERTEX;
	p= VERTEX;                    
	cout<<"Заполните матрицу весов графа "<<endl;      
	cout<<setw(4);
	for (i=0; i<VERTEX; i++)
		cout<<"|x"<<i+1;
	cout<<endl;

	for(i=0; i<VERTEX; i++) {
		cout<<"X"<<i+1<<'|';
		for(j=0; j<VERTEX; j++)
			cin>>VES[i][j];
	}

	int start;                  
	int end;                             
N:
	cout<<"Введите стартовую вершину: ";    
	cin>>start;
	if (start>(p-1) && start<0) {
		cout<<"Нет такой вершины повторите ввод..."<<endl;   
		goto N;
	}
	start=start-1; 
	for (int prosto=0; prosto<VERTEX; prosto++) {
		end=prosto;
		if (end==start) continue;            
		else {

			int u;
			for (u=0; u<p; u++) {
				DlinaPuti[u]=infinity;                    
				
				x[u]=0;                           
			}
			PredVertex[start]=0;                     
			DlinaPuti[start]=0;                      
			x[start]=1;                              
			v=start;                                

			while(1) {
				for(u=0; u<p; u++) {
					if(VES[v][u]==0)continue;     
					if(x[u]==0 && DlinaPuti[u]>DlinaPuti[v]+VES[v][u]) 
					{
						DlinaPuti[u]=DlinaPuti[v]+VES[v][u];           
						PredVertex[u]=v;                    
					}
				}

				int w=infinity;
				v=-1;                             
				for(u=0; u<p; u++) {              
					if(x[u]==0 && DlinaPuti[u]<w)           
						
					

{
						w= DlinaPuti[u];
					}
				}
				if(v==-1) {
					cout<<"Нет пути из вершины "<<start+1;
					cout<<" в вершину "<<end+1<<"."<<endl;
					break;
				}
				if(v==end) {                          
					// выводим его
					cout<<"Кратчайший путь из вершины "<<start+1;
					cout<<" в вершину "<<end+1<<":"<<" ";
					u=end;
					while(u!=start) {
						cout<<"X"<<u+1<<"-";
						u=PredVertex[u];
					}
					cout<<"X"<<start+1<<endl<<endl<<"Длина пути - "<< DlinaPuti[end]<<endl<<endl;
					break;
				}
				x[v]=1;
			}
		}
	}

	return 0;
}