
struct Solution;

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut graph = vec![vec![];n];
        let mut dp = vec![0; n];
        let mut res;

        // construct the graph
        // graph[i] stores the predecessor j of i if 
        // j < i and nums[j] < nums[i]
        for i in 0..n {
            for j in i + 1..n {
                if nums[i] < nums[j] {
                    graph[j].push(i);
                }
            }
        }

        for i in 0..n {
            dp[i] = 1;
            for &j in &graph[i] {
                if dp[j] + 1 > dp[i] {
                    dp[i] = dp[j] + 1;
                }
            }
            res = dp[i].max(res);
        }

        res
    }
}

fn main() {
    println!("{}\n", Solution::length_of_lis(vec![10,9,2,5,3,7,101,18]));
}
