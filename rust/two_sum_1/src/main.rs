use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        let mut i = 0;

        for n in nums.iter() {
            match map.get(&(target - n)) {
                Some(v) => return vec![*v, i],
                None => map.insert(n, i)
            }; 
            i += 1
        }
        return vec![]
    }
}

fn main() {
    println!("{:?}", Solution::two_sum(vec![3, 2, 4], 6));
}
