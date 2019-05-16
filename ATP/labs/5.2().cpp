#include <bits/stdc++.h>

void sift_down(std::vector<int> &heap, int heap_size, int to_remember);

int main()
{

    int heap_size;
  
    std::cin>>heap_size;

    std::vector<int> heap(heap_size);

    for (int i = 0; i < heap_size; i++)
    {
        std::cin>>heap[i];
    }

    int number_of_changes;
    std::cin>>number_of_changes;


    std::vector<int> index(number_of_changes);
 
    std::vector<int> value(number_of_changes);

    for (int i = 0; i < number_of_changes; i++)
    {
        std::cin>>index[i];
        std::cin>>value[i];
    }

    int parent_node;
    int to_remember;

    for (int i = 0; i < number_of_changes; i++)
    {
        parent_node = index[i] - 1;
        heap[parent_node] -= value[i];
        to_remember = heap[parent_node];

        sift_down(heap, parent_node, to_remember);
    }

    for (int i = 0; i < heap.size(); i++)
    {
        std::cout<<heap[i]<<" ";
    }
}

void sift_down(std::vector<int> &heap, int node, int to_remember)
{
    int parent_node = node;
    int left_child;
    int right_child;

    while (true)
    {
     
        left_child = (parent_node * 2) + 1;
        right_child = (parent_node * 2) + 2;


        if (left_child >= heap.size())
        {
            break;
        }

        if (heap[parent_node] > heap[left_child] && heap[parent_node] > heap[right_child] && right_child < heap.size())
        {
            break;
        }

        if (heap[parent_node] > heap[left_child] && right_child >= heap.size())
        {
            break;
        }

        if (heap[right_child] > heap[left_child] && heap[right_child] > heap[parent_node] && right_child < heap.size())
        {
            std::swap(heap[parent_node], heap[right_child]);
            parent_node = right_child;
            continue;
        }
        else
        {
            std::swap(heap[parent_node], heap[left_child]);
            parent_node = left_child;
            continue;
        }
    }

    if (to_remember == heap[parent_node])
    {
        std::cout<<++parent_node<<std::endl;
    }
    else if (to_remember == heap[left_child])
    {
        std::cout<<++left_child<<std::endl;
    }
    else
    {
        std::cout<<++right_child<<std::endl;
    }
}