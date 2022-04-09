struct Solution;

impl Solution {
    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let mut adjlist: Vec<Vec<i32>> = vec![Vec::new(); n];
        let mut succ: Vec<i32> = vec![0; n];

        if n == 1 {
            return vec![0];
        }
        if n == 2 {
            return vec![0, 1];
        }
        // construct the adjacent list
        for edge in &edges {
            let u = edge[0];
            let v = edge[1];
            adjlist[u as usize].push(v);
            adjlist[v as usize].push(u);
        }

        println!("{:?}", adjlist);
        Solution::balance_branch(&adjlist, 0, &mut succ)
    }

    fn compute_height(adjlist: &Vec<Vec<i32>>, s: i32, p: i32, succ: &mut Vec<i32>) -> i32 {
        let mut height = 0;

        for &child in &adjlist[s as usize] {
            if child != p {
                let h = Solution::compute_height(adjlist, child, s, succ);
                if h + 1 > height {
                    height = h + 1;
                    succ[s as usize] = child;
                }
            }
        }

        height
    }

    fn balance_branch(adjlist: &Vec<Vec<i32>>, s: i32, succ: &mut Vec<i32>) -> Vec<i32> {
        let mut highest = 0;
        let mut higher = 0;
        let mut highest_cnt = 0;
        let mut highest_node = s;

        if adjlist[s as usize].len() == 1 {
            return Solution::balance_branch(adjlist, adjlist[s as usize][0], succ);
        }
        for &child in &adjlist[s as usize] {
            let h = Solution::compute_height(adjlist, child, s, succ);
            if h > highest {
                higher = highest;
                highest = h;
                highest_cnt = 1;
                highest_node = child;
                continue;
            }
            if h == highest {
                highest_cnt += 1; 
                continue;
            }
            if h > higher {
                higher = h;
            }
        }
        if highest_cnt > 1 {
            return vec![s];
        }
        if highest == higher + 1 {
            return vec![s, highest_node];
        }

        succ[s as usize] = highest_node;
        println!("{:?}", succ);
        println!("s: {}, highest_node, {}, highest: {}", s, highest_node, highest);
        let dist = (highest - higher) >> 1;
        let new_s = Solution::seek_node(succ, s, dist);
        return Solution::balance_branch(adjlist, new_s, succ);
    }

    fn seek_node(succ: &Vec<i32>, s: i32, dist: i32) -> i32 {
        let mut new_s = s;
        for _ in 0..dist {
            new_s = succ[new_s as usize];
        }
        new_s
    }
}

fn main() {
    let edges = vec![vec![1, 0], vec![1, 2], vec![1, 3]];
    println!("{:?}", Solution::find_min_height_trees(4, edges));
}
