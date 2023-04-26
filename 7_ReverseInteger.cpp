class Solution {
public:
    int reverse(int x) {
        //+12300
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        //00321+
        int sum = 0;
        int sign = 1;
        for(auto c : s)
        {
            if(c == '-')    {sign = -1; continue;}
            else if(c == '+') {sign = 1; continue;}
            if(0 <= c - '0' && c - '0' <= 9)
            {
              if(sum > INT_MAX/10)
              {
                return 0;
              }
              sum = sum*10 + (c - '0');
            }
        }

        return sum*sign;
    }
};