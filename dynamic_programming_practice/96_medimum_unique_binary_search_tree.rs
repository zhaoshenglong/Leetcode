struct Solution;

impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let n = n as usize;
        let mut dp = vec![1; n + 1];

        for i in 2..n + 1 {
            dp[i] = 0;
            for j in 0..i {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        dp[n]
    }
}

fn main() {}
