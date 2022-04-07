
struct Solution;

impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let sum_nums: i32 = nums.iter().sum();
        let sum_nums: usize = sum_nums as usize;

        if sum_nums & 1 == 1 {
            return false;
        }
        let t = sum_nums >> 1;
        let mut dp = vec![vec![false; t + 1]; n + 1];

        for i in 0..n + 1 {
            dp[i][0] = true;
        }
        for i in 1..n + 1 {
            for j in 1..t + 1 {
                if j >= nums[i - 1] as usize {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1] as usize];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        dp[n][t]
    }
}

fn main() {
    let nums = vec![1,5,5,11];
    println!("{}\n", Solution::can_partition(nums));
}
