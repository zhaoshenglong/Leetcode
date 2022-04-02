struct Solution;

impl Solution {
    pub fn longest_increasing_path(matrix: Vec<Vec<i32>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut dp = vec![vec![0; n]; m];
        let mut res = 0;
        
        for i in 0..m {
            for j in 0..n {
                if dp[i][j] != 0 {
                    res = res.max(dp[i][j]);
                    continue;
                }
                Solution::recursive_compute(&matrix, &mut dp, i, j);
                res = res.max(dp[i][j]);
            }
        }

        res
    }

    fn recursive_compute(matrix: &Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>, i: usize, j: usize) -> () {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut neighbors = vec![];

        if i > 0 {
            neighbors.push((i - 1, j));
        }
        if i + 1 < m {
            neighbors.push((i + 1, j)); }
        if j > 0 {
            neighbors.push((i, j - 1));
        }
        if j + 1 < n {
            neighbors.push((i, j + 1));
        }
        dp[i][j] = 1;
        for &(x, y) in &neighbors {
            let x :usize = x;
            let y :usize = y;
            if matrix[x][y] < matrix[i][j] {
                if dp[x][y] == 0 {
                    Solution::recursive_compute(matrix, dp, x, y);
                }
                dp[i][j] = (dp[x][y] + 1).max(dp[i][j]);
            }
        }
    }
}

fn main() {
    let matrix = vec![ vec![3,4,5], vec![3,2,6], vec![2,2,1] ];
    println!("{}", Solution::longest_increasing_path(matrix));
}
