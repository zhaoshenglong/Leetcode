struct NumArray {
    nums: Vec<i32>,
    prefix_sum: Vec<i32>
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {

    fn new(nums: Vec<i32>) -> Self {
        let mut ps = 0;

        let mut arr = NumArray {
            nums: nums.clone(),
            prefix_sum: vec![],
        };
        for &n in &nums {
            ps += n;
            arr.prefix_sum.push(ps);
        }
        arr
    }

    fn update(&mut self, index: i32, val: i32) {
        for i in index as usize.. self.prefix_sum.len() {
            self.prefix_sum[i] += val - self.nums[index as usize];
        }
        self.nums[index as usize] = val;
    }

    fn sum_range(&self, left: i32, right: i32) -> i32 {
        let left = left as usize;
        let right= right as usize;
        if left == 0 {
            self.prefix_sum[right]
        } else {
            self.prefix_sum[right] - self.prefix_sum[left - 1]
        }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray::new(nums);
 * obj.update(index, val);
 * let ret_2: i32 = obj.sum_range(left, right);
 */

fn main() {
    let nums = vec![1,3,5];
    let mut arr = NumArray::new(nums);
    println!("{}\n", arr.sum_range(0, 2));

    arr.update(1, 2);
    println!("{}\n", arr.sum_range(0, 2));
}
