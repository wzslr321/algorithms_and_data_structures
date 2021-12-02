use std::io;

fn main() -> io::Result<()> {
    let mut x = 0;
    let mut y = 0;
    loop {
        let mut data = String::new();
        match io::stdin().read_line(&mut data) {
            Ok(_) => {
                let mut words = &data.split_whitespace();
                match words.next() {
                    Some("forward") => x = x + words.next(),
                    Some("up") => y = y + words.next(),
                    Some("down") => y += words.next(),
                    _ => (),
                }
            },
            Err(_) => break,
        }
    }

    Ok(())
}
