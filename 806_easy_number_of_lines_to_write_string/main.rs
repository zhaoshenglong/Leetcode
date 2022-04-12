struct Solution;

impl Solution {
    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let mut line_fill = 0;
        let mut line_cnt = 1;

        for c in s.chars() {
            line_fill += widths[(c as u32 - 'a' as u32) as usize];
            if line_fill > 100 {
                line_fill = widths[(c as u32 - 'a' as u32) as usize];
                line_cnt += 1;
            }
        }

        vec![line_cnt, line_fill]
    }
}

fn main() {
    let widths = vec![4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10];
    let s = String::from("bbbcccdddaaa");
    println!("{:?}", Solution::number_of_lines(widths, s));
}
