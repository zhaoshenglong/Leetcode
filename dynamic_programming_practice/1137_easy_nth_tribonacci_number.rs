struct Solution;

impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        if n < 3 {
            return if n == 2 {
                1
            } else {
                n
            }
        }
        
        let (mut pprev, mut prev, mut cur) = (0, 1, 1);
        for _ in 3.. n + 1 {
            let tmp = pprev + prev + cur;
            pprev = prev;
            prev = cur;
            cur = tmp;
        }
        cur
    }
}
