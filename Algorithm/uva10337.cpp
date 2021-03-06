#include <iostream>
#include <algorithm>
using namespace std;

// reference: https://ppt.cc/fzYlzx
const int inf(1e9);
int Case;
int dp[1000][10];
int wind[1000][10];
int X;

void read()
{
	cin >> X;
	X /= 100;
	for (int i = 9; i >= 0; i--)
		for (int j = 0; j < X; j++) cin >> wind[j][i], dp[j][i] = inf;
}

void solve()
{
	dp[0][0] = 0;
	for (int i = 1; i <= X; i++) for (int j = 0; j < 10; j++)
	{
		int mn = inf;
		if (j > 0)
		{
			mn = min(dp[i - 1][j] + 30 - wind[i - 1][j], mn);    // i-1 -> i平飛
			mn = min(dp[i - 1][j - 1] + 60 - wind[i - 1][j - 1], mn); // 上飛          
		}
		if (j < 9)
		{
			mn = min(dp[i - 1][j + 1] + 20 - wind[i - 1][j + 1], mn); //下飛
		}
		dp[i][j] = mn;
	}
	cout << dp[X][0] << endl << endl;

}

int main()
{
	cin >> Case;
	while (Case--)
	{
		read();
		solve();
	}
}