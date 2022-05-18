#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>
#include<map>
using namespace std;
string dp[1001];
map<char, char> m;

bool who_is_win(string a, string b) {
    if (a==""&&b=="")
    {
        return false;
    }
    if (a=="")
    {
        return true;
    }
    if (a.size() > b.size()) {
        return true;
    }
    else if(a.size()==b.size()) {
        string first = "";
        string second = "";
        for (auto i : a) {
            first += m[i];
        }
        for (auto i : b) {
            second += m[i];
        }
        if (first>second)
        {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void solve() {
    m['('] = '1';
    m[')'] = '2';
    m['{'] = '3';
    m['}'] = '4';
    m['['] = '5';
    m[']'] = '6';
    dp[1] = "()";
    dp[2] = "{}";
    dp[3] = "[]";

    for (int i = 4; i < 1001; i++)
    {
        if (i % 2==0 && who_is_win(dp[i], '(' + dp[i / 2] + ')'))
        {
            dp[i] = '(' + dp[i / 2] + ')';
        }
        if (i % 3 ==0 && who_is_win(dp[i], '{' + dp[i / 3] + '}'))
        {
            dp[i] = '{' + dp[i / 3] + '}';
        }
        if (i % 5 ==0  && who_is_win(dp[i], '[' + dp[i / 5] + ']'))
        {
            dp[i] = '[' + dp[i / 5] + ']';
        }

        for (int j = 1; j <= i; j++)
        {
            if (who_is_win(dp[i], dp[i - j] + dp[j])) {
                dp[i] = dp[i - j] + dp[j];
            }
        }

    }

}

int T, N;
int main() {
    cin >> T;
    solve();
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << dp[N] << "\n";
    }
    return 0;
}