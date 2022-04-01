use std::collections::BTreeMap;

struct Solution;

impl Solution {
    pub fn can_reorder_doubled(arr: Vec<i32>) -> bool {
        let mut num_cnt: BTreeMap<i32, (i32, i32)> = BTreeMap::new();
        let mut grp = 0;
        
        for num in arr.iter() {
            if num < &0 {
                let ref mut cnt = num_cnt.entry(-num).or_insert((0, 0)).1;
                *cnt += 1;
            } else if num == &0 {
                grp += 1;
            } else {
                let ref mut cnt = num_cnt.entry(*num).or_insert((0, 0)).0;
                *cnt += 1;
            }
        }

        match grp & 1 {
            1 => { return false; }
            0 => { grp >>= 1; }
            _ => ()
        }

        let nums: Vec<i32> = num_cnt.keys().cloned().collect();
        for num in nums {
            let (pos, neg) = num_cnt.get(&num).unwrap().clone();
            if pos == 0 && neg == 0 {
                continue;
            }
            if let Some(dn) = num_cnt.get_mut(&(num << 1)) {
                dn.0 -= pos;
                dn.1 -= neg;
                if dn.0 < 0 || dn.1 < 0 {
                    return false;
                }
                grp += pos + neg;
                if grp == (arr.len() >> 1) as i32 {
                    return true;
                }
            }
        }
        
        return true;
    }
}

fn main() {
    println!("{}", Solution::can_reorder_doubled(vec![-4, 2, 4, -2]));
}
