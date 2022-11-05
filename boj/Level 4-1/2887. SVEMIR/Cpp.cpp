#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>   
using namespace std;

struct Point {
    int x, y, z;
    int v;
};

struct Node {
    int v, u, w;
};

int FindParent(vector<int>& parents, int v) {
    if (parents[v] == v) return v;
    return parents[v] = FindParent(parents, parents[v]);
}

void UnionParent(vector<int>& parents, int v, int u) {
    v = FindParent(parents, v);
    u = FindParent(parents, u);
    if (v < u) parents[u] = v;
    else parents[v] = u;
}

int Kruskal(int n, vector<Node>& edges) {
    vector<int> parents(n);
    for (int i = 0; i < n; i++)
        parents[i] = i;

    sort(
        edges.begin(), edges.end(),
        [](const Node& l, const Node& r) {
            return l.w < r.w;
        }
    );

    int answer = 0;
    for (const auto& [v, u, w] : edges) {
        if (FindParent(parents, v) != FindParent(parents, u)) {
            UnionParent(parents, v, u);
            answer += w;
        }
    }

    return answer;
}

int GetDistance(const Point& l, const Point& r) {
    return min(abs(l.x - r.x), min(abs(l.y - r.y), abs(l.z - r.z)));
}

void solve() {
    int N;
    cin >> N;

    vector<Point> info(N);
    for (int i = 0; i < N; ++i) {
        cin >> info[i].x >>
               info[i].y >>
               info[i].z;

        info[i].v = i;
    }
    
    auto xCompare = [](const Point& l, const Point& r) { return l.x < r.x; };
    auto yCompare = [](const Point& l, const Point& r) { return l.y < r.y; };
    auto zCompare = [](const Point& l, const Point& r) { return l.z < r.z; };

    vector<Node> edges;
    
    sort(info.begin(), info.end(), xCompare);
    for (int i = 0; i < N - 1; ++i) {
        const Point& A = info[i];
        const Point& B = info[i + 1];

        edges.push_back({ A.v, B.v, GetDistance(A, B) });
    }

    sort(info.begin(), info.end(), yCompare);
    for (int i = 0; i < N - 1; ++i) {
        const Point& A = info[i];
        const Point& B = info[i + 1];

        edges.push_back({ A.v, B.v, GetDistance(A, B) });
    }

    sort(info.begin(), info.end(), zCompare);
    for (int i = 0; i < N - 1; ++i) {
        const Point& A = info[i];
        const Point& B = info[i + 1];

        edges.push_back({ A.v, B.v, GetDistance(A, B) });
    }

    cout << Kruskal(N, edges) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
