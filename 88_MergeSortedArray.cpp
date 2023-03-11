#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m + n - 1; i >=0; i--)
        {
            if(n == 0) return;
            if(m == 0)
            {
                nums1[i] = nums2[n-1];
                n--;
                continue;
            }
            if(nums1[m-1] >= nums2[n-1])
            {
                nums1[i] = nums1[m-1];
                m--;
            }
            else
            {
                nums1[i] = nums2[n-1];
                n--;
            }
        }
        return;
    }
};

class Solution {
public:
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int i = m - 1, j = n - 1, k = m + n - 1;
     while(i >= 0 and j >= 0) {
         if(nums1[i] < nums2[j]) {
             nums1[k--] = nums2[j--];
         } else {
             nums1[k--] = nums1[i--];
         }
     }
     while(j >= 0) {
         nums1[k--] = nums2[j--];
     }
 }
};