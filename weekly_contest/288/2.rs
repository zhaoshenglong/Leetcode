struct Solution;

impl Solution {
    pub fn minimize_result(expression: String) -> String {
        let n = expression.len();
        let mut plus_i = 0;
        
        for &b in expression.as_bytes() {
            if b == '+' as u8 {
                break;
            }
            plus_i += 1;
        }

        println!("{}", &expression[..plus_i]);
        let mut min_exp = (&expression[..plus_i]).parse::<i32>().unwrap()
                        + &expression[plus_i + 1..].parse::<i32>().unwrap();
        let mut min_i = 0;
        let mut min_j = n - 1;

        for i in 0..plus_i {
            let mut left = 1; 
            if i > 0 {
                left = *&expression[..i].parse::<i32>().unwrap();
            }
            for j in plus_i + 1..n {
                let mut right = 1;
                if j < n - 1 {
                    right = *&expression[j + 1..].parse::<i32>().unwrap();
                }
                let mid_left = &expression[i..plus_i].parse::<i32>().unwrap();
                let mid_right = &expression[plus_i + 1.. j + 1].parse::<i32>().unwrap();
                if left * (mid_left + mid_right) * right < min_exp {
                    min_exp = left * (mid_left + mid_right) * right;
                    min_i = i;
                    min_j = j;
                }
            }
        }

        String::from(&expression[..min_i])
            + "(" + &expression[min_i..min_j + 1] + ")"
            + &expression[min_j + 1..]
    }
}

fn main() {
    let exp = String::from("5+22");
    println!("{}", Solution::minimize_result(exp));
}
