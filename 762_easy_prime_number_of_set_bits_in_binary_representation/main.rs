struct Solution;

impl Solution {
    pub fn count_prime_set_bits(left: i32, right: i32) -> i32 {
        let prime = vec![2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31];
        let mut res = 0;

        for num in left..right + 1 {
            let bits = Solution::count_bits(num);
            println!("bits of {}: {}\n", num, &bits);
            match prime.binary_search(&bits) {
                Ok(_) => res += 1,
                Err(e) => println!("{:?}\n", e)
            }
        }

        res
    }

    fn count_bits(num: i32) -> usize {
        let num = num as usize; 
        let mask = 0x55555555;
        let mut res = (num & mask) + ((num >> 1) & mask);

        let mask = 0x33333333;
        res = (res & mask) + ((res >> 2) & mask);
        
        let mask = 0x0f0f0f0f;
        res = (res & mask) + ((res >> 4) & mask);

        let mask = 0xff;
        (res & mask) + ((res >> 8) & mask) + ((res >> 16) & mask) + ((res >> 24 & mask))
         
    }
}

fn main() {
    println!("{}\n", Solution::count_prime_set_bits(6, 10));
}
