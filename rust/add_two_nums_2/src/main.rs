use std::boxed::Box;
use std::fmt;
use std::vec::Vec;

struct Solution;

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

impl fmt::Display for ListNode {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        let mut p = self.clone();
        loop {
            write!(f, "{} ", p.val)?;
            if p.next.is_none() {
                break;
            }
            p = *(p.next.unwrap());
        }
        Ok(())
    }
}

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let v1 = Solution::list_to_vec(l1);
        let v2 = Solution::list_to_vec(l2);
        let vec = Solution::add_two_numbers_vec(&v1, &v2);
        return Solution::vec_to_list(&vec);
    }

    pub fn list_to_vec(list: Option<Box<ListNode>>) -> Vec<i32> {
        let mut vec = Vec::new();

        if list.is_some() {
            let mut node = list.unwrap();
            loop {
                vec.push(node.val);
                if node.next.is_some() {
                    node = node.next.unwrap();
                } else {
                    return vec;
                }
            }
        }
        return vec![];
    }

    pub fn add_two_numbers_vec(v1: &Vec<i32>, v2: &Vec<i32>) -> Vec<i32> {
        let mut it1 = v1.iter();
        let mut it2 = v2.iter();
        let mut carry = 0;
        let mut vec = Vec::new();

        let mut v1 = it1.next();
        let mut v2 = it2.next();
        loop {
            if v1.is_some() && v2.is_some() {
                let mut val = v1.unwrap() + v2.unwrap() + carry;
                if val >= 10 {
                    carry = 1;
                    val -= 10;
                } else {
                    carry = 0;
                }
                vec.push(val);
                v1 = it1.next();
                v2 = it2.next();
            } else {
                if v1.is_some() {
                    v2 = Some(&0); 
                } else if v2.is_some() {
                    v1 = Some(&0);
                } else {
                    if carry > 0 {
                        vec.push(1);
                    }
                    return vec;
                }
            }
        }
    }

    pub fn vec_to_list(v: &Vec<i32>) -> Option<Box<ListNode>> {
        let mut head = Box::new(ListNode::new(0));
        
        for i in v.iter().rev() {
            let mut p = Box::new(ListNode::new(*i));
            p.next = head.next;
            head.next = Some(p);
        }
        head.next
    }
}

fn main() {
    let l1 = Solution::vec_to_list(&vec![9,9,9,9,9,9,9]);
    println!("l1: {}", &*((l1.as_ref()).unwrap()));
    let l2 = Solution::vec_to_list(&vec![9,9,9,9]);
    println!("l2: {}", &*((l2.as_ref()).unwrap()));
    println!("l1 + l2: {}", &*(Solution::add_two_numbers(l1, l2).unwrap()));

}
