#include <iostream>
#include <numeric>
#include <climits>

using namespace std;

int N, graph[100][100], dist[101];
bool tree[100];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        dist[i] = INT_MAX;
    }

    dist[100] = INT_MAX;
    dist[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        int minIndex = 100;
        for (int j = 0; j < N; ++j)
        {
            if (!tree[j] && dist[j] < dist[minIndex])
            {
                minIndex = j;
            }
        }

        tree[minIndex] = true;

        for (int j = 0; j < N; ++j)
        {
            if (!tree[j])
            {
                dist[j] = min(dist[j], graph[minIndex][j]);
            }
        }
    }

    cout << accumulate(dist, dist + N, 0) << endl;
}