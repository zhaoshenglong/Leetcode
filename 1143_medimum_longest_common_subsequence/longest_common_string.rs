
struct Solution;

impl Solution {
    pub fn longest_common_string(text1: String, text2: String) -> i32 {
        let m = text1.len();
        let n = text2.len();
        let mut dp: Vec<Vec<i32>> = vec![vec![0; n]; m];
        let mut res = 0;

        for i in 0..m {
            dp[i][0] = (text1.as_bytes()[i] == text2.as_bytes()[0]) as i32;
        }
        for j in 0..n {
            dp[0][j] = (text1.as_bytes()[0] == text2.as_bytes()[j]) as i32;
        }
        
        for i in 1..m {
            for j in 1..n {
                if text1.as_bytes()[i] == text2.as_bytes()[j] {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    res = dp[i][j].max(res);
                }
            }
        }
        res
    }
}

fn main() {
    let t1 = String::from("alsdfkjfjkdsal");
    let t2 = String::from("fdjskalajfkdsla");
    println!("{}\n", Solution::longest_common_string(t1, t2));
}
