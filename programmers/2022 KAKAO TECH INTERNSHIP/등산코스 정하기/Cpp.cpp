#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
constexpr int INF = 10000001;

using graph_type = vector<vector<pair<int, int>>>;

graph_type Kruskal(int n, vector<vector<int>>& edges) {
    vector<int> parents(n + 1);
    for (int i = 0; i < parents.size(); i++)
        parents[i] = i;

    auto findParent = [&](int x) {
        while (parents[x] != x)
            x = parents[x];
        return x;
    };
    auto unionParent = [&](int src, int dest) {
        int parA = findParent(src);
        int parB = findParent(dest);
        if (parA < parB) parents[parB] = parA;
        else parents[parA] = parB;
    };

    sort(
        edges.begin(),
        edges.end(),
        [](const vector<int>& left, const vector<int>& right) {
            return left[2] < right[2];
        }
    );

    graph_type graph(n + 1);
    for (int i = 0; i < edges.size(); i++) {
        int src  = edges[i][0];
        int dest = edges[i][1];
        int cost = edges[i][2];

        if (findParent(src) != findParent(dest)) {
            unionParent(src, dest);
            graph[src].emplace_back(dest, cost);
            graph[dest].emplace_back(src, cost);
        }
    }

    return graph;
}

int bfs(
    const graph_type& graph,
    int src,
    const vector<bool>& gatesTable,
    const vector<bool>& summitsTable)
{
    int answer = INF;

    vector<int> costInfo(graph.size(), INF);
    costInfo[src] = 0;

    queue<int> q;
    q.emplace(src);

    while (!q.empty()) {
        int src = q.front();
        int srcCost = costInfo[src];
        q.pop();

        for (auto [dest, cost] : graph[src]) {
            if (costInfo[dest] != INF) 
                continue;

            costInfo[dest] = max(srcCost, cost);

            if (!gatesTable[dest] && !summitsTable[dest]) 
                q.emplace(dest);

            else if (gatesTable[dest])
                answer = min(answer, costInfo[dest]);
        }
    }

    return answer;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    graph_type graph = Kruskal(n, paths);

    vector<bool> summitsTable(n + 1);
    for (int summit : summits) { summitsTable[summit] = true; }

    vector<bool> gatesTable(n + 1);
    for (int gate : gates) { gatesTable[gate] = true; }

    int bestSummit = 0;
    int bestIntensity = INF;

    sort(summits.begin(), summits.end());
    for (int summit : summits) {
        int intensity = bfs(graph, summit, gatesTable, summitsTable);

        if (intensity < bestIntensity) {
            bestIntensity = intensity;
            bestSummit    = summit;
        }
    }

    vector<int> answer = { bestSummit, bestIntensity };
    return answer;
}