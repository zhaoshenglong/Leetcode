use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let mut num_cnt = HashMap::new();
        for &num in &nums {
            *num_cnt.entry(num).or_insert(0) += 1;
        }

        let mut uni_nums = Vec::new();
        for &k in num_cnt.keys() {
            uni_nums.push(k);
        }
        uni_nums.sort();
        let n = uni_nums.len();
        let mut dp = vec![0, uni_nums[0] * num_cnt.get(&uni_nums[0]).unwrap()];

        for i in 1..n {
            let mut tmp = dp[1];
            let cnt = num_cnt.get(&uni_nums[i]).unwrap();
            if uni_nums[i] > uni_nums[i - 1] + 1 {
                tmp += uni_nums[i] * cnt;
            } else {
                tmp = tmp.max(dp[0] + uni_nums[i] * cnt);
            }
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        dp[1]
    }
}

fn main() {
    let nums = vec![2,2,3,3,3,4];
    println!("{}", Solution::delete_and_earn(nums));
}
