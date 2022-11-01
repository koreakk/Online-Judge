#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

using POSITION = pair<int, int>;
using NODE     = pair<int, POSITION>;
using PQ       = priority_queue<NODE, vector<NODE>, greater<NODE>>;
int dist[160][160];

int solution(int alp, int cop, vector<vector<int>> problems) {
    memset(dist, -1, sizeof(dist));
    dist[alp][cop] = 0;

    vector<int> p1 = { 0, 0, 1, 0, 1 };
    vector<int> p2 = { 0, 0, 0, 1, 1 };
    problems.emplace_back(p1);
    problems.emplace_back(p2);

    int max_alp = alp;
    int max_cop = cop;

    for (const auto& problem : problems) {
        max_alp = max(max_alp, problem[0]);
        max_cop = max(max_cop, problem[1]);
    }

    if (max_alp <= alp && max_cop <= cop) {
        return 0;
    }

    PQ pq;
    pq.emplace(0, make_pair(alp, cop));

    while (!pq.empty()) {
        auto [curr_cost, curr_pos] = pq.top();
        auto [curr_alp, curr_cop]  = curr_pos;
        pq.pop();

        if (dist[curr_alp][curr_cop] == -1 ||
            dist[curr_alp][curr_cop] >= curr_cost)
        {
            for (const auto& problem : problems) {
                int alp_req = problem[0];
                int cop_req = problem[1];
                int alp_rwd = problem[2];
                int cop_rwd = problem[3];
                int cost    = problem[4];

                if ((alp_rwd == 0 && cop_rwd == 0) ||
                    (alp_req > curr_alp || cop_req > curr_cop))
                {
                    continue;
                }

                int next_alp  = min(curr_alp + alp_rwd, max_alp);
                int next_cop  = min(curr_cop + cop_rwd, max_cop);
                int next_cost = curr_cost + cost;

                if (dist[next_alp][next_cop] == -1 ||
                    dist[next_alp][next_cop] > next_cost)
                {
                    dist[next_alp][next_cop] = next_cost;
                    pq.emplace(next_cost, make_pair(next_alp, next_cop));
                }
            }
        }
    }

    return dist[max_alp][max_cop];
}
