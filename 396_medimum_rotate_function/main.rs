struct Solution;

impl Solution {
    pub fn max_rotate_function(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut prefix = vec![0; n];
        let mut rotate = 0;

        prefix[0] = nums[0];
        for i in 1..n {
            prefix[i] = prefix[i - 1] + nums[i];
            rotate += nums[i] * i as i32;
        }

        let rotate = rotate;
        let mut max_rotate = rotate;
        for i in 1..n {
            let mut tmp = rotate
                        + prefix[n - i - 1] * i as i32
                        - (prefix[n - 1] - prefix[n - i - 1]) * (n - i) as i32;
            max_rotate = max_rotate.max(tmp);
        }

        max_rotate
    }
}

fn main() {}
