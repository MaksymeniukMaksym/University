#include <bits/stdc++.h>

using namespace std;



bool BFS(vector<int> arr[], int start, int finish, int top, int min[], int max[])
{

    list<int> queue;
    bool cheked[top];

    for (int i = 0; i < top; i++)
    {
        cheked[i] = false;
        max[i] = INT_MAX;
        min[i] = -1;
    }

    max[start] = 0;
    cheked[start] = true;
    queue.push_back(start);

    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop_front();

        for (int i = 0; i < arr[u].size(); i++)
        {
            if (cheked[arr[u][i]] == false)
            {
                cheked[arr[u][i]] = true;
                max[arr[u][i]] = max[u] + 1;
                min[arr[u][i]] = u;

                queue.push_back(arr[u][i]);

                if (arr[u][i] == finish)
                {
                    return true;
                }
            }
        }
    }

    return false;
}


void printShortestDistance(vector<int> arr[], int lenght, int finish, int top)
{

    int pred[top], dist[top];

    if (BFS(arr, lenght, finish, top, pred, dist) == false)
    {
        if (lenght == finish)
        {
            printf("0\n");
        }
        else
        {
            printf("-1\n");
        }
        return;
    }

    vector<int> path;
    int crawl = finish;
    path.push_back(crawl);
    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    printf("%d\n", dist[finish]);

    for (int i = path.size() - 1; i >= 0; i--)
    {
        printf("%d ", ++path[i]);
    }
}


int main()
{
    int top;
    scanf("%d", &top);

    vector<int> arr[top];

    int number;

    for (int i = 0; i < top; i++)
    {
        for (int j = 0; j < top; j++)
        {
            scanf("%d", &number);

            if (number)
            {
            arr[i].push_back(j);
            }
        }
    }

    int start, finish;

    scanf("%d %d", &start, &finish);

    printShortestDistance(arr, start - 1, finish - 1, top);
    return 0;
}