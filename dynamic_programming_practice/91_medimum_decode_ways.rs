struct Solution;

impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        let n = s.len();
        let mut prev = 0;
        let mut cur = 0; 
        let bytes = &s.as_bytes();
        
        if bytes[0] == '0' as u8 {
            return 0;
        } else {
            prev = 1;
            cur = 1;
        }

        for i in 1..n {
            let mut tmp = 0;
            if bytes[i] != '0' as u8 {
                tmp += cur;
            }

            let code = &s[i - 1..i + 1]
                        .parse::<i32>()
                        .unwrap();
            if *code <= 26 && *code >= 1 && bytes[i - 1] != '0' as u8 {
                tmp += prev;
            } else {
                if bytes[i] == '0' as u8 {
                    return 0;
                }
            }
            prev = cur;
            cur = tmp;
        }

        cur
    }
}


fn main() {}
