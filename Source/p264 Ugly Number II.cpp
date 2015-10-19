#include "leetcode.h"

/**
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

 */
 
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> f(1, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        while (n > 1)
        {
            --n;
            if (f[p2] * 2 <= f[p3] * 3 && f[p2] * 2 <= f[p5] * 5)
                f.push_back(f[p2++] * 2);
            else if (f[p2] * 2 >= f[p3] * 3 && f[p3] * 3 <= f[p5] * 5)
                f.push_back(f[p3++] * 3);
            else f.push_back(f[p5++] * 5);
            if (f.back() >= f[p2] * 2) ++p2;
            if (f.back() >= f[p3] * 3) ++p3;
            if (f.back() >= f[p5] * 5) ++p5;
        }
        return f.back();
    }
};
