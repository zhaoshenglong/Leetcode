struct Solution;

impl Solution {
    pub fn max_coins(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        // dp[k][i] => maximum coins of
        // k-length nums start from i 
        let mut dp = vec![vec![0; n + 2]; n + 1];
        let mut nums = nums;
        nums.insert(0, 1);
        nums.push(1);

        for k in 1..n + 1 {
            for i in 1..n + 2 - k {
                for j in i..i + k {
                    let left = dp[j - i][i];
                    let right = dp[i + k - j - 1][j + 1];
                    let product = nums[i - 1] * nums[j] * nums[i + k];
                    dp[k][i] = dp[k][i].max(left + product + right);
                }
            }
        }

        println!("{:?}", dp);
        dp[n][1]
    }
}

fn main() {
    let nums = vec![3, 1, 5, 8];
    println!("{}", Solution::max_coins(nums));
}
