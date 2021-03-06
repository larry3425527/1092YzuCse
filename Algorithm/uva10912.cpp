#include <iostream>
using namespace std;
int dp[27][27][355];
int L, S, cases;
void compute()
{
    for (int i = 1; i <= 26; ++i) dp[i][1][i] = 1;  //dp[i][1][i]�զX���u���@�� ex:dp[1][1][1] = 1
    for (int i = 1; i <= 26; ++i) for (int j = 1; j <= i; ++j)
    {
        for (int k = 1 ; k <= 351; ++k)
        {
            dp[i][j][k] += dp[i - 1][j][k];
            // �P�_�O�_��N i ���W
            if (j > 0 && k >= i) dp[i][j][k] += dp[i - 1][j - 1][k - i];
        }
    }
}

int main()
{
    compute();
    while (cin >> L >> S && L&& S)
    {
        cout << "Case " << ++cases << ": ";
        // �ѩ��Y�滼�W�A�]���̦h 26 �Ӧr���AS �̤j�� 351
        if (L > 26 || S > 351) cout << "0\n";
        else cout << dp[26][L][S] << '\n';
    }
	return 0;
}