#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int find_peak(vector<int>& height, int start, int hi, int &height_sum) {
        int i = start;
        bool increasing = false;
        
        for (; i < hi; i++) {
            height_sum += height[i];
            if (height[i + 1] > height[i])
                increasing = true;
            
            if (increasing && height[i + 1] < height[i])
                return i;
        }
        return hi;
    }

    int sum_peaks(vector<int> &height, int st, int end) {
        int i = st;
        int full_sum;
        int bd_height = height[st] >= height[end] ? height[end] : height[st];
        int res = 0;

        full_sum = bd_height * (end - st + 1);
        res += full_sum;
        for (i = st; i <= end; i++) 
            res -= height[i] > bd_height ? bd_height : height[i];
        return res;
    }

    int trap(vector<int>& height) {
        int sz = height.size();
        int height_sum = 0;
        int res = 0;
        int i = 0;
        int peak_start, peak_end, max_peak_end;


        height.push_back(0);
        while (i < sz && height[i + 1] >= height[i])
            i++;

        if (i >= sz)
            return 0;

        peak_start = i;
        height_sum = height[peak_start];
        while (true) {
            peak_end = find_peak(height, peak_start + 1, sz, height_sum);
            if (peak_end >= sz)
                break;

            if (height[peak_end] < height[peak_start]) {
                max_peak_end = peak_end;
                
                peak_end = find_peak(height, peak_end + 1, sz, height_sum);
                while (peak_end < sz && height[peak_end] < height[peak_start]) {
                    if (height[peak_end] > height[max_peak_end])
                        max_peak_end = peak_end;
                    peak_end = find_peak(height, peak_end + 1, sz, height_sum);
                }
                if (peak_end < sz)
                    max_peak_end = peak_end;
                res += sum_peaks(height, peak_start, max_peak_end);
                
                peak_start = max_peak_end;
                height_sum = height[peak_start];
            } else {
                res += height[peak_start] * (peak_end - peak_start + 1) - height_sum;
                for (i = peak_end; i > peak_start; i--) {
                    if (height[i] >= height[peak_start])
                        res += (height[i] - height[peak_start]);
                    else
                        break;
                } 
                peak_start = peak_end;
                height_sum = height[peak_start];
            }

        }
        
        height.pop_back();
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height(arr, arr + 12);

    cout << s.trap(height) << endl;
}
