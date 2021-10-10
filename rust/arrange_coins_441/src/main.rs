struct Solution;

impl Solution {
    pub fn arrange_coins(n: i32) -> i32 {
        let n = (n as i64) << 1;
        let r = (n as f64).sqrt() as i32;
        if r * (r + 1) > (n as i32) {
            r - 1
        } else {
            r
        }
    }
}

fn main() {
    println!("{}", Solution::arrange_coins(5));
}
