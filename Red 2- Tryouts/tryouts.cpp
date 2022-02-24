#include <bits/stdc++.h>

using namespace std;

int N, T, D[10000];

bool ok(int x)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int time = 0;

    for (int i = 0; i < N; ++i)
    {
        if (pq.size() == x)
        {
            time = pq.top(); pq.pop();
        }

        if (time + D[i] > T)
        {
            return false;
        }

        pq.push(time + D[i]);
    }

    return true;
}

int main()
{
    cin >> N >> T;
    for (int i = 0; i < N; ++i)
    {
        cin >> D[i];
    }

    int x = 0;
    for (int b = N; b > 0; b /= 2)
    {
        for(  ; !ok(x + b); x += b);
    }

    cout << x + 1 << endl;
}