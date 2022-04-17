use std::collections::HashMap;
use std::collections::HashSet;
struct Solution;

impl Solution {
    pub fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        let mut paragraph: String = paragraph;
        let symbols = "!?',;.";
        let banned: HashSet<String> = banned.into_iter().collect();
        let mut word_cnt: HashMap<String, i32> = HashMap::new();

        let mut encode = [0; 1];
        for c in symbols.chars() {
            let s: &str = c.encode_utf8(&mut encode);
            paragraph = paragraph.replace(&s, " ");
        }

        let mut max_cnt = 0;
        let mut res = String::from("");
        for word in paragraph.split(" ") {
            if word == "" {
                continue;
            }
            let lower_word = word.to_lowercase();
            if banned.contains(&lower_word) {
                continue;
            }
            *word_cnt.entry(lower_word.clone()).or_insert(0) += 1;
            if word_cnt.get(&lower_word).unwrap() > &max_cnt {
                max_cnt = *word_cnt.get(&lower_word).unwrap();
                res = lower_word;
            }
        }
        
        res
    }
}

fn main() {
    let p = "Bob hit a ball, the hit BALL flew far after it was hit.";
    let banned = vec![];
    println!("{}", Solution::most_common_word(String::from(p), banned));
}
