struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 2 {
            return n;
        }

        let (mut prev, mut cur) = (1, 2);
        for _ in 3..n + 1 {
            let tmp = cur + prev;
            prev = cur;
            cur = tmp;
        }
        cur
    }
}
