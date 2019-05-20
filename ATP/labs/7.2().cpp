#include <bits/stdc++.h>

int main(void)
{

    int N;
    std::cin >> N;

    int S;
    std::cin >> S;

    std::vector<int> graf[N];
    int number;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> number;

            if (number != 0)
            {
                graf[i].push_back(j);
            }
        }
    }

    std::list<int> stack;
    bool visited[N];

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

    visited[S - 1] = true;
    stack.push_back(S - 1);
    int counter = 0;

    while (!stack.empty())
    {
        int u = stack.front();
        stack.pop_front();
        int tmp;
        for (int i = 0; i < graf[u].size(); i++)
        {
            tmp = graf[u][i];
            if (visited[tmp] == false)
            {
                visited[tmp] = true;
                stack.push_back(tmp);
                counter++;
            }
        }
    }
    std::cout << ++counter;

    return 0;
}