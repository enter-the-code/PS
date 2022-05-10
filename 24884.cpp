#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <deque>
#include <cstring>
using namespace std;
typedef long long ll;
int modak_count;
int start;
int least_modak;
int modak_time;
int res;
void check_c(vector<int> v)
{
    int count1 = 0;
    for (auto i : v)
    {
        if (i)
        {
            count1++;
        }
    }
    if (count1 >= least_modak)
    {
        res++;
    }
}

void solve(vector<int> v, int now_time, int now_point)
{
    if (now_time == modak_time)
    {
        check_c(v);
    }
    else
    {
        vector<int> minus_val(modak_count), vec = v;
        for (int i = 0; i < modak_count; i++)
        {
            minus_val[i] = 3;
            if (i > 0)
            {
                if (vec[i - 1])
                    minus_val[i]--;
            }
            if (i < modak_count - 1)
            {
                if (vec[i + 1])
                    minus_val[i]--;
            }
        }

        for (int i = 0; i < modak_count; i++)
        {
            vec[i] -= minus_val[i];
            vec[i] = max(0, vec[i]);
        }
        vec[now_point] = v[now_point];
        solve(vec, now_time + 1, now_point);
        vec = v;
        int m = now_point - 1;
        if (m >= 0)
        {
            for (int i = 0; i < modak_count; i++)
            {
                minus_val[i] = 3;
                if (i > 0)
                {
                    if (vec[i - 1])
                        minus_val[i]--;
                }
                if (i < modak_count - 1)
                {
                    if (vec[i + 1])
                        minus_val[i]--;
                }
            }

            for (int i = 0; i < modak_count; i++)
            {
                vec[i] -= minus_val[i];
                vec[i] = max(0, vec[i]);
            }
            vec[m] = v[m];
            solve(vec, now_time + 1, m);
        }
        vec = v;
        int l = now_point + 1;
        if (l < modak_count)
        {
            for (int i = 0; i < modak_count; i++)
            {
                minus_val[i] = 3;
                if (i > 0)
                {
                    if (vec[i - 1])
                        minus_val[i]--;
                }
                if (i < modak_count - 1)
                {
                    if (vec[i + 1])
                        minus_val[i]--;
                }
            }

            for (int i = 0; i < modak_count; i++)
            {
                vec[i] -= minus_val[i];
                vec[i] = max(0, vec[i]);
            }
            vec[l] = v[l];
            solve(vec, now_time + 1, l);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> modak_count >> start >> modak_time >> least_modak;
    vector<int> modacbol;
    for (int i = 0; i < modak_count; i++)
    {
        int a;
        cin >> a;
        modacbol.push_back(a);
    }
    int t = 0;
    vector<int> minus_val(modak_count);
    for (int i = 0; i < modak_count; i++)
    {
        minus_val[i] = 3;
        if (i > 0)
        {
            if (modacbol[i - 1])
                minus_val[i]--;
        }
        if (i < modak_count - 1)
        {
            if (modacbol[i + 1])
                minus_val[i]--;
        }
    }
    for (int i = 0; i < modak_count; i++)
    {
        modacbol[i] -= minus_val[i];
        modacbol[i] = max(0, modacbol[i]);
    }
    solve(modacbol, t + 1, start);
    cout << res << "\n";

    return 0;
}