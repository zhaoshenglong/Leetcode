use std::collections::binary_heap::BinaryHeap;

struct Solution;

impl Solution {
    pub fn maximum_product(nums: Vec<i32>, k: i32) -> i32 {
        let modulo = 1000000007;
        let mut num_queue: BinaryHeap<i32> = BinaryHeap::new();

        for &n in &nums {
            num_queue.push(-n);
        }

        for _ in 0..k {
            let num = *num_queue.peek().unwrap();
            num_queue.pop();
            num_queue.push(num - 1);
        }
        
        println!("{:?}", num_queue);
        let mut res: u64 = 1;
        for n in &num_queue {
            res *= (-n) as u64;
            if res > modulo {
                res %= modulo;
            }
        }
        res as i32
    }
}

fn main() {
    let nums = vec![24,5,64,53,26,38];
    let k = 54;
    println!("{}", Solution::maximum_product(nums, k));
}
