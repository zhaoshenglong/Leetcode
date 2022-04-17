struct Solution;

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut max_index = 0;

        for i in 0..n {
            if i as i32 > max_index {
                return false;
            }
            max_index = max_index.max(i as i32 + nums[i]);
            if max_index >= (n - 1) as i32 {
                return true;
            }
        }
        return max_index >= (n - 1) as i32; 
    }
}

fn main() {}
