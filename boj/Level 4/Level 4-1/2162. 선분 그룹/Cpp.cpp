#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Point { long long x, y; };
struct Line  { Point     s, e; };

bool operator<=(const Point& left, const Point& right) {
    if (left.x == right.x) {
        return left.y <= right.y;
    }
    return left.x <= right.x;
}

int ccw(const Point& p1, const Point& p2, const Point& p3) {
    long long d = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    return (d > 0) ? 1 : (d < 0) ? -1 : 0;
}

bool lineSegmentIntersection(const Line& Al, const Line& Bl) {
    Point s1 = Al.s, e1 = Al.e;
    Point s2 = Bl.s, e2 = Bl.e;

    int d1 = ccw(s1, e1, s2), d2 = ccw(s1, e1, e2);
    if (d1 == 0 && d2 == 0) {
        if (e1 <= s1) swap(s1, e1);
        if (e2 <= s2) swap(s2, e2);

        return s1 <= e2 && s2 <= e1;
    }

    return ccw(s2, e2, s1) != ccw(s2, e2, e1) && d1 != d2;
}

int Find(vector<int>& parents, int v) {
    if (parents[v] == v) { return v; }
    return parents[v] = Find(parents, parents[v]);
}

void Union(vector<int>& parents, int v, int u) {
    v = Find(parents, v);
    u = Find(parents, u);
    if (v < u) { parents[u] = v; }
    else parents[v] = u;
}

int main() {
    int N;
    cin >> N;

    vector<Line> info(N);
    for (int i = 0; i < N; ++i) {
        Point &s = info[i].s, &e = info[i].e;
        cin >> s.x >> s.y >> e.x >> e.y;
    }

    vector<int> parents(N);
    for (int i = 0; i < N; ++i) {
        parents[i] = i;
    }

    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (Find(parents, i) != Find(parents, j) &&
                lineSegmentIntersection(info[i], info[j]))
            {
                Union(parents, i, j);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        parents[i] = Find(parents, parents[i]);
    }

    vector<int> count(N);
    for (int i = 0; i < N; ++i) {
        ++count[parents[i]];
    }

    int group_count = 0, max_count = 0;
    for (int i = 0; i < N; ++i) {
        if (count[i] != 0) { ++group_count; }
        max_count = max(max_count, count[i]);
    }

    cout << group_count << '\n';
    cout << max_count   << '\n';

    return 0;
}
