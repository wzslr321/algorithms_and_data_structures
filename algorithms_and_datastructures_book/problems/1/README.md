### Problem 1-1

For each function f(n) and time t in the following table, determine the largest size n of a problem that can be solved
in time t, assuming that the algorithm to solve the problem takes f(n) microseconds.

Because creating a table in Readme is too problematic, I paste a URL to online solution and explain where particular
numbers come from.

https://ita.skanev.com/01/problems/01.html

<img width="962" alt="solution table" src="https://user-images.githubusercontent.com/59893892/128398392-bcd813d9-1de0-47d0-8c07-42fa51fd0275.png">

```
1 sec = 1 000 000ms
1 min = 1 000 000ms * 60
1 hour = 1 000 000ms * 60 * 60 
1 day = 1 000 000ms * 60 * 60 * 24 
1 month = 1 000 000ms * 60 * 60 * 24 * 30 (We assume that every month has 30 days)
1 year = 1 000 000ms * 60 * 60 * 24 * 30 * 365 
1 century = 1 000 000ms * 60 * 60 * 24 * 30 * 365 * 100
```

Exponential notation visible mostly in the first row of a table simplifies record of very large numbers.

* lg n

In IT logarithm without a base is usually a binary logarithm, so it's default base is equal to 2.

lg ₂ 2 = 1

Since we know that binary logarithm of 2 is equal to 1, we only have to calculate how many ms is equal to the particular
number. I wrote it under the solutions table.

1 sec = 1 000 000 ms - we can see 6 0's - so 6 is the number used in this exponential notation.

1 minute in ms is 60 times bigger than 1 sec in ms, what can be seen divided into two parts in the table -> * 6 | * 10

Respectfully with the rest of columns.

* √n

I think that square doesn't require deeper explanation.

We can see a simple dependency:

<img width="92" src="https://user-images.githubusercontent.com/59893892/128408766-1f1ec796-f248-44e6-94cf-5d53b01b717f.png">

6 seen in log n row and 36 seen in √n row. Number in row lg n, in place of 6 is a square of number that we need in the
same column, in √n row.

* n

This one definitely doesn't require explanation.

* n lg n

We still operate on binary logarithms, so the default base is equal to 2.

We need to find a number that multiplied by its logarithm is equal to particular time in ms.

I can't find or figure out any formula that would help to calculate it for specified values, 
so I assume that it needs to be calculated by *trial and error method.*

* n², n^3, 2^n

I believe it doesn't require any explanation.

* n!

It is a <b> <a href="https://en.wikipedia.org/wiki/Factorial"> Factorial </a> </b> 

<i> 
In mathematics, the factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less
than or equal to n:

n! = n ⋅ (n − 1) ⋅ (n − 2) ⋅ (n − 3) ⋅ ⋯ ⋅ 3 ⋅ 2 ⋅ 1 

For example, 5! = 5 ⋅ 4 ⋅ 3 ⋅ 2 ⋅ 1 = 120 . 

</i> 
  
Source: https://en.wikipedia.org/wiki/Factorial

So respectfully, we have to calculate factorial of particular time in ms. 

Verification (1st column - 9!):

<img width="204" src="https://user-images.githubusercontent.com/59893892/128413074-599643d6-f4c5-4acc-a273-d5c6235f4300.png">