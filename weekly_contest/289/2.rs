use std::collections::HashMap;
struct Solution;

impl Solution {
    pub fn minimum_rounds(tasks: Vec<i32>) -> i32 {
        let mut task_cnt = HashMap::new();

        for &task in &tasks {
            *task_cnt.entry(task).or_insert(0) += 1;
        }

        let mut round = 0;
        for (&_, &cnt) in &task_cnt {
            match cnt % 3 {
                0 => {
                    round += cnt / 3;
                },
                1 => {
                    if cnt == 1 {
                        return -1;
                    }
                    round += cnt / 3 + 1;
                },
                _ => {
                    round += cnt / 3 + 1;
                }
            }
        }
        round
    }
}

fn main() {
    let tasks = vec![2,2,3,3,2,4,4,4,4,4];
    println!("{}", Solution::minimum_rounds(tasks));
}

