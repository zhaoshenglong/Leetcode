struct Solution;

impl Solution {
    pub fn max_trailing_zeros(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut left_2 = vec![vec![0; n]; m];
        let mut left_5 = vec![vec![0; n]; m];
        let mut top_2 = vec![vec![0; n]; m];
        let mut top_5 = vec![vec![0; n]; m];

        for i in 0..m {
            for j in 0..n {
                if j == 0 {
                    left_2[i][0] = Solution::count2(grid[i][0]);
                    left_5[i][0] = Solution::count5(grid[i][0]);
                } else {
                    left_2[i][j] = left_2[i][j - 1] + Solution::count2(grid[i][j]);
                    left_5[i][j] = left_5[i][j - 1] + Solution::count5(grid[i][j]);
                }
                if i == 0 {
                    top_2[0][j] = Solution::count2(grid[0][j]);
                    top_5[0][j] = Solution::count5(grid[0][j]);
                } else {
                    top_2[i][j] = top_2[i - 1][j] + Solution::count2(grid[i][j]);
                    top_5[i][j] = top_5[i - 1][j] + Solution::count5(grid[i][j]);
                }
            }
        }

        let mut res = 0;
        for i in 0..m {
            for j in 0..n {
                let mut left_top_2 = 0;
                let mut left_top_5 = 0;
                let mut left_down_2 = 0; 
                let mut left_down_5 = 0; 
                let mut right_top_2 = 0;
                let mut right_top_5 = 0;
                let mut right_down_2 = 0;
                let mut right_down_5 = 0;

                if i >= 1 {
                    left_top_2 += top_2[i - 1][j];
                    left_top_5 += top_5[i - 1][j];
                    right_top_2 += top_2[i - 1][j];
                    right_top_5 += top_5[i - 1][j];
                }
                left_down_2 += top_2[m-1][j] - top_2[i][j];
                left_down_5 += top_5[m-1][j] - top_5[i][j];
                right_down_2 += top_2[m-1][j] - top_2[i][j];
                right_down_5 += top_5[m-1][j] - top_5[i][j];
                if j >= 1 {
                    left_top_2 += left_2[i][j-1];
                    left_top_5 += left_5[i][j-1];
                    left_down_2 += left_2[i][j-1];
                    left_down_5 += left_5[i][j-1];
                }
                right_top_2 += left_2[i][n-1] - left_2[i][j];
                right_top_5 += left_5[i][n-1] - left_5[i][j];
                right_down_2 += left_2[i][n-1] - left_2[i][j];
                right_down_5 += left_5[i][n-1] - left_5[i][j];
                let c2 = Solution::count2(grid[i][j]);
                let c5 = Solution::count5(grid[i][j]);
                left_top_2 += c2;
                left_top_5 += c5;
                left_down_2 += c2; 
                left_down_5 += c5; 
                right_top_2 += c2;
                right_top_5 += c5;
                right_down_2 += c2;
                right_down_5 += c5;

                res = res.max(left_top_2.min(left_top_5));
                res = res.max(left_down_2.min(left_down_5));
                res = res.max(right_top_2.min(right_top_5));
                res = res.max(right_down_2.min(right_down_5));
            }
        }
        res
    }

    fn count2(num: i32) -> i32 {
        let mut res = 0;
        let mut num = num;
        loop {
            if num % 2 == 0 {
                num /= 2;
                res += 1;
                continue;
            }
            break;
        }
        res
    }

    fn count5(num: i32) -> i32 {
        let mut res = 0;
        let mut num = num;
        loop {
            if num % 5 == 0 {
                num /= 5;
                res += 1;
                continue;
            }
            break;
        }
        res
    }
}

fn main() {
    let grid = vec![vec![23,17,15,3,20], vec![8,1,20,27,11], vec![9,4,6,2,21], vec![40,9,1,10,6],vec![22,7,4,5,3]];
    println!("{}", Solution::max_trailing_zeros(grid));
}

