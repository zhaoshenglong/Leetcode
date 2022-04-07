struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let n = s.len();
        let mut dp = vec![vec![0; n + 1]; n + 1];
        let mut longest_len = 0;
        let mut longest_end = 0;

        for i in 1..n + 1 {
            for j in i..n + 1 {
                if s.as_bytes()[i - 1] == s.as_bytes()[n - j] {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if i + j == n + dp[i][j]{
                        if dp[i][j] > longest_len {
                            longest_len = dp[i][j];
                            longest_end = i;
                        }
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        println!("{:?}\n", dp);
        String::from_utf8(s.as_bytes()[longest_end - longest_len..longest_end].to_vec()).unwrap()
    }
}

fn main() {
    let s = String::from("babad");
    println!("{}\n", Solution::longest_palindrome(s));
}
