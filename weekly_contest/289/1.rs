struct Solution;

impl Solution {
    pub fn digit_sum(s: String, k: i32) -> String {
        let mut s = s;
        let k = k as usize;
        loop {
            if s.len() <= k {
                return s;
            }
            let mut tmp = String::new();
            let n = s.len();
            for i in 0..(n / k) + 1 {
                let mut sum = 0;
                for j in 0..k {
                    if i * k + j < n {
                        sum += s.as_bytes()[i * k + j] as u32 - 48;
                    } else {
                        break;
                    }
                }
                if i * k == n {
                    break;
                }
                tmp += &sum.to_string();
            }
            s = tmp;
        }
    }
}

fn main() {
    let s = String::from("1234");
    let k = 2;
    println!("{}", Solution::digit_sum(s, k));
}
