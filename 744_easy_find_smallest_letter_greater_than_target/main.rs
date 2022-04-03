struct Solution;

impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        let mut res = char::MAX;
        let mut min_ch = char::MAX;

        for &c in &letters {
            if c > target && c < res {
                res = c;
                if res == (target as u8 + 1) as char {
                    return res;
                }
            }
            min_ch = min_ch.min(c);
        }
        if res == char::MAX {
            min_ch
        } else {
            res 
        }
    }
}

fn main() {
    let letters = vec!['c', 'f', 'j'];
    let target = 'k';
    println!("{}\n", Solution::next_greatest_letter(letters, target));
}
