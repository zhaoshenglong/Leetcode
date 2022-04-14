struct Solution;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let n = nums.len();
        if n == 1 {
            return nums[0];
        }
        nums[1] = nums[1].max(nums[0]);
        for i in 2..n {
            nums[i] = nums[i - 1].max(nums[i - 2] + nums[i]);
        }
        nums[n - 1]
    }
}

