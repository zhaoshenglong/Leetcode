struct Solution;

impl Solution {
    pub fn max_score_sightseeing_pair(values: Vec<i32>) -> i32 {
        let n = values.len();
        let mut dp = vec![0; n];
        let mut max_score = 0;

        dp[1] = values[0] + values[1] - 1;
        max_score = max_score.max(dp[1]);
        for i in 2..n {
            let mut s = 0;
            if (values[i] as usize) < i {
                s = i - values[i] as usize;
            }
            for j in s..i {
                dp[i] = dp[i].max(values[i] + values[j] + j as i32 - i as i32);
            }

            max_score = max_score.max(dp[i]);
        }

        max_score
    }
}

fn main() {}
