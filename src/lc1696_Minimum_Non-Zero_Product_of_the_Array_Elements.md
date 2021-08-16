Actually, in this problem there is HUGE hint in examples, at least I was able to get the direct formula from example 3.

Let us look at our numbers and see what happens, when we swap two bits: in fact the sum of all numbers will rest the same! So, we need to minimize product of numbers, if we have fixed sum and not allowed to have zeroes. Let us provide estimation and example:

Estimation (let p = 4 for simplicity, but logic is the same for general case) then we have numbers 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15). Notice that if we take two numbers, say 4 and 7 and decrease smallest of them by one and increase biggest by one, sum will be the same and product become smaller - it can be proved easily for any a <= b: (a-1)*(b+1) < a*b. Let us continue this process until we can: we do it for pairs until one element in pair become equal to 1. Then in the end we have (1, 1, 1, 1, 1, 1, 1, 14, 14, 14, 14, 14, 14, 14, 15).
Example: in fact we can do this if we allowed to manipulate bits: we can make each pair (i, 15 - i) equal to (1, 14), because in this pair for all bits places, we have different bits, like 1001 and 0110. Number 1111 will not have pair because its pair is 0.
So, finally, we just can write direct formula.

Complexity
Time complexity is O(p), because python allows to do fast power, space complexity is O(1).

Code
class Solution:
def minNonZeroProduct(self, p):
return (pow(2**p -2, 2**(p-1) - 1, 10**9 + 7) * (2**p - 1)) % (10**9 + 7)

reference: https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/discuss/1403913/Python-math-oneliner-with-proof-explained