<h3> 1.2-1 </h3> 

<p>
  Give an example of an application that requires algorithmic content at the application level,
  and discuss the function of the algorithms involved. 
</p>

<b> My answer: </b> 

   An application that allows to send emojis based on our current facial expressions. 
   It would have to involve an algorithm that compares neutral state of our face 
   with a current one by analyzing possibly millions of points and restructure them
   in a way that all of them would be related to avoid a deconstruction of emoji. 

---

<h3> 1.2-2 </h3> 

<p>
  Suppose we are comparing implementations of insertion sort and merge sort on the same machine.
  For inputs of size n, insertion sort runs in 8n^2 steps, while merge sort runs in 64n lg n steps.
  For which values of n does insertion sort beat merge sort?
</p>

<b> My answer: </b>

  lg n here is a binary logarithm, because the default base of logarithms in computer science
  and information theory is equal to 2. With this knowledge, we can perform simple checks. 

  <i> Insertion Sort </i>

    formula =  8n^2 

    n = 10 --> 8 * 10 ^ 2 = 800

    n = 25 --> 8 * 25 ^ 2 = 5000

    n = 50 --> 8 * 50 ^ 2 = 20 000

    n = 42 --> 8 * 42 ^ 2 = 14 112 

    n = 43 --> 8 * 43 ^ 2 = 14 792 

    n = 44 --> 8 * 44 ^ 2 = 15 488

    n = 45 --> 8 * 45 ^ 2 = 16 200

  <i> Merge Sort </i> 

    formula = 64n lg n 

    n = 10 --> 64 * 10 * ~3,32 = ~2125

    n = 25 --> 64 * 25 * ~4,64 = ~ 7424 

    n = 50 --> 64 * 50 * ~5,64 = 18 048 

    n = 42 --> 64 * 42 * ~5,39 = ~ 14 448

    n = 43 --> 64 * 43 * ~5,426 = ~ 14 932

    n = 44 --> 64 * 44 * ~5,4594 = 15 373

    n = 45 --> 64 * 45 * ~5.4919 = 15 816

Basing on calculations above, we can assume that insertion sort 
beats merge sort for n values <b> approximately equal or smaller than 43. </b> 

---

<h3> 1.2-3 </h3>

<p>
  What is the smallest value of n such that algorithm whose running time is 100n^2
  runs faster than an algorithm whose running time is 2^n on the same machine?
</p>

<b> My answer: </b>

<i> First Formula ( 100n ^ 2 ) </i>

    n = 10 --> 100 * 10 ^ 2 = 10 000
    
    n = 15 --> 100 * 15 ^ 2 = 22 500

    n = 14 --> 100 * 14 ^ 2 = 19 600

<i> Second Formula ( 2 ^ n ) </i>
    
    n = 10 --> 2 ^ 10 = 1024 

    n = 15 --> 2 ^ 15 = 32 768 

    n = 14 --> 2 ^ 14 = 16 384
---

Basing on calculations above we can say that smallest value of n, which makes that 
algorithm whose running time is 100n ^ 2 runs faster than an algorithm 
whose running time is 2 ^ n on the same machine, is approximately equal to 15.  