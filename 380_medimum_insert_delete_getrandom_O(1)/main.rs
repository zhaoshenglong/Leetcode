use std::collections::HashMap;
use rand::Rng;

struct RandomizedSet {
    pos: HashMap<i32, usize>,
    arr: Vec<i32>,
    size: usize
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {

    fn new() -> Self {
        RandomizedSet {
            pos: HashMap::new(),
            arr: Vec::new(),
            size: 0
        }
    }
    
    fn insert(&mut self, val: i32) -> bool {
        if self.pos.get(&val) == None {
            if self.arr.len() > self.size {
                self.arr[self.size] = val;
            } else {
                self.arr.push(val);
            }
            self.pos.insert(val, self.size);
            self.size += 1;
            true
        } else {
            false
        }
    }
    
    fn remove(&mut self, val: i32) -> bool {
        if self.pos.get(&val) != None {
            let pos = self.pos.remove(&val).unwrap();
            self.size -= 1;
            if pos < self.size {
                self.arr[pos] = self.arr[self.size];
                self.pos.insert(self.arr[pos], pos);
            }
            true
        } else {
            false
        }
    }
    
    fn get_random(&self) -> i32 {
        // println!("{:?}, {:?}, {}", self.arr, self.pos, self.size);
        let pos = rand::thread_rng().gen_range(0, self.size);
        self.arr[pos]
    }
}

fn main() {
    let obj = RandomizedSet::new();
    let ret_1: bool = obj.insert(1);
    let ret_2: bool = obj.insert(2);
    let ret_3: bool = obj.insert(2);
    let ret_4: i32 = obj.get_random();
    println!("ret_1: {}, ret_2: {}, ret_3: {}, ret_4: {}", ret_1, ret_2, ret_3, ret_4);
}
