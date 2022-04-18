struct Solution;

impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        let mut lexical_nums = vec![0; n as usize];

        for i in 1..10.min(n + 1) {
            Solution::dfs(&mut lexical_nums, &mut 0, i, n);
        }

        lexical_nums
    }

    fn dfs(nums: &mut Vec<i32>, s: &mut usize, n: i32, bound: i32) {
        nums[*s] = n;
        *s += 1;

        let n = 10 * n;
        for i in 0..10 {
            if n + i <= bound {
                Solution::dfs(nums, s, n + i, bound);
            }
        }
    }
}

fn main() {}
