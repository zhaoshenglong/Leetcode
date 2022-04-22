struct Solution;

impl Solution {
    pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut res = 0;
        
        if n < 3 {
            return 0;
        }
        res = if nums[0] - nums[1] == nums[1] - nums[2] {
            1
        } else {
            0
        }
        for i in 2..n {
            let diff = nums[i] - nums[i - 1];
            let mut inc = 0;
            let mut j = i - 2;
            loop {
                if j >= 0 && nums[j + 1] - nums[j] == diff {
                    inc += 1;
                    continue;
                }
                break;
            }
            res += inc;
        }

        res
    }
}

fn main() {}
