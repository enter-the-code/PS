#include  <iostream>
#include  <algorithm>
using namespace std;
int Train[50001];
int Dp[4][50001];
int main()
{
    int N, M;
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int temp;
        cin >> temp;
        Train[i] = Train[i - 1] + temp;
    }
    cin >> M;
 
    for (int i = 1; i <= 3; ++i)
        for (int j = i * M; j <= N; ++j)
            Dp[i][j] = max(Dp[i][j-1], (Train[j] - Train[j - M]) + Dp[i - 1][j - M]);
 
    cout << Dp[3][N];
    return 0;
}