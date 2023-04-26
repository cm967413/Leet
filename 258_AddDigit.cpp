//Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
//Time Complexity: O(1)
class Solution {
public:
    int addDigits(int num) 
    {        
        return (num-1)%9+1;
    }
};