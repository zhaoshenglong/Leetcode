struct Solution;

impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let m = word1.len();
        let n = word2.len();
        let mut dp: Vec<Vec<i32>> = vec![vec![0; n + 1]; m + 1];

        for i in 0..m + 1 {
            dp[i][0] = i as i32;
        }

        for j in 0..n + 1{
            dp[0][j] = j as i32;
        }

        println!("{:?}\n", dp);
        for i in 1..m + 1{
            for j in 1..n + 1 {
                if word1.as_bytes()[i - 1] == word2.as_bytes()[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                dp[i][j] = dp[i][j].min(dp[i - 1][j] + 1);
                dp[i][j] = dp[i][j].min(dp[i][j - 1] + 1);
            }
        }

        println!("{:?}\n", dp);
        dp[m][n]
    }
}

fn main() {
    let word1 = String::from("horse");
    let word2 = String::from("ros");
    println!("{}\n", Solution::min_distance(word1, word2));
}
