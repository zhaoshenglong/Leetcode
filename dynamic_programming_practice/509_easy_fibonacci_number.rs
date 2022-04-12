struct Solution;

impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n <= 1 {
            return n; 
        }
        let mut prev = 1;
        let mut pprev = 0;
        let mut cur = 0;

        for i in 2..n + 1 {
            cur = prev + pprev;
            pprev = prev;
            prev = cur;
        }
        cur
    }
}

fn main() {
    prinln!("{}", Solution::fib(20));
}
