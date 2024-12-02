Palindrome Partitioning


Given a string s, partition s such that every substring of the partition is a palindrome. Find all possible ways of palindromic partitioning.

Example:
s: “aabc”
Partitions: [ 
  [“a”, “a”, “b”, “c”],
  [“aa”, “b”, “c”]
]
Testing
Input Format
The first line contains an integer ‘T’ denoting the number of test cases.

For each test case, the input has one line with the string ‘s’.

Output format
For each test case, the output has following lines:

The first line contains an integer ‘n’ denoting the number of palindromic partitions possible.
The next n lines contain space separated strings denoting the strings of a particular partition.
Sample Input
3
abbc
a
cdc
Expected Output
2
a b b c
a bb c
1
a
2
c d c
cdc