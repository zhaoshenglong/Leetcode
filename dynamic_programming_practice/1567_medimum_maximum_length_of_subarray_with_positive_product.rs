struct Solution;

impl Solution {
    pub fn get_max_len(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.push(0);
        let n = nums.len();
        let mut sign = 1;
        let mut first_neg_pos = 0;
        let mut start = 0;
        let mut max_len = 0;

        for i in 0..n {
            if nums[i] == 0 {
                if sign < 0 {
                    max_len = max_len.max(i - first_neg_pos - 1);
                }
                sign = 1;
                first_neg_pos = i + 1;
                start = i + 1;
                continue;
            }

            if nums[i] < 0 {
                sign = -sign;
                if nums[first_neg_pos] > 0 {
                    first_neg_pos = i;
                }
            }
            if sign > 0 {
                max_len = max_len.max(i - start + 1);
            }
        }

        max_len as i32
    }
}
fn main() {}
