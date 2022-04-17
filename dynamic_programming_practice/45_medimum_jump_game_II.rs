struct Solution;

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![n; n];

        dp[0] = 0;
        for i in 0..n {
            for j in i+1..n.min(i + 1 + nums[i] as usize) {
                dp[j] = dp[j].min(dp[i] + 1);
            }
        }
        dp[n - 1] as i32
    }
}

fn main() {}
