/*   
Here I did some basic yet complex question on finding Time complexiety , if you are not good at math first learn about AP,GP and logarithms
and further I think its easy once you grasp the key concept that
For nested loops :- WE need to find total number of iteration(Their SUM!)
as for single loop :- Find last iteration of 'i' for finding Time complexity.
 Its easy and don't worry if you don't get things in once or twice , Time Complexity will come in approx. all DSA questions so just keep
 learning and slowly but surely you will improve in it!
 Bye and Have a good Day!!

-Problem on time complexity 

int value=0;
for(int i=0 ; i<=n ; i*=2){
    value++;
}
//So, this code will add 1 to value each time it iterates through loop
-Make this code more optimal

We can use the method that for every one iteration the value of i increases exponentially one less than the interation value
so, we can write that loop should run till (2^i<=n) => i<= log2(n);

Explanation :-

Let's analyze the time complexity of the given code snippet:

```cpp
int value = 0;
for (int i = 1; i <= n; i *= 2) {
    value++;
}
```

**Explanation:**
In this code, we have a loop that starts with `i = 1` and continues as long as `i` is less than or equal to `n`. In each iteration
 of the loop, `i` is multiplied by 2, and we increment the `value` variable by 1.

**Time Complexity:**
Let's see how the value of `i` changes with each iteration of the loop:
1. `i = 1` (initial value)
2. `i = 1 * 2 = 2` (first iteration)
3. `i = 2 * 2 = 4` (second iteration)
4. `i = 4 * 2 = 8` (third iteration)

The value of `i` increases exponentially in each iteration of the loop, doubling its value with every step. The loop will continue 
until `i` becomes greater than `n`. So, the number of iterations required to exit the loop can be represented as `log2(n)`.

Mathematically, `log2(n)` represents the number of times we can double 1 until we reach `n`. Hence, the time complexity of this code
 is logarithmic, denoted as O(log n).

**Explanation of Time Complexity:**
The loop iterates fewer times as `n` grows larger because it is doubling `i` in each step. As a result, the execution time increases 
slowly compared to the size of `n`.

Logarithmic time complexity is considered very efficient and desirable. It means that the algorithm performs well even for significantly 
larger input sizes, making it suitable for handling large datasets or more complex problems efficiently.

-Problem on time complexity 
int val=0;
for(int i=1;i<=n;i+=i){
    val++;
}
-Make this code more efficient
int val=0;
for(int i=1; i<=log(n)/log(2) ; i+=i){
    val++;
}
Therefore time complexity is : O(log2(n))

-Problem on time complexity
int val=0;
for(int i=1;i<=n;i*=2){
    for(int j=1; j<=i ; j++){
        val++;
    }
}
Here find how many times val++  hoga i.e. ye statement kitni bar run ho raha he
Explanation:-


```cpp
int val = 0;
for (int i = 1; i <= n; i *= 2) {
    for (int j = 1; j <= i; j++) {
        val++;
    }
}
```

**Explanation:**
In this code, we have two nested loops. The outer loop runs from `i = 1` to `i` being doubled in each iteration as long as `i` is 
less than or equal to `n`. The inner loop runs from `j = 1` to `j = i` in each iteration of the outer loop. In each iteration of the 
inner loop, we increment the `val` variable by 1.

**Time Complexity:**
Let's see how the loops progress:

- For the outer loop:
  1. `i = 1` (initial value)
  2. `i = 1 * 2 = 2` (first iteration)
  3. `i = 2 * 2 = 4` (second iteration)
  4. `i = 4 * 2 = 8` (third iteration)

- For the inner loop:
  - For `i = 1`, the inner loop runs once (`j = 1`).
  - For `i = 2`, the inner loop runs twice (`j = 1`, `j = 2`).
  - For `i = 4`, the inner loop runs four times (`j = 1`, `j = 2`, `j = 3`, `j = 4`).
  - For `i = 8`, the inner loop runs eight times (`j = 1`, `j = 2`, ..., `j = 8`).

Notice that the number of iterations for the inner loop increases with each iteration of the outer loop. For `i = 1`, it runs once; 
for `i = 2`, it runs twice; for `i = 4`, it runs four times, and so on. The pattern is that the inner loop runs exactly `i` times in 
each iteration of the outer loop.

So, the total number of times the inner loop runs can be represented as follows:

```
1 + 2 + 4 + 8 + ... + n
```

This is a geometric series with a common ratio of 2. The sum of this geometric series is `2*n - 1`. Therefore, the total number of times
 the inner loop runs is approximately `2*n`.

Since the `val` variable is incremented once in each iteration of the inner loop, the total number of increments is approximately `2*n`.

Hence, the time complexity of this code is linear, denoted as O(n).

**Explanation of Time Complexity:**
The time complexity of this code is linear because the number of operations performed increases linearly with the input size `n`. 
For every doubling of `i`, the number of iterations for the inner loop doubles, resulting in a linear relationship between the input 
size and the total number of operations.

In simpler terms, as `n` gets bigger, the time taken by the code to execute also increases proportionally. This is a good sign, as 
linear time complexity means the code is reasonably efficient and can handle larger inputs without significant performance issues.

-Problem on time complexity
int val=0;
for (int i = 1; i <= n; i*=2)
{
    for(int j=n ; j>i ; j--){
        val++;
    }
}
Explanation:-


```cpp
int val = 0;
for (int i = 1; i <= n; i *= 2) {
    for (int j = n; j > i; j--) {
        val++;
    }
}
```

**Explanation:**
In this code, we have two nested loops. The outer loop runs from `i = 1` and keeps doubling `i` as long as it is less than or equal to 
`n`. The inner loop runs from `j = n` down to `i + 1` (exclusive). In each iteration of the inner loop, we increment the `val` variable 
by 1.

**Time Complexity:**
Let's see how the loops progress:

- For the outer loop:
  1. `i = 1` (initial value)
  2. `i = 1 * 2 = 2` (first iteration)
  3. `i = 2 * 2 = 4` (second iteration)
  4. `i = 4 * 2 = 8` (third iteration)

- For the inner loop:
  - For `i = 1`, the inner loop runs `n - 1` times (`j = n, j = n-1, ..., j = 2`).
  - For `i = 2`, the inner loop runs `n - 2` times (`j = n, j = n-1, ..., j = 3`).
  - For `i = 4`, the inner loop runs `n - 4` times (`j = n, j = n-1, ..., j = 5`).
  - For `i = 8`, the inner loop runs `n - 8` times (`j = n, j = n-1, ..., j = 9`).

**Total Number of Operations:**
The number of operations for each iteration of the inner loop is decreasing with each iteration of the outer loop. The total number 
of operations can be calculated as follows:

```
(n - 1) + (n - 2) + (n - 4) + (n - 8) + ... + 1
```

This is a geometric series with a common ratio of 1/2. The sum of this geometric series is `n - 1 + n/2 + n/4 + ... + 1`, which is 
approximately `2 * n`.

Since the `val` variable is incremented once in each iteration of the inner loop, the total number of increments is also proportional 
to `n`.

Hence, the time complexity of this code is O(n * log n), where `n` is the input size.

**Explanation of Time Complexity:**
The time complexity of this code is O(n * log n) because the number of operations performed increases with `n` and also depends on the 
logarithm of `n` due to the geometric series. As `n` gets larger, the time taken by the code to execute increases in a somewhat 
logarithmic manner, making it efficient for handling larger inputs compared to pure linear time complexity (O(n)).

-find time complexity
int val=0;
for(int i=n ; i>0; i/=2){
    for(int j=0; j<i ; j++){
        val++;
    }
}

Explanation :-

Let's analyze the time complexity of the given code snippet:

```cpp
int val = 0;
for (int i = n; i > 0; i /= 2) {
    for (int j = 0; j < i; j++) {
        val++;
    }
}
```

**Explanation:**
In this code, we have two nested loops. The outer loop starts with `i = n` and divides `i` by 2 in each iteration until `i` becomes 0. 
The inner loop runs from `j = 0` to `j = i` (exclusive). In each iteration of the inner loop, we increment the `val` variable by 1.

**Time Complexity:**
Let's see how the loops progress:

- For the outer loop:
  1. `i = n` (initial value)
  2. `i = n / 2` (first iteration)
  3. `i = (n / 2) / 2 = n / 4` (second iteration)
  4. `i = (n / 4) / 2 = n / 8` (third iteration)

- For the inner loop:
  - For `i = n`, the inner loop runs `n` times (`j = 0, j = 1, ..., j = n - 1`).
  - For `i = n / 2`, the inner loop runs `n / 2` times (`j = 0, j = 1, ..., j = n / 2 - 1`).
  - For `i = n / 4`, the inner loop runs `n / 4` times (`j = 0, j = 1, ..., j = n / 4 - 1`).
  - For `i = n / 8`, the inner loop runs `n / 8` times (`j = 0, j = 1, ..., j = n / 8 - 1`).

**Total Number of Operations:**
The number of operations for each iteration of the inner loop decreases with each iteration of the outer loop. The total number of 
operations can be calculated as follows:

```
n + n/2 + n/4 + n/8 + ... + 1
```

This is a geometric series with a common ratio of 1/2. The sum of this geometric series is approximately `2 * n`.

Since the `val` variable is incremented once in each iteration of the inner loop, the total number of increments is also proportional 
to `n`.

Hence, the time complexity of this code is O(n), where `n` is the input size.

**Explanation of Time Complexity:**
The time complexity of this code is linear, denoted as O(n). It means that the number of operations performed by the code increases 
linearly with the input size `n`. As `n` gets larger, the time taken by the code to execute increases proportionally, making it 
efficient for handling larger inputs.

-Problem on Time Complexity
int val=0;
for(int i=2; i<=n ; i*=i){
    val++;
}

Explanation:-

Time Complexity
To analyze the time complexity of the code, we need to consider the number of iterations the loop will execute. In each iteration, 
the value of i is multiplied by itself. Let's denote the number of iterations as k.

In the first iteration, i is initialized to 2. In the second iteration, i becomes 2 * 2 = 4. In the third iteration, i 
becomes 4 * 4 = 16. In general, in the kth iteration, i becomes 2^(2^k).

We need to find the value of k for which 2^(2^k) exceeds or equals n. Taking the logarithm base 2 on both sides, we get:

2^k >= log2(log2(n))

Simplifying further, we get:

k >= log2(log2(n))

Therefore, the number of iterations k is logarithmic in the logarithm of n. Hence, the time complexity of the code is O(log(log(n))).*/






