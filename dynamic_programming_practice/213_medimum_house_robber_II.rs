impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 1 {
            return nums[0];
        }
        if n == 2 {
            return nums[0].max(nums[1]);
        }

        let mut dp = vec![nums[0], nums[0]];
        let mut res = 0;
        for i in 2..n - 1 {
            let tmp = dp[1].max(dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }

        res = res.max(dp[1]);
        dp = vec![0, nums[1]];
        for i in 2..n {
            let tmp = dp[1].max(dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        res.max(dp[1])
    }
}
