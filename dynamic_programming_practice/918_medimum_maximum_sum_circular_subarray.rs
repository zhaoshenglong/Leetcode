struct Solution;

impl Solution {
    pub fn max_subarray_sum_circular(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut max_prefix = vec![0; n];
        
        let mut sum = nums[n - 1];
        max_prefix[n - 1] = nums[n - 1];
        for i in (n - 2..0).rev() {
            sum += nums[i];
            max_prefix[i] = max_prefix[i + 1].max(sum);
        }

        let mut prev_sum = 0;
        let mut max_sum = 0;
        let mut prefix_sum = 0;
        for i in 0..n - 1 {
            prev_sum = nums[i].max(prev_sum + nums[i]);
            max_sum = max_sum.max(prev_sum);
            max_sum = max_sum.max(prefix_sum + max_prefix[i + 1] + nums[i]);
            prefix_sum += nums[i];
        }
        
        max_sum = max_sum.max(nums[n - 1].max(prev_sum + nums[n - 1]));
        max_sum
    }
}

fn main() {}

