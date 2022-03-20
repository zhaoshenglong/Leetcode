#include "../../include/leetcode.hpp"
const int BITS = 20;
const int MASK = 0xfffff;

static inline unsigned long long encode(long long node, int dist) {    
    return (node << BITS) | (dist & MASK);
}

static inline unsigned int getNode(unsigned long long code) {
    return (code >> BITS) & MASK;
}

static inline unsigned int getDist(unsigned long long code) {
    return code & MASK;
}

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size(), m = edges.size();
        vector<vector<int>> adjList(n, vector<int>({}));
        int i; 

        for (i = 0; i < m; i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        // find dist using bfs
        queue<unsigned long long > nodes;
        unsigned long long code;
        int maxCost = 0;
        int p, r, cost;
        
        nodes.push(0);
        while (!nodes.empty()) {
            code = nodes.front();
            nodes.pop();
            
            int d = getDist(code);
            int node = getNode(code);
            for (int n: adjList[node]) {
                if (patience[n] > 0) {
                    p = patience[n];
                    r = (d + 1) << 1;
                    if (p >= r) {
                        cost = r;
                    } else {
                        cost = r + r - (r % p);
                        if (r % p == 0)
                            cost -= p;
                    }
                    if (cost > maxCost)
                        maxCost = cost;
                    nodes.push(encode(n, d + 1));
                    patience[n] = -patience[n];
                }
            }
        }

        return maxCost + 1;
    }
};

int main() {
    auto edges = vector<vector<int>>({{5,7},{15,18},{12,6},{5,1},{11,17},{3,9},{6,11},{14,7},{19,13},{13,3},{4,12},{9,15},{2,10},{18,4},{5,14},{17,5},{16,2},{7,1},{0,16},{10,19},{1,8}});
    auto patience = vector<int>({0,2,1,1,1,2,2,2,2,1,1,1,2,1,1,1,1,2,1,1});
    Solution sol;

    cout << sol.networkBecomesIdle(edges, patience) << endl;
}
