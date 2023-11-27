#![allow(unused_must_use)]

use std::io::{self, prelude::*};
use std::str;

fn can_cut(v: &Vec<f64>, k: i32, l: f64) -> bool {
    let mut sum = 0;
    v.iter().for_each(|&x| sum += (x / l) as i32);
    sum >= k
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    let (n, k): (usize, i32) = (sc.tok(), sc.tok());
    let mut nums = vec![0.0; n];
    for i in 0..n {
        nums[i as usize] = sc.tok();
    }
    let (mut l, mut r): (f64, f64) = (0.0, nums.clone().into_iter().reduce(f64::max).unwrap());
    for _ in 0..100 {
        let mid = (l + r) / 2.0;
        if can_cut(&nums, k, mid)  {
            l = mid;
        } else {
            r = mid;
        }
    }
    writeln!(wr, "{}",l);
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
