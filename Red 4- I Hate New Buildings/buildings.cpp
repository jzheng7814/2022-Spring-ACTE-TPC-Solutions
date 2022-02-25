#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;

void sol() 
{
	int N, M; cin >> N >> M;
	vector<string> grid(N);
	for(int i = 0; i < N; i++) cin >> grid[i];

	vector<vector<int>> lft, rgt, up, down;
	lft = rgt = up = down = vector<vector<int>>(N, vector<int>(M));

	for(int i = 0; i < N; i++) 
	{
		for(int j = 0; j < M; j++) 
		{
			if(grid[i][j] != 'X') 
			{
				lft[i][j] = j;
				if(j > 0 && grid[i][j-1] != 'X') lft[i][j] = lft[i][j-1];

				up[i][j] = i;
				if(i > 0 && grid[i-1][j] != 'X') up[i][j] = up[i-1][j];
			}
		}
	}

	for(int i = N-1; i >= 0; i--) 
	{
		for(int j = M-1; j >= 0; j--) 
		{
			if(grid[i][j] != 'X') 
			{
				rgt[i][j] = j;
				if(j+1 < M && grid[i][j+1] != 'X') rgt[i][j] = rgt[i][j+1];

				down[i][j] = i;
				if(i+1 < N && grid[i+1][j] != 'X') down[i][j] = down[i+1][j];
			}
		}
	}

	pii start, end;
	for(int i = 0; i < N; i++) 
	{
		for(int j = 0; j < M; j++) 
		{
			if(grid[i][j] == 'S') start = {i, j};
			if(grid[i][j] == 'E') end = {i, j};
		}
	}

	vector<vector<int>> vis(N, vector<int>(M, -1));
	vis[start.first][start.second] = 0;
	deque<pii> dq;
	dq.push_back(start);

	int iters = 0;
	vector<int> pos;
	while(sz(dq)) 
	{
		pii now = dq.front(); dq.pop_front();
		int x = now.first, y = now.second;

		pos = {lft[x][y], rgt[x][y], up[x][y], down[x][y]};
		for(int k = 0; k < 4; k++) 
		{
			iters++;
			int nx = x, ny = y;
			if(k < 2) ny = pos[k];
			else nx = pos[k];

			if(vis[nx][ny] == -1) 
			{
				vis[nx][ny] = 1+vis[x][y];
				dq.push_back({nx, ny});
			}
		}
	}

	cout << vis[end.first][end.second] << '\n';

}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	sol();

	return 0;
}
