#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> ans;
    
    ProductOfNumbers() { }

    void add(int num) {
        ans.push_back(num);
    }

    int getProduct(int k) {
        if (k > ans.size()) return 0; 
        int s = 1;
        for (int i = ans.size() - 1; i >= 0 &&  k>0; i--) {
            s *= ans[i];
            k--;
        }
        return s;
    }
};