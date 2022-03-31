#include "../../include/leetcode.hpp"


class Comp
{
    bool loadComp;

public:
    Comp(const bool& loadComp=false) {
        this->loadComp = loadComp;
    }

    bool operator()(pair<int, int> left, pair<int, int> right) {
        if (loadComp)
            return left.second > right.second;
        return left.first > right.first;
    }
};


typedef priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int mostBusy = 0;
        pq lowFree(Comp(false));
        pq highFree(Comp(false));
        pq workQueue(Comp(true));
        vector<int> res;
        int i;

        if (k >= arrival.size()) {
            res.resize(arrival.size());
            for(i = 0; i < arrival.size(); i++)
                res[i] = i;
            return res;
        }

        for (i = 0; i < k; i++) {
            workQueue.push({i, arrival[i] + load[i]});
            arrival[i] = 1;
        }

        for (; i < arrival.size(); i++) {
            // cout << "i = " << i << endl;
            checkFree(lowFree, highFree, workQueue, arrival[i], i % k, k);
            if (!highFree.empty()) {
                auto [idx, _] = highFree.top();
                highFree.pop();
                arrival[idx]++;
                if (arrival[idx] > mostBusy)
                    mostBusy = arrival[idx];
                workQueue.push({idx, arrival[i] + load[i]});
                // cout << "high push idx = " << idx << " load " << arrival[i] + load[i] << endl;
            } else if (!lowFree.empty()) {
                auto [idx, _] = lowFree.top();
                lowFree.pop();
                arrival[idx]++;
                if (arrival[idx] > mostBusy)
                    mostBusy = arrival[idx];
                workQueue.push({idx, arrival[i] + load[i]});
                // cout << "low push idx = " << idx << " load " << arrival[i] + load[i] << endl;
            }
            // abandon
        }

        for (i = 0; i < k; i++)
            if (arrival[i] == mostBusy)
                res.push_back(i);
        return res;
    }

    void checkFree(pq& lowFree, pq& highFree, pq& workQueue, int arrival, int i, int k) {
        // check if i equals to 0
        if (i == 0) {
            highFree.swap(lowFree);
            while (!lowFree.empty()) {
                highFree.push(lowFree.top());
                lowFree.pop();
            }
        } else {
            // move from highFree to lowFree
            while(!highFree.empty()) {
                auto [idx, load] = highFree.top();
                if (idx < i) {
                    highFree.pop();
                    lowFree.push({idx, load});
                    continue;
                }
                break;
            }
        }

        while(!workQueue.empty()) {
            auto [idx, load] = workQueue.top();

            if (load <= arrival) {
                // cout << "top: " << idx << ", " << load << ", i: " << i << endl;
                workQueue.pop();
                if (idx >= i) {
                    highFree.push({idx, load});
                } else {
                    lowFree.push({idx, load});
                }
                continue;
            }
            break;
        }
    }
};

