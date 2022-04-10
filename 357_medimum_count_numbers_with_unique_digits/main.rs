struct Solution;

impl Solution {
    pub fn count_numbers_with_unique_digits(n: i32) -> i32 {
        if n <= 1 {
            return 10_i32.pow(n as u32);
        }

        let mut res = 10;
        for i in 2..n + 1 {
            let mut count = 9;
            let mut k = 9;
            for _ in 0..i - 1 {
                count *= k; 
                k -= 1;
            }
            res += count;
        }
        res
    }
}

fn main() {
    println!("{}", Solution::count_numbers_with_unique_digits(4));
}
