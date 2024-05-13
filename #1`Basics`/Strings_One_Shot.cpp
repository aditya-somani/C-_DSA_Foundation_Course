/*

-So , in this we completed whole strings in oneshot if you want you can directly jump to questions as
they will give you a much better understandings of its concept! Have a GOOD DAY AHEAD!!


#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "abc";
    cout<<str[1]<<" "<<int(str[1]); //b 98

}

String V/S Character array

| String                                                      | Character Array                                            |
|-------------------------------------------------------------|------------------------------------------------------------|
| `string` is a class in C++.                                 | Character arrays are of type `char`.                       |
| `string str_name;`                                          | `char array_name[size];`                                   |
| Dynamic memory allocation.                                  | Static memory allocation.                                  |
| No preallocated memory.                                     | Memory is preallocated based on size.                      |
| Have built-in functions for string manipulation.            | Need to use standard C library functions for manipulation. |
| Consumes memory dynamically, minimizing waste.              | Unused allocated memory may be wasted.                     |
| Slower due to dynamic memory management and function calls. | Faster due to static allocation.                           |

This table summarizes some of the key differences between strings and character arrays in C++. Strings provide more convenience 
with built-in functions and dynamic memory allocation but may have slightly slower performance, whereas character arrays offer 
faster performance due to static allocation but require manual memory management and library functions for manipulation. 
The choice between them depends on the specific needs of your program.

-Commonly used built in functions in a string:-

1. reverse() - to reverse the whole string frmm starting pointer to end pointer
    reverse(ptr1,ptr2)
    string str = "abcd";
    reverse(str.begin(),str.end());
    cout<<str;
-Time complexity - O(n)
-Example:-

#include<iostream>
#include<string>
#include<algorithm> //to use reverse you must first  include Algorithm header file
using namespace std;
int main(){
    string str = "abcd";
    reverse(str.begin(),str.end());
    cout<<str;   //dcba
    return 0;
}
-2. substr() - used to find subtring of a given string
    string_name.substr(position,length);

#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "abcd";
    cout<<str.substr(0,2)<<endl;  //ab
    cout<<str.substr(1,2)<<endl;  //bc
    cout<<str.substr(1)<<endl;  //bcd
    return 0;
}
-Time complexity -> O(n);

-3. '+' operator -> concatenate/append two strings 
    str = "ab";
    str1 = "cd";
    cout<<str+str1;

#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "ab";
    string str1 = "cd";
    //These two things are differenet :- 
    str += str1;   //str1 is getting appended after str -> extra space not used
    str = str + str1 // copy string is being created for str -> extra space used
    cout<<str+str1;   //abcd
    return 0;
}

-4. strcat() - concatenate char arrays
    char s1[20] = "ab";
    char s2[20] = "cd";
    strcat(s1,s1);

#include<iostream>
#include<string>
#include<cstring> //This header files must be included to use 'strcat'
using namespace std;
int main(){
    char s1[20] = "ab";
    char s2[20] = "cd";
    strcat(s1,s1);  //abab
    cout<<s1<<endl;  //ababcd
    strcat(s1,s2);
    cout<<s1;
    return 0;
}

-5. push_back() - insert char at the end of string
    string str = "abc";
    char ch = "e";
    str.push_back(ch);

#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "abc";
    char ch = 'd'; //single ko -> single inverted commas me hi use karte he
    str.push_back(ch);  //abcd
    cout<<str;
    return 0;
}

-6. size()/length()/strlen() - gives the size/length of string / size of charater array
    -They are faster than 'strlen()' functions which have O(n)
    strlen() gives length of character array

#include<iostream>
#include<string>
#include<cstring>  //Must be included for 'strlen()' to work
using namespace std;
int main(){
    string str = "abc";
    cout<<str.size()<<endl;  //3
    cout<<str.length()<<endl;  //3
    char ch[20] = "ab";
    cout<<strlen(ch)<<endl;  //2
    return 0;
}

-7. to_string -> to convert integers value to string
    int num = 4;
    to_string(num);

#include<iostream>
#include<string>
using namespace std;
int main(){
    int num1 = 4;
    string str1 = to_string(num1);
    int num2 = 132;
    string str2 = to_string(num2);
    cout<<num1+num2<<endl;  //136
    cout<<str1+str2;   //4132
    return 0;
}

-QUESTIONS!!

-1.Given a strings str, sort the given string.
Constraints: The string will contain only alphabetical characters from a-z.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to perform counting sort on a string
string countSort(string str) {
    // Create a frequency array for lowercase letters (26 letters)
    vector<int> freq(26, 0);

    // Count the frequency of each character in the input string
    for (int i = 0; i < str.size(); i++) {
        // Calculate the index of the character in the frequency array
        int index = str[i] - 'a';
        
        // Increment the count for that character
        freq[index]++;
    }

    int j = 0;

    // Reconstruct the sorted string using the frequency array
    for (int i = 0; i < freq.size(); i++) {
        while (freq[i]--) {
            // Append the character back into the string based on its frequency
            str[j++] = i + 'a';
        }
    }

    // Return the sorted string
    return str;
}

int main() {
    cout << "Enter the string: ";
    string str;
    
    // Input the string from the user
    cin >> str;

    // Perform counting sort on the input string
    cout << "Sorted string is: " << countSort(str);

    return 0;
}

Output:-
Enter the string : aditya
Sorted string is : aadity

**Explanation:**

- The `countSort` function:
  - Accepts a string `str` as its parameter, which is the input string to be sorted.
  - Initializes a vector `freq` of size 26, representing the frequency of lowercase letters ('a' to 'z').
  - Iterates through the characters of the input string.
  - For each character, it calculates its index in the `freq` vector by subtracting 'a'.
  - Increments the count in the `freq` vector for that character.
  - Constructs the sorted string by iterating through the `freq` vector and appending characters 
  based on their frequencies.
  - Returns the sorted string.

**Explanation for the `main` function:**

- In the `main` function:
  - It prompts the user to input a string.
  - Reads the input string from the user.
  - Calls the `countSort` function to sort the input string.
  - Displays the sorted string as the output.

This code performs counting sort on the input string, which is a sorting algorithm that counts the 
occurrences of each character and reconstructs the sorted string based on those counts. It provides a 
sorted version of the input string as the output.

-Time complexity -> O(length of string)
-Space Complexity -> O(26)

-2.Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Constraints : String s and t will only contain lowercase alphabetical characters.
Anagram -> rearranging letter of a word to get another meaningful word 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if two strings are anagrams
bool countSort(string &s, string &t) {
    // Check if the lengths of both strings are different, if so, they cannot be anagrams
    if (s.length() != t.length()) {
        return false;
    }
    
    // Create an array 'freq' to count the occurrences of each character (26 letters of the alphabet)
    vector<int> freq(26, 0);

    // Update the frequency array based on characters in both strings
    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;  // Increment for characters in the first string
        freq[t[i] - 'a']--;  // Decrement for characters in the second string
    }

    // Check if all character frequencies in 'freq' are zero, indicating an anagram
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return false; // If any frequency is not zero, they are not anagrams
        }
    }

    return true; // If all frequencies are zero, they are anagrams
}

int main() {
    string s, t;
    cout << "Enter first word: ";
    cin >> s;
    cout << "Enter second word: ";
    cin >> t;

    // Check if the input strings are anagrams and display the result
    if (countSort(s, t)) {
        cout << "Yes, " << s << " is an anagram of " << t;
    } else {
        cout << "No, " << s << " is not an anagram of " << t;
    }

    return 0;
}


Output:-
Enter first word : integral
Enter second word : traingle
Yes , integral is an anagram of traingle

**Explanation:**

- The `countSort` function:
  - Accepts two string references, `s` and `t`, as parameters to check if they are anagrams.
  - Initially checks if the lengths of both strings are different. If they are, it returns `false` as 
  they cannot be anagrams with different lengths.
  - Creates a vector `freq` of size 26 to represent the frequency of each lowercase letter of the alphabet.
  - Iterates through the characters of the input strings, incrementing the corresponding frequency 
  in the `freq` vector for characters in `s` and decrementing it for characters in `t`.
  - After processing both strings, it checks if all character frequencies in the `freq` vector are zero.
  - If all frequencies are zero, it returns `true`, indicating that the input strings are anagrams.
  - If any frequency is not zero, it returns `false`, indicating that the input strings are not anagrams.

- In the `main` function:
  - It takes user input for two strings, `s` and `t`, to be checked for anagram status.
  - Calls the `countSort` function to determine if `s` and `t` are anagrams.
  - Depending on the result, it displays a message indicating whether `s` is an anagram of `t` or not.

This code provides a clear and efficient way to check if two input strings are anagrams of each other, 
considering the character frequencies in both strings.

-Time complexity -> O(length of string)
-Space complexity -> O(26)

-Given two strings s and t , determine if they are isomorphic
    Isomorphic -> one to one mapping

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if two strings are isomorphic
bool isIsomorphic(string s1, string s2) {
    // Create two vectors 'v1' and 'v2' to store character mappings (initialized to -1)
    vector<int> v1(128, -1);
    vector<int> v2(128, -1);

    // Check if the sizes of 'v1' and 'v2' are equal (not necessary)
    if (v1.size() != v2.size()) {
        return false;
    }

    // Iterate through the characters of both input strings
    for (int i = 0; i < s1.size(); i++) {
        // Check if the character mapping in 'v1' and 'v2' is consistent
        if (v1[s1[i]] != v2[s2[i]]) {
            return false;
        }

        // Update the character mappings in 'v1' and 'v2'
        v1[s1[i]] = v2[s2[i]] = i;
    }

    // If all character mappings are consistent, the strings are isomorphic
    return true;
}

int main() {
    string s1, s2;
    cout << "Enter the first word: ";
    cin >> s1;
    cout << "Enter the second word: ";
    cin >> s2;

    // Check if the input words are isomorphic and display the result
    if (isIsomorphic(s1, s2)) {
        cout << "Yes, they are Isomorphic";
    } else {
        cout << "No, they are not Isomorphic";
    }

    return 0;
}

Output:-
Enter the first word : add
Enter the second number : egg
Yes , they are Isomorphic

**Explanation:**

- The `isIsomorphic` function:
  - Accepts two strings, `s1` and `s2`, as parameters to check if they are isomorphic.
  - Creates two vectors, `v1` and `v2`, each of size 128, initialized with -1. These vectors will be used 
  to store character mappings.
  - It checks if the sizes of `v1` and `v2` are equal (although this check is not necessary since they 
  are initialized with the same size).
  - Iterates through the characters of both input strings using a loop.
  - For each character, it checks if the character mapping in `v1` and `v2` is consistent. If they are 
  not equal, it returns `false`, indicating that the strings are not isomorphic.
  - If the character mappings are consistent, it updates the character mappings in `v1` and `v2` to 
  reflect the current character's position in the string.
  - After processing all characters in both strings, if all character mappings are consistent, it 
  returns `true`, indicating that the input strings are isomorphic. Otherwise, it returns `false`.

**`main` function:**

- In the `main` function:
  - It takes user input for two words, `s1` and `s2`, to be checked for isomorphism.
  - Calls the `isIsomorphic` function to determine if `s1` and `s2` are isomorphic.
  - Depending on the result, it displays a message indicating whether `s1` is an isomorph of `s2` or not.

This code provides a clear and efficient way to check if two input strings are isomorphic by comparing 
their character mappings.

- Given an array of strings, write a program to find the longest common prefix string amongst an array of string

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to find the longest common prefix among a vector of strings
string longestCommonPrefix(vector<string> v) {
    // Sort the vector of strings lexicographically
    sort(v.begin(), v.end());

    // Initialize variables to hold the first and last strings after sorting
    string s1 = v[0];
    string s2 = v[v.size() - 1];

    // Initialize variables for comparing characters
    int i = 0; // Index for s1
    int j = 0; // Index for s2

    // Initialize a string to store the longest common prefix
    string ans = "";

    // Iterate through both strings, comparing characters
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            ans += s1[i];
            i++;
            j++;
        } else {
            break; // If characters are different, exit the loop
        }
    }

    return ans; // Return the longest common prefix
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    vector<string> v(n);

    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Longest common prefix is: " << longestCommonPrefix(v);
    return 0;
}


Output:-
Enter the number of string : 3
Enter the strings : ant anti anthem
Longest common prefix is : ant

-Time complexity -> O(nlogn * m) + O(min(s[0].size(),s[n-1].size())) -> O(nlogn)
nlogn -> sorting , n-> no. of strings , m-> general length of strings , min(...) -> comparing first and last element
-Space complexity -> O(n) or constant

**Explanation:**

- The `longestCommonPrefix` function:
  - Accepts a vector of strings, `v`, as a parameter to find the longest common prefix among the strings.
  - First, it sorts the input vector of strings lexicographically using the `sort` function from the `<algorithm>` library.
  - Then, it initializes two strings, `s1` and `s2`, with the first and last strings from the sorted vector, respectively.
  - Two index variables, `i` and `j`, are used to compare characters between `s1` and `s2`.
  - It also initializes an empty string `ans` to store the longest common prefix.
  - The function iterates through `s1` and `s2`, comparing characters at the same positions.
  - If the characters are the same, it appends the character to the `ans` string and increments both `i` and `j`.
  - If the characters are different, it breaks out of the loop.
  - Finally, it returns the `ans` string, which represents the longest common prefix.


-`main` function:
  - It takes user input for the number of strings, `n`, and a vector of strings, `v`.
  - Calls the `longestCommonPrefix` function to find the longest common prefix among the strings in the vector.
  - Displays the result, which is the longest common prefix.

This code provides an efficient way to find the longest common prefix among a set of strings and uses 
sorting to simplify the comparison process.

-Now let's solve this question without sorting


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to find the longest common prefix among a vector of strings
string longestCommonPrefix(vector<string> v) {
    // Initialize the first string as the reference for comparison
    string s1 = v[0];
    int ans_length = s1.size(); // Initialize the answer length with the length of the first string
    
    // Iterate through the remaining strings in the vector
    for (int i = 1; i < v.size(); i++) {
        int j = 0;
        
        // Compare characters of the current string and the reference string
        while (j < s1.size() && j < v[i].size() && s1[j] == v[i][j]) {
            j++; // Increment the index as long as characters match
        }
        
        // Update the answer length with the minimum of the current index and the existing answer length
        ans_length = min(ans_length, j);
    }
    
    // Create a substring of the first string using the calculated answer length
    string ans = s1.substr(0, ans_length);
    return ans; // Return the longest common prefix
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    vector<string> v(n);

    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the function to find the longest common prefix and display the result
    cout << "Longest common prefix is: " << longestCommonPrefix(v);
    return 0;
}

Output:-
Enter the number of strings: 3
Enter the strings: add adam addu
Longest common prefix is: ad

-Time complexity -> O(n-1 * m) -> O(n*m)
n-> number of strings , m -> general length of strings

**Explanation:**

- The `longestCommonPrefix` function:
  - Accepts a vector of strings, `v`, as a parameter to find the longest common prefix among the strings.
  - Initializes the first string, `s1`, as the reference for comparison.
  - Initializes `ans_length` with the length of `s1`, as a starting point for the answer.
  - Iterates through the remaining strings in the vector using a `for` loop.
  - Inside the loop, it compares characters of the current string and the reference string (`s1`) using 
  a `while` loop.
  - It increments the index `j` as long as characters in both strings match.
  - Updates `ans_length` with the minimum of the current index `j` and the existing `ans_length`. 
  This ensures that it tracks the length of the longest common prefix.
  - After processing all strings, it creates a substring of the first string, `s1`, using the calculated 
  `ans_length` to obtain the longest common prefix.
  - Finally, it returns the `ans` string, which represents the longest common prefix.

-`main` function:**

- In the `main` function:
  - Takes user input for the number of strings, `n`, and a vector of strings, `v`.
  - Calls the `longestCommonPrefix` function to find the longest common prefix among the strings in 
  the vector.
  - Displays the result, which is the longest common prefix.

This code provides an efficient way to find the longest common prefix among a set of strings 
and uses dynamic tracking of the common prefix length.

-An encoded string (s) is given, and the task is to decode it. The encoding pattern is that
the occurrence of the string is given at the starting of the string and each string is
enclosed by square brackets.
Note: The occurrence Ot a single string is less than 1000.

#include<bits/stdc++.h>
using namespace std;

// Function to decode a coded string using a stack
string decoded(string s) {
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ']') {
            // If the current character is not ']', add it to the result
            result.push_back(s[i]);
        } else {
            // If the current character is ']', decode the substring inside the nearest '[' and ']'
            
            // Create an empty string 'str' to store the characters within the brackets
            string str = "";
            
            // While the result is not empty and the last character is not '[', pop characters from the result and reverse them to get the inner string
            while (!result.empty() && result.back() != '[') {
                str.push_back(result.back());
                result.pop_back();
            }
            reverse(str.begin(), str.end());
            
            // Remove the '[' from the result
            result.pop_back();
            
            // Create an empty string 'num' to collect numeric characters that represent the repetition count
            string num = "";
            
            // While the result is not empty, and 'i' is within bounds, and the last character is a numeric digit, collect these digits to form the repetition count
            while (!result.empty() && i < s.size() && (result.back() >= '0' && result.back() <= '9')) {
                num += result.back();
                result.pop_back();
            }
            reverse(num.begin(), num.end());
            
            // Convert the numeric string 'num' to an integer 'intnum'
            int intnum = stoi(num);
            
            // Repeat the inner string 'str' as per the repetition count 'intnum' and add it to the result
            while (intnum) {
                result += str;
                intnum--;
            }
        }
    }
    return result;
}

int main() {
    cout << "Enter the coded string : ";
    string s;
    
    // Read the input string from the user
    getline(cin, s);
    
    // Call the 'decoded' function to decode the input string
    string decodedStr = decoded(s);
    
    // Display the decoded string to the user
    cout << "The decoded string is : " << decodedStr;
    
    return 0;
}

Output:-
Enter the coded string : 3[a2[b3[c]]]
The decoded string is : abcccbcccabcccbcccabcccbccc

-Space complexity -> O(n) where 'n' is the length of decoded string
-Time complexity -> O(n)
1. It initializes an empty string `result` to store the decoded string.

2. It iterates through the input string `s` character by character.

3. If the current character is not ']', it appends it to the `result` string, effectively 
building the decoded string.

4. When it encounters a ']', it extracts the substring enclosed within the nearest '[' and ']' 
characters. It uses the `str` string to collect these characters by reversing the order.

5. It removes the '[' character from the `result` string as it has been processed.

6. It then collects numeric characters following the ']' character, which represent the repetition 
count for the enclosed substring. It stores these digits in the `num` string.

7. It converts the `num` string to an integer `intnum` using `stoi()`.

8. Finally, it repeats the inner string `str` as per the repetition count `intnum` and appends it to 
the `result` string.

The main function reads the input string, calls the `decoded` function to decode it, and then displays 
the decoded string to the user.

**Explanation:**

- The `decoded` function is designed to decode a coded string enclosed in square brackets. 
It follows a stack-like approach to process the input string character by character and reconstruct 
the decoded string.

  - It starts by initializing an empty string `result`, which will store the decoded string.

  - Then, it iterates through the input string `s` character by character.

  - If the current character is not ']', it appends it to the `result` string, effectively building 
  the decoded string.

  - When it encounters a ']', it extracts the substring enclosed within the nearest '[' and ']' characters. 
  It uses the `str` string to collect these characters by reversing the order. This inner string 
  represents the content to be repeated.

  - It removes the '[' character from the `result` string as it has been processed.

  - Next, it collects numeric characters following the ']' character, which represent the repetition 
  count for the enclosed substring. These digits are stored in the `num` string.

  - The `num` string is then converted to an integer `intnum` using the `stoi()` function.

  - Finally, it repeats the inner string `str` as per the repetition count `intnum` and appends it to 
  the `result` string.

  - The function continues this process until it has processed the entire input string, resulting in a 
  fully decoded string.

- In the `main` function:

  - It prompts the user to enter a coded string.

  - It reads the input string using `getline()` to handle spaces and special characters.

  - Then, it calls the `decoded` function to decode the input string.

  - Finally, it displays the decoded string to the user.

This code effectively decodes coded strings with nested brackets and repetition counts, 
producing the desired output.

- Given a binary string and an integer k, return the max number of consecutive 1s in the string 
if you can flip at most k 0's

-This technique is called "SLIDING WINDOW TECHNIQUE"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Function to find the length of the longest consecutive string of '1's
int longestConse(string s, int n) {
    int start = 0;          // Initialize the start index of the window
    int end = 0;            // Initialize the end index of the window
    int zerocount = 0;      // Count of '0's in the current window
    int maxlength = 0;      // Length of the longest consecutive '1's found

    // Loop through the binary string 's'
    for (; end < s.size(); end++) {
        if (s[end] == '0') {
            zerocount++;    // Increment the count of '0's in the window
        }

        // If the count of '0's exceeds 'n', adjust the window
        while (zerocount > n) {
            if (s[start] == '0') {
                zerocount--;    // Decrement the count as '0' is removed from the window
            }
            start++;            // Move the start of the window to the right
        }

        // Update the maximum length of consecutive '1's found in the window
        maxlength = max(maxlength, end - start + 1);
    }

    return maxlength;   // Return the length of the longest consecutive '1's
}

int main() {
    string s;
    cout << "Enter the Binary string : ";
    cin >> s;
    int n;
    cout << "Enter the number of times 0's can be flipped : ";
    cin >> n;
    cout << "Longest consecutive string of 1 is : " << longestConse(s, n);
    return 0;
}

Output:-
Enter the Binary string : 0001010111
Enter the number of time 0's can be flipped : 2
Longest consective string of 1 is : 7

-Time complexity -> O(n) where 'n' is the length of input string
-Space complexity -> O(1) that is constant space complexity

**Explanation:**

- The `longestConse` function:
  - Parameters:
    - `string s`: This parameter represents the input binary string.
    - `int n`: This parameter represents the number of times '0's can be flipped.
  - Variables:
    - `start`: This variable keeps track of the start index of the current window.
    - `end`: This variable keeps track of the end index of the current window.
    - `zerocount`: It stores the count of '0's in the current window.
    - `maxlength`: It keeps track of the maximum length of consecutive '1's found.
  - Explanation:
    - The function uses a sliding window approach to find the longest consecutive string of '1's with 
    the ability to flip '0's up to `n` times.
    - It iterates through the binary string `s` using the `end` index.
    - If the character at the `end` index is '0', it increments the `zerocount` to keep track of '0's 
    in the current window.
    - It then enters a while loop to adjust the window size by moving the `start` index to the right 
    if the `zerocount` exceeds `n`.
    - During this process, it calculates the length of the current consecutive '1's substring and 
    updates `maxlength` if a longer consecutive sequence is found.
    - The function returns the `maxlength` as the result, representing the length of the longest 
    consecutive string of '1's that can be achieved with at most `n` '0's flipped.

- In the `main` function:
  - It takes user input for the binary string `s` and the allowed number of '0's to be flipped, `n`.
  - Then, it calls the `longestConse` function with these inputs and prints the result, which is the 
  length of the longest consecutive string of '1's.

This code snippet efficiently calculates the desired result using the sliding window technique and 
should work as expected.

*/
