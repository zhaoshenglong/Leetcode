impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut cost = cost;

        for i in 2..cost.len() {
            cost[i] = cost[i - 1].min(cost[i - 2]) + cost[i];
        }

        cost[cost.len() - 1].min(cost[cost.len() - 2])
    }
}
