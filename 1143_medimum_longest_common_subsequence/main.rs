
struct Solution;

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let m = text1.len();
        let n = text2.len();
        let mut dp: Vec<Vec<i32>> = Vec::new();

        dp.resize_with(m, || {let mut v = Vec::new(); v.resize(n, 0); v});
        dp[0][0] = (text1[0..1] == text2[0..1]) as i32;
        for i in 1..m {
            dp[i][0] = (text1[i..i + 1] == text2[0..1]) as i32;
            dp[i][0] = dp[i][0].max(dp[i - 1][0]);
        }
        for j in 1..n {
            dp[0][j] = (text1[0..1] == text2[j..j + 1]) as i32;
            dp[0][j] = dp[0][j].max(dp[0][j - 1]);
        }

        for i in 1..m {
            for j in 1..n {
                if text1[i..i + 1] == text2[j..j + 1] {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]).max(dp[i - 1][j - 1]);
                }
            }
        }
        println!("{:?}", &dp);
        dp[m - 1][n - 1]
    }
}

fn main() {
    let t1 = String::from("abcde");
    let t2 = String::from("ace");
    println!("{}\n", Solution::longest_common_subsequence(t1, t2));
}
