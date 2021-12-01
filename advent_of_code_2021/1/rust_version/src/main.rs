use std::cmp::Ordering;
use std::io;

fn main() -> io::Result<()> {
    let mut answer = 0;
    let mut previous = std::i32::MAX;
    loop {
        let mut number = String::new();
        io::stdin().read_line(&mut number)?;

        match number.trim().parse::<i32>() {
            Ok(num) => {
                match num.cmp(&previous) {
                    Ordering::Greater => answer += 1,
                    _ => (),
                };
                previous = num;
            }
            Err(_) => break,
        }
    }
    println!("Answer: {}", answer);
    Ok(())
}
