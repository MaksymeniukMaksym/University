#include<iostream>
#include<vector>

void up(std::vector<int> &heap,int index,int num_of_index){

int child;
child = index;
int parent;

while(true){

    if(child % 2 == 0 ){
        parent = (child - 1)/2;
    }else parent = (child - 2 )/2;

    if ((heap[child] > heap[parent]) && parent >= 0){

      std::swap(heap[parent],heap[child]);

      child = parent;

    }else {

        break;
    }
}
     ;
if (num_of_index == heap[parent]) {

        std::cout<< parent + 1<<std::endl;

    } else {

        std::cout<<child + 1<< std::endl;

    }

}

int main(void){

    int size;
    std::cin>>size;
 
    std::vector<int> heap;
    heap.reserve(size);
    for(int i = 0; i < size; i++){

        std::cin>>heap[i];
    }
    int changes;
    std::cin>>changes;
   
    int changes_value[changes][2];

    for(int i = 0; i < changes; i++){
        std::cin>>changes_value[i][0];
        std::cin>>changes_value[i][1];
    }
    int index,num_of_index;
   
    for(int i = 0; i < changes; i++){
        
        index = changes_value[i][0] - 1;

        heap[index] += changes_value[i][1];
        
        num_of_index = heap[index];

        up(heap, index, num_of_index);
    }
     
         for (int i = 0; i <size; i++) {

       std::cout<<heap[i]<<" ";
         }

    return 0;
}