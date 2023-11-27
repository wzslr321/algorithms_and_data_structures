#![allow(unused_must_use)]

use std::io::{self, prelude::*};
use std::str;

fn is_valid(x: i64, a: i64, b: i64, n: i64) -> bool {
    ((x / b) * (x / a)) >= n
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    let (w, h, n): (i64, i64, i64) = (sc.tok(), sc.tok(), sc.tok());
    let (mut l, mut r) = (std::cmp::max(w,h), 0);
    let mut p = 0;
    while p < 64 {
        r = 1 << p;
        let _mid = l + (r - l) / 2;
        if is_valid(_mid, w, h, n)  {
           break; 
        }
        p += 1;
    }
    while l < r {
        let mid = l + (r - l) / 2;
        if is_valid(mid, w, h, n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    writeln!(wr, "{}", l);
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
