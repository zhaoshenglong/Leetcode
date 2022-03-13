#include "../../include/leetcode.hpp"

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (n - 1 == hour || n - 1 > int(hour))
            return -1;

        int lo = 1, hi = getMaxSpeed(dist, hour) + 1;
        while(lo < hi) {
            int mid = (lo + hi) >> 1;
            int flag = isValid(dist, hour, mid);
            if(flag > 0)
                hi = mid;
            else
                lo = mid + 1;
        }
        if (lo >= hi)
            return lo;
        return -1;
    }

    int getMaxSpeed(vector<int>& dist, double hour) {
        int speed = dist[0];
        for (auto d: dist)
            if (d > speed)
                speed = d;

        if (hour != int(hour)) {
            int s = dist.back() / (hour - int(hour)) + 1;
            if ( s > speed)
                speed = s;
        }
        return speed;
    }

    int isValid(vector<int>& dist, double hour, int speed) {
        int n = dist.size();
        int elapsed = 0;
        int i;

        for (i = 0; i < n - 1; i++) {
            elapsed += (dist[i] + speed - 1) / speed;
        }
        if (elapsed >= hour)
            return -1;
        float remain = hour - elapsed;
        if (speed * remain >= dist.back())
            return 1;
        else
            return -1;
    }
};

int main() {
    Solution sol;
    auto dist = vector<int>({1, 3, 100000});
    double hour = 2.01;
    cout << sol.minSpeedOnTime(dist, hour) << endl;
    return 0;
}
