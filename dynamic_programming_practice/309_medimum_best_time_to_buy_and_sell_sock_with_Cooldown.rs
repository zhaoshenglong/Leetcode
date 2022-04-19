struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let n = prices.len();
        let mut dp = vec![vec![0; n], vec![0; n]];

        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        dp[0][1] = dp[0][0].max(dp[1][0] + prices[1]);
        dp[1][1] = dp[1][0].max(dp[0][0] - prices[1]);
        for i in 2..n {
            dp[0][i] = dp[0][i - 1].max(dp[1][i - 1] + prices[i]);
            if dp[0][i - 1] == dp[0][i - 2] {
                dp[1][i] = dp[1][i - 1].max(dp[0][i - 1] - prices[i]);
            } else {
                dp[1][i] = dp[1][i - 1].max(dp[0][i - 2] - prices[i]);
            }
        }

        dp[0][n - 1]
    }
}

fn main() {}
