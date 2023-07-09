#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (1LL*(res) * x%m)%m;
            n--;
        }
        else
        {
            x =(1LL* (x)%m * (x)%m)%m;
            n = n / 2;
        }
    }
    return res;
}