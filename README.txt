An anagram of a string is any string that can be formed using the same letters as the original. 

Given a string and a rank K, anagram.cpp will determine the Kth such anagram according to alphabetical order.

Example:
TOMMARVOLORIDDLE 54852357601
IAMLORDVOLDEMORT

ALTERING 39982
TRIANGLE

anagram.cpp identifies in which range does K falls and finds the corresponding letter to it.(left->right)
The range keeps decreasing as each letters is identified. 
This reduces the search space from n to logn, where n is the permutation of the given string.

The range is calculated based on 2 conditions.
case 1: number of time a letter1 appears in the string is same as the number of time a letter2 appears in the same string
        Eg: ABCABCABC 
case 2: number of occurance of each letter is different. 
        Eg: AACCCPP

Working:
string: AMC
K: 5 ==> 4 (permutation starts from 0 in this code)
result: MAC



0 1 2
A C M
permutation: 6    range: 2
S = 0   2   4
E = 1   3   5
letter+=M

0 1 
A C 

permutation: 2    range: 1
S = 4
E = 4
letter+= A

0
C
letter+= C


output: MAC
