struct Solution;

impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut mxpdt = i32::MIN;
        let mut prefix = 1;
        let mut first_neg = 0;
        let mut first_neg_pos = 0;

        for i in 0..n {
            if nums[i] == 0 {
                if first_neg != 0 && prefix < 0 && i - 1 != first_neg_pos {
                    mxpdt = mxpdt.max(prefix / first_neg);
                }
                mxpdt = mxpdt.max(0);
                prefix = 1;
                first_neg = 0;
                continue;
            }

            prefix *= nums[i];
            mxpdt = mxpdt.max(prefix);
            if nums[i] < 0 && first_neg == 0 {
                first_neg = prefix;
                first_neg_pos = i;
            }
        }

        if nums[n - 1] != 0 {
            if first_neg != 0 && prefix < 0 && n - 1 != first_neg_pos {
                mxpdt = mxpdt.max(prefix / first_neg);
            }
        }
        mxpdt
    }
}

fn main() {}
