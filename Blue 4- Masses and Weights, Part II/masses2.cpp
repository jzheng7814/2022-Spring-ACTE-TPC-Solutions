#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int desired; cin >> desired;
    int coincounts[5] = {}, coinvals[4] = {1, 3, 4};

    for (int i = 1; i <= desired; ++i)
    {
        coincounts[i % 5] = INT_MAX;
        for (int j = 0; j < 3; ++j)
        {
            if (i >= coinvals[j])
            {
                coincounts[i % 5] = min(coincounts[i % 5], coincounts[(i - coinvals[j]) % 5] + 1);
            }
        }
    }

    cout << coincounts[desired % 5] << endl;
}