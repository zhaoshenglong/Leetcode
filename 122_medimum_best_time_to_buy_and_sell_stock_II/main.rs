struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let n = prices.len();
        let mut dp = vec![vec![0; n]; 2];

        dp[1][0] = -prices[0];
        for j in 1..n {
            dp[0][j] = dp[0][j - 1].max(dp[1][j - 1] + prices[j]);
            dp[1][j] = dp[1][j - 1].max(dp[0][j - 1] - prices[j]);
        }

        println!("{:?}", dp);
        dp[0][n - 1]
    }
}

fn main() {
    let prices = vec![7,1,5,3,6,4];
    println!("{}", Solution::max_profit(prices));
}
