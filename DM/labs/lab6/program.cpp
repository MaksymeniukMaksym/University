#include <iostream>

#include<bits/stdc++.h>
#define ROW 13
#define COL 13
#define infi 5000

using namespace std;

int first[14];
int second[14];
int tmp=0;

class prims {
		int graph[ROW][COL],nodes;
	public:
		prims();
		void createGraph();
		void primsAlgo();
};

prims :: prims() {
	for(int i=0; i<ROW; i++)
		for(int j=0; j<COL; j++)
			graph[i][j]=0;
}

void prims :: createGraph() {
	int i,j;
	cout<<"Enter Total Nodes : ";
	cin>>nodes;
	cout<<"\nEnter Adjacency Matrix : \n";
	for(i=0; i<nodes; i++)
		for(j=0; j<nodes; j++)
			cin>>graph[i][j];


	for(i=0; i<nodes; i++) {
		for(j=0; j<nodes; j++) {
			if(graph[i][j]==0)
				graph[i][j]=infi;
		}
	}
}

void prims :: primsAlgo() {
	int selected[ROW],i,j,ne;
	int min,x,y;

	for(i=0; i<nodes; i++)
		selected[i]=false;

	selected[0]=true;
	ne=0;

	while(ne < nodes-1) {
		min=infi;

		for(i=0; i<nodes; i++) {
			if(selected[i]==true) {
				for(j=0; j<nodes; j++) {
					if(selected[j]==false) {
						if(min > graph[i][j]) {
							min=graph[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
		selected[y]=true;
		first[tmp]=x+1;
		second[tmp]=y+1;
		tmp++;
		//cout<<"\n"<<x+1<<" ==> "<<y+1;
		ne=ne+1;
	}
	int tmp2=0;
	bool bol= true;
	while(bol){
		bol=false;
		for (int i = 0; i < 14; i++) { 
			if (first[i] > first[i + 1]) { 
				swap(first[i],first[i+1]);
				swap(second[i],second[i+1]);     
		    	bol=true;
			} 
		} 
	}
	for(int i = 3; i<14; i++){
		cout<<"\n"<<first[i]<<" ==> "<<second[i];
	}
}

int main() {
	prims MST;
	MST.createGraph();
	MST.primsAlgo();
}