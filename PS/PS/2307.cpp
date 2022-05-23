#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#define MAX 100
#define INF 99999999
using namespace std;
vector<pair<int, int>> graph[1001];
int N, M;
vector<int> dist(1001, INF);
vector<pair<int, int>> greedy_way;
void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i <= N; i++)
        dist[i] = INF;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nCost = cost + graph[cur][i].second;
            if (nCost < dist[next])
            {
                dist[next] = nCost;
                pq.push(make_pair(-nCost, next));
                greedy_way.push_back({cur, next});
            }
        }
    }

    return;
}
void another_dijkstra(int start, pair<int, int> tmp)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i <= N; i++)
        dist[i] = INF;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nCost = cost + graph[cur][i].second;
            if (!(cur == tmp.second && next == tmp.first) && !(cur == tmp.first && next == tmp.second) && nCost < dist[next])
            {
                dist[next] = nCost;
                pq.push(make_pair(-nCost, next));
            }
        }
    }

    return;
}

int main()
{
    cin >> N;
    cin >> M;
    int min = INF;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    dijkstra(1);
    min = dist[N];
    int result = 0;
    if (min == INF)
    {
        cout << 0 << "\n";
    }
    for (auto i : greedy_way)
    {
        another_dijkstra(1, i);
        if (dist[N] == INF)
        {
            cout << -1 << "\n";
            return 0;
        }
        else
        {
            result = max(result, dist[N] - min);
        }
    }
    cout << result << "\n";
    return 0;
}