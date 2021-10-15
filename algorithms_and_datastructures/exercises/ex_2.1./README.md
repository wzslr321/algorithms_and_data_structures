
<h3> 2.1-1 </h3>

<p>
  Using Figure 2.2 as a model, illustrate the operation of INSERTION-SORT
  on the array A = [32,41,59,26,41,58]
</p>

<b> My Answer: </b>

```
31 | 41 | 59 | 26 | 41 | 58
---------------------------
31 | 41 | 59 | 26 | 41 | 58
---------------------------
31 | 41 | 59 | 26 | 41 | 58
---------------------------
26 | 31 | 41 | 59 | 41 | 58
---------------------------
26 | 31 | 41 | 41 | 59 | 58
---------------------------
26 | 31 | 41 | 41 | 58 | 59
```

<h3> 2.1-2 </h3>

<p>
  Rewrite the INSERTION-SORT procedure to sort into non-increasing instead
  of non-decreasing order.
</p>

<b> My Answer: </b>

At first, I copy pseudo-code example for non-decreasing order.

```
for j = 2 to A.length
    key = A[j]
    i = j - 1
    while i > 0 and A[i] > key
      A[i+1] = A[i]
      i = i - 1
    A[i+1] = key
```

pseudo code non-increasing order:
```
for j = 2 to A.length
  key = A[j]
  i  = j - 1
  while i > 0 and A[i] < key
    A[i+1] = A[i]
    i = i - 1
  A[i+1] = key 
```

Only a little difference can be seen - in 4th line of pseudocode, 
replacing 2nd `>` with `<` does all the work. I believe it's quite logic - perform same change, but in opposite scenario. 


<h3> 2.1-3 </h3>

<p>

  Consider the searching problem:

  Input: A sequence of n numbers A = [a1, a2,...,an] and a value v

  Output: An index i such that v = A[i] or the special value NIL if v
  does not appear in A.

  Write pseudocode for linear search, which scans through the sequence, 
  looking for v. Using a loop invariant, prove that your algorithm is 
  correct. Make sure that your loop invariant fulfills the three 
  necessary properties.

</p>

<b> My Answer: </b>

```
function search(A []int) // 
  v = int 

  for i = 0 to A.length // Assume that first index of array is equal to 0.
    if A[i] == v
      return i 

  return nil 
```

<h3> 2.1-4 </h3>

<p>
  Consider the problem of adding two n-bit binary integers,
  stored in two n-element arrays A and B. The sum of the two
  integers should be stored in binary form in an (n+1)-element
  array C. State the problem formally and write pseudocode for
  adding the two integers. 
</p>

<b> My Answer: </b>

