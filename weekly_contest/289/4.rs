struct Solution;

impl Solution {
    pub fn longest_path(parent: Vec<i32>, s: String) -> i32 {
         
    }
}

fn main() {
    let parent = vec![-1,0,0,1,1,2];
    let s = String::from("abacbe");
    println!("{}", Solution::longest_path(parent, s));
}
