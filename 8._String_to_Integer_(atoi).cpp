class Solution {
public:
    int myAtoi(string s) {
        int cnt = 0, ind = 0, sign = 1;
     long result =0;
        while (ind < s.length() && s[ind] == ' ')
            ind++;

        while (ind < s.length() && (s[ind] == '+' || s[ind] == '-')) {
              if(cnt == 1)
              return 0;
            
            if (s[ind] == '-')  { 
                sign = -1;}

            ind++;
             cnt++;
            }

           while (ind < s.length() && isdigit(s[ind])) {
            result = result * 10 + (s[ind] - '0');
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;

            ind++;
        }

        return (int)(result * sign);
        }
    };