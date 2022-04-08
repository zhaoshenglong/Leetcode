struct Solution;

impl Solution {
    pub fn super_egg_drop(k: i32, n: i32) -> i32 {
        let k = k as usize;
        let n = n as usize;
        let mut dp: Vec<Vec<i32>> = vec![vec![0; k + 1]; n + 1];

        for i in 1..n + 1 {
            dp[i][1] = i as i32;
        }
        for i in 1..n + 1 {
            for j in 2..k + 1 {
                dp[i][j] = i as i32;
                for x in 1..i + 1 {
                    dp[i][j] = dp[i][j].min(dp[x - 1][j - 1].max(dp[i - x][j]));
                }
                dp[i][j] += 1;
            }
        }

        dp[n][k]
    }
}

fn main() {
    let k = 7;
    let n = 5000;
    println!("{}", Solution::super_egg_drop(k, n));
}
