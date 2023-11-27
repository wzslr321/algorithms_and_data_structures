#![allow(unused_must_use)]

use std::io::{self, prelude::*};
use std::str;

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    let test_cases: i32 = sc.tok();
    for _ in 0..test_cases {
        let (_n, k, s) : (i32, i32, String) = (sc.tok(), sc.tok(), sc.tok());

        let alphabet_size = 26;
        let mut vec = vec![0; alphabet_size];
        for letter in s.chars() {
            let index:usize = (letter as usize) - ('a' as usize);
            vec[index] += 1;
        }
        let odd_count: i32 = vec.iter().filter(|&&x| x & 1 == 1).count().try_into().unwrap();
        let allowed_odd:i32 = ((s.len() - (k as usize)) & 1).try_into().unwrap();

        if odd_count - k> allowed_odd {
            writeln!(wr, "NO");
        } else {
            writeln!(wr, "YES");
        }
    }
}

struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitWhitespace<'static>,
}
impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self { reader, buf_str: vec![], buf_iter: "".split_whitespace() }
    }
    fn tok<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader.read_until(b'\n', &mut self.buf_str).expect("Failed read");
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
    solve(&mut  scan, &mut out);
}
