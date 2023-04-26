
class Solution {
public:
    int myAtoi(string s) 
    {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == n) return 0;
        int sign = 1;
        if(s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
        {
            sign = 1;
            i++;
        }
        long long ans = 0;
        while(i < n && s[i] >= '0' && s[i] <= '9')
        {
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && (s[i] - '0') > INT_MAX%10))
            {
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            ans = ans * 10 + (s[i] - '0');
            i++;
        }
        // if(ans * sign > INT_MAX) return INT_MAX;
        // if(ans * sign < INT_MIN) return INT_MIN;
        return ans * sign;
        
    }
};