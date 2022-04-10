struct Solution;

impl Solution {
    pub fn largest_integer(num: i32) -> i32 {
        let mut nums = Vec::new();
        let mut num = num;

        loop {
            nums.push(num % 10);
            num /= 10;
            if num == 0 {
                break;
            }
        }
        let mut odd = Vec::new();
        let mut even = Vec::new();
        let mut odd_index = Vec::new();
        let mut even_index = Vec::new();

        let mut i = 0;
        for &n in nums.iter().rev() {
            if n & 1 == 0 {
                even.push(n);
                even_index.push(i);
            } else {
                odd.push(n);
                odd_index.push(i);
            }
            i += 1;
        }

        odd.sort();
        odd.reverse();
        even.sort();
        even.reverse();
        println!("{:?}", odd);
        println!("{:?}", even);
        println!("{:?}", even_index);
        println!("{:?}", odd_index);

        let mut i = 0;
        let mut j = 0;
        let mut res = 0;
        loop {
            if i >= odd_index.len() || j >= even_index.len() {
                break;
            }
            res *= 10;
            if odd_index[i] < even_index[j] {
                res += odd[i];
                i += 1;
            } else {
                res += even[j];
                j += 1;
            }
        }
        println!("i: {}, j: {}", i, j);
        loop {
            if i < odd_index.len() {
                res *= 10;
                res += odd[i];
                i += 1;
                continue;
            }
            if j < even_index.len() {
                res *= 10;
                res += even[j];
                j += 1;
                continue;
            }
            break;
        }
        res
    }
}

fn main() {
    println!("{}\n", Solution::largest_integer(1234));
}
