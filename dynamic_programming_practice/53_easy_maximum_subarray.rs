struct Solution;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut max_sum = nums[0];
        let mut prev_sum = nums[0];

        for i in 1..n {
            prev_sum = nums[i].max(prev_sum + nums[i]);
            max_sum = max_sum.max(prev_sum);
        }
        max_sum
    }
}

fn main() {}
