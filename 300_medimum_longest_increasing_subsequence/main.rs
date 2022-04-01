
struct Solution;

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![0; n];
        let mut res = 0;

        dp[0] = 1;
        res = 1;
        for i in 1..n {
            dp[i] = 1;
            for j in 0..i {
                if nums[i] > nums[j] && dp[j] + 1 > dp[i] {
                    dp[i] = dp[j] + 1;
                }
            }
            if dp[i] > res {
                res = dp[i];
            }
        }

        res
    }
}

fn main() {
    println!("{}\n", Solution::length_of_lis(vec![10,9,2,5,3,7,101,18]));
}
