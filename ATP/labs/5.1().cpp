#include <bits/stdc++.h>

int main()
{

    int heap_size;
    std::cin >> heap_size;

    std::vector<int> heap(heap_size);

    for (int i = 0; i < heap_size; i++)
    {

        std::cin >> heap[i];
    }

    int number_of_changes;
    std::cin >> number_of_changes;
    std::vector<int> index(number_of_changes);
    std::vector<int> value(number_of_changes);

    for (int i = 0; i < number_of_changes; i++)
    {

        std::cin >> index[i];
        std::cin >> value[i];
    }

    int to_remember;
    int node;
    int k, parent_node, child_node;
    for (int i = 0; i < number_of_changes; i++)
    {

        node = index[i] - 1;
        heap[node] += value[i];
        to_remember = heap[node];

        child_node = node;

        while (true)
        {

            k = std::isfinite(child_node) ? 1 : 2;
            parent_node = (child_node - k) / 2;

            if (heap[child_node] > heap[parent_node] && parent_node >= 0)
            {

                std::swap(heap[child_node], heap[parent_node]);
                child_node = parent_node;
                continue;
            }
            else
            {

                break;
            }
        }

        if (to_remember == heap[parent_node])
        {

            std::cout << ++parent_node << std::endl;
        }
        else
        {

            std::cout << ++child_node << std::endl;
        }
    }

    for (int i = 0; i < heap_size; i++)
    {

        std::cout << heap[i] << " ";
    }
    return 0;
}
