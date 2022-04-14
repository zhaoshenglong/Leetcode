struct Solution;

impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut wealthiest = 0;

        for wealthy in accounts.iter() {
            wealthiest = wealthiest.max(wealthy.iter().sum());
        }

        wealthiest
    }
}
