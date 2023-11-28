#![allow(unused_must_use)]

use std::io::{self, prelude::*};
use std::str;

fn can_build(corals: &Vec<i32>, water_limit: i32, height: i64) -> bool {
    let water_sum: i64 = corals
        .iter()
        .map(|&coral_height| (height - coral_height as i64).max(0))
        .sum();

    water_sum <= water_limit as i64
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    let test_cases: i32 = sc.tok();
    for _ in 0..test_cases {
        let (corals_amount, water_limit): (i32, i32) = (sc.tok(), sc.tok());
        let corals = (0..corals_amount).map(|_| sc.tok()).collect();
        let (mut lower_bound, mut upper_bound) = (0, 1e9 as i64 + water_limit as i64);
        while upper_bound > lower_bound + 1 {
            let mid = (lower_bound + upper_bound) / 2;
            if can_build(&corals, water_limit, mid) {
                lower_bound = mid;
            } else {
                upper_bound = mid;
            }
        }
        let max_height = if can_build(&corals, water_limit, upper_bound) {
            upper_bound
        } else {
            lower_bound
        };

        writeln!(wr, "{}", max_height);
    }
}

// template

struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitWhitespace<'static>,
}
impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: vec![],
            buf_iter: "".split_whitespace(),
        }
    }
    fn tok<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_whitespace())
            }
        }
    }
}
fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());
    solve(&mut scan, &mut out);
}

