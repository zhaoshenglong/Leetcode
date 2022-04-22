use std::collections::BinaryHeap;
use std::collections::HashSet;
struct Solution;

impl Solution {
    pub fn nth_ugly_number(n: i32) -> i32 {
        let n = n as usize;
        let mut nums = BinaryHeap::with_capacity(n);
        let mut exclude = HashSet::new();
        nums.push(-1);
        exclude.insert(-1);
        
        for _ in 1..n {
            let num = nums.pop().unwrap();
            if !exclude.contains(&(num * 2)) && -num <= i32::MAX / 2 {
                nums.push(num * 2);
                exclude.insert(num * 2);
            }
            if !exclude.contains(&(num * 3)) && -num <= i32::MAX / 3 {
                nums.push(num * 3);
                exclude.insert(num * 3);
            }
            if !exclude.contains(&(num * 5)) && -num <= i32::MAX / 5 {
                nums.push(num * 5);
                exclude.insert(num * 5);
            }
        }

        -nums.peek().unwrap()
    }
}

fn main() {
    println!("{}", Solution::nth_ugly_number(1690));
}
