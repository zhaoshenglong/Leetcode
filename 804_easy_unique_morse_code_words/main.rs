use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        let morse_table = vec![".-","-...","-.-.","-..",".",
                               "..-.","--.","....","..",".---",
                               "-.-",".-..","--","-.","---",
                               ".--.","--.-",".-.","...","-",
                               "..-","...-",".--","-..-","-.--",
                               "--.."];
        let mut morse_set: HashSet<String> = HashSet::new();
        
        for word in &words {
            let mut morse_str = String::from("");
            for &c in word.as_bytes() {
                morse_str += morse_table[c as usize - 'a' as usize];
            }
            morse_set.insert(String::from(morse_str));
        }

        morse_set.len() as i32
    }
}

fn main() {
    let words = vec!["gin","zen","gig","msg"]
                    .into_iter().map(|s| String::from(s)).collect();
    println!("{}\n", Solution::unique_morse_representations(words));
}
