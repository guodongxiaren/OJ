//https://leetcode.com/problems/string-to-integer-atoi/description/
#include <ctype.h>
class Solution {
public:
    int myAtoi(string str) {

        bool header = true;
        int val = 0;
        int sign = 1;
        for (int i = 0; i < str.size(); ++i) 
        {
            char ch = str[i];
            if (header && isspace(ch))
            {
                continue;
            }
                
            if (header == true) 
            {
                header = false;
                if (ch == '+') 
                {
                    sign = 1;
                    continue;
                } 
                else if (ch == '-') 
                {
                    sign = -1;
                    continue;
                } 
            }
            if (isdigit(ch)) 
            {
                long long t = val;
                t = t*10 + ch - '0';
                if (sign == 1 && t >= INT_MAX) {
                    return INT_MAX;
                } 
                else if (sign == -1 && -t <= INT_MIN) {
                    return INT_MIN;
                }
                val = val*10 + ch - '0';
            } 
            else 
            {
                return sign*val;
            }
            
        }

        return sign*val;
    }
};
