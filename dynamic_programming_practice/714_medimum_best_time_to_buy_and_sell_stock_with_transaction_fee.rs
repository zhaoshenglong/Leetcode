struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>, fee: i32) -> i32 {
        let n = prices.len();
        let mut dp = vec![vec![0; n], vec![0; n]];

        dp[1][0] = -prices[0];
        for i in 1..n {
            dp[0][i] = dp[0][i - 1].max(dp[1][i - 1] + prices[i] - fee);
            dp[1][i] = dp[1][i - 1].max(dp[0][i - 1] - prices[i]);
        }

        dp[0][n - 1]
    }
}

fn main {}
