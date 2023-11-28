#![allow(unused_must_use)]

use std::cmp;
use std::io::{self, prelude::*};
use std::str;

fn can_copy(n: i64, x: i64, y: i64, t: i64) -> bool {
    t / x + t / y >= n
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    let (n, x, y): (i64, i64, i64) = (sc.tok(), sc.tok(), sc.tok());

    let (mut l, mut r) = (0, cmp::max(x, y) * n);
    while l < r {
        let time = l + (r - l) / 2;
        if can_copy(n - 1, x, y, time) {
            r = time;
        } else {
            l = time + 1;
        }
    }
    writeln!(wr, "{}", l + cmp::min(x, y));
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
