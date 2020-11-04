#include <iostream>
#include <vector>

class Solution {
	std::vector<int> nums;

public:
    int countPrimes(int n) {
		int i, j, res = 0;

		if (n <= 1) 
			return 0;
		
		nums = std::vector<int>(n);
		fill_nums(n);
		for (i = 1; i + 1 < n; i++) {
			if (nums[i] > 0)
				res++;
			for (j = 2; (i + 1) * j < n; j++)
				nums[(i + 1) * j - 1] = 0;
		}
		return res;
    }

private:
    void fill_nums(int n) {
		int i;

		for (i = 0; i < n; i++)
			nums[i] = i + 1;
    }
};

int main() {
	Solution s = Solution();
	std::cout << s.countPrimes(10) << std::endl;
}
