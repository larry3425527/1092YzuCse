#include <iostream>
#include <algorithm>
using namespace std;
int n;
int k;
int dp[101][101];

void compute()
{
    for (int i = 0; i < 101; ++i) dp[i][1] = 1;
    for (int i = 0; i < 101; i++) for (int j = 1; j < 101; j++) for (int k = 0; k <= i; k++)
        dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 1000000;
}

int main()
{
    compute();
    while (cin >> n >> k && n != 0 && k != 0) cout << dp[n][k] << '\n';
}