
/* 

**Time Complexity:**
Imagine you have to complete a task, like counting the number of items in a shopping list. Time complexity is like asking, 
"How long will it take me to finish this task as the shopping list gets longer?"

For example, if you have 5 items on the list, it might take you 5 seconds to count them. If there are 10 items, it might take 
you 10 seconds, and so on. The time complexity tells you how the time to complete the task increases as the list gets longer.

In computer science, we use time complexity to understand how fast an algorithm (a set of instructions) works as the input it 
handles becomes bigger. We use "big O notation" to describe this growth rate.

**Space Complexity:**
Now, think about how much space you need to do the task. For counting the items, you might not need any extra space; you can
 just use your memory to keep track. But, what if the list is very long, like 1000 items or more? Then, you might need a pen and paper 
 to help you remember the count.

Space complexity is like asking, "How much extra stuff do I need as the task becomes more complex?"

In computer science, space complexity helps us understand how much memory an algorithm requires to work as the input size increases. 
It's essential when dealing with big amounts of data or when trying to make our programs efficient.

So, time complexity is about how long an algorithm takes to run as the problem becomes bigger, and space complexity is about how much 
extra memory it needs to solve the problem as it becomes more complex. Both concepts are essential to make sure our programs work well 
with different sizes of data.



'x' and 'y' find sum from x to y where 1<x<10^5 and x<y<10^8

x=2 and y=6 then range = {2,3,4,5,6}
Here rather than just brute forcing things using loops , use concept of A.P.
that S = (n/2)(2a+(n-1)d)  here a=x , d=1 , and n = y-x+1 using a(nth)= a+(n-1)d;
therefore , a=2 , d=1 , n = 6-2+1 = 5;
then S = (5/2)(2*2+(5-1)*1) = (5/2)(8) = 20 = {2+3+4+5+6}
Here we have advantage that value of x and y can be as large as you want and still be efficient as it is not running loop everytime;

This type of code is ex. of experimental analysis as it takes different time everytime we run it 
#include<iostream>
using namespace std;
int suminrange(int a, int b){
    int sum=0;
    for (int i = a; i <= b; i++)
    {
        sum+= i;
    }
    return sum;
    //Total number of instruction = 3n+3 = 3*(10^8)+3 ~~ 3*(10^8)
}
Here for large input it will take big time to sole it which makes this code ineffective!

So , as experimental analysis is too random and processinf power dependent we will intead use Asympotic analysis to solve it!
-So, now we will judge => "code on basis of number of operations w.r.t change in input"
Pharak padta he when input size is large as computer can execute 10^8 instruction in 1 sec

int effectiveCode(int a, int b){
    int n=b-a+1;
    int d=1;
    int ans= (n/2)*(2*a+(n-1)d);
    return ans;
} 
Here roughly 10 instructions are excuted regardless of how big the input is! , which make this code very relaible
This is what Asympotic analysis is!
-We care about big input value as well as number of operation/instruction which are gettin executed
-We are gonna look for growth -> number of instruction / input size 
-Slower the growth better the code!
-Look for Worst case Time Complexity

Types of complexity :-
1. Worst case - Big O - O => O(n)
2. Best case - Big Omega - Ω => Ω(1)
3. Avercaage se - Big Theta - θ => θ(n)

Time complexity is not the only criteria to determine the efficiency of code

Space Complexity(SC - self made abreviation):- it is the extra space requirement of an algorithm , using asympotic analysis
-We don't include input and output in SC
-Extra space means , input ke change hone pe ye  change hogi!
 Like here's an example involving T&S Complexity

Write a code to give 'n'th fibonacci number (pseudo code)
// we neglect constant and small values
arr[0]=0;
arr[1]=1
for(int i=2; i<= n ; i++){
    arr[i] = arr[i-1]+arr[i-2];
}
return arr[n];

-Here -> Space Complexity is - O(n);
and Time Complexity is :- O(n);

Now we are gonna optimise the code -  How about instead of making the whole array just make the last two elements
int n=8;
if(n==0 || n==1) return n;
int a=0;
int b=1;
int c=1;
for(int i=2; i<=n ; i++){
    c=a+b;
    a=b;
    b=c;
}
return c;

//Here these variable (a,b,c) are independent of value of n and hence;
Space C - O(1);
Time C - O(n); 
*/









