use std::collections::HashSet;
struct Solution;

impl Solution {
    pub fn to_goat_latin(sentence: String) -> String {
        let vowels: HashSet<char> = vec!['a', 'e', 'i', 'o', 'u',
                                     'A', 'E', 'I', 'O', 'U']
                                    .into_iter().collect();
        let goat_speak = "ma";
        let mut suffix = String::from("a");
        let mut goat_latin = String::from("");

        for word in sentence.split(" ") {
            match word.chars().next() {
                Some(c) => {
                    if vowels.contains(&c) {
                        goat_latin += word;
                    } else {
                        goat_latin += &word[1..];
                        goat_latin += &word[0..1];
                    }
                    goat_latin += goat_speak;
                    goat_latin += &suffix;
                    goat_latin += " ";
                    suffix += "a";
                },
                _ => {}
            }
        }

        String::from(&goat_latin[..(goat_latin.len() - 1)])
    }
}

fn main() {
    let sentence = String::from("I speak Goat Latin");
    let goat_latin = Solution::to_goat_latin(sentence);
    println!("{}", goat_latin);
}
