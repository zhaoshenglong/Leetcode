struct Solution;

impl Solution {
    pub fn is_one_bit_character(bits: Vec<i32>) -> bool {
        let size = bits.len();
        let mut i = 0;
        
        loop {
            match bits[i] {
                0 => {
                    i += 1;
                }
                _ => {
                    i += 2;
                }
            }
            if i == size - 1 {
                return true;
            }
            if i > size - 1 {
                return false;
            }
        }
    }
}
