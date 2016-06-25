/*
 ===================================================================================
 *     File Name: 65 - Valid Number.cpp
 *   Description: https://leetcode.com/problems/valid-number/
 *        Author: Stoney
 *      Category: 数字、正则式
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/19
 *      Run Time: 12ms, beats 10.97%
 *     Solutions: 1.状态机，状态转移
 *
 *       Version: 2.0
 *   Submit Time: 2016/05/19
 *      Run Time: 12ms, beats 10.97%
 *     Solutions: 1.处理法，按照数字的处理流程处理字符串，处理结束后到达末尾则结束
 ===================================================================================
 */

class Solution {
public:
    bool isNumber(string s) {
        int status = 0;

        for(int i=0;i<s.length() && status>=0;++i){
            switch(status){
            case 0:
                if(s[i]==' ') {}
                else if(s[i]=='+' || s[i]=='-')
                    status = 1;
                else if('0'<=s[i] && s[i]<='9')
                    status = 2;
                else if(s[i]=='.') { //.55
                    if(judge(s, i)) status = -1;       //“.”不是一个数字
                    else status = 3;
                }
                else status = -1;
                break;
            case 1:
                if('0'<=s[i] && s[i]<='9')
                    status = 2;
                else if(s[i]=='.') { //.55
                    if(judge(s, i)) status = -1;
                    else status = 3;
                }
                else status = -1;
                break;
            case 2:
                if('0'<=s[i] && s[i]<='9') {}
                else if(s[i]=='.') { //.55
                    if(judge(s, i)) status = -1;
                    else status = 3;
                }
                else if(s[i]=='e' || s[i]=='E')
                    status = 4;
                else if(s[i]==' ')
                    status = 7;
                else status = -1;
                break;
            case 3:
                if('0'<=s[i] && s[i]<='9') {}
                else if(s[i]=='e' || s[i]=='E')
                    status = 4;
                else if(s[i]==' ')
                    status = 7;
                else status = -1;
                break;
            case 4:
                if(s[i]=='+' || s[i]=='-')
                    status = 5;
                else if('0'<=s[i] && s[i]<='9')
                    status = 6;
                else status = -1;
                break;
            case 5:
                if('0'<=s[i] && s[i]<='9')
                    status = 6;
                else status = -1;
                break;
            case 6:
                if('0'<=s[i] && s[i]<='9')
                    status = 6;
                else if(s[i]==' ')
                    status = 7;
                else status = -1;
                break;
            case 7:
                if(s[i] == ' ')
                    status = 7;
                else status = -1;
                break;
            default: break;
            }
        }

        return (status==2 || status==3 || status==6 || status==7);
    }

private:
    bool static judge(const string &s, int i){
        if( (i==0 || s[i-1]<'0' || s[i-1]>'9')
            &&
            (i==s.length()-1 || s[i+1]<'0' || s[i+1]>'9')
          )
            return true;
        return false;
    }
};

// version 2.0
class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        if(n == 0) return false;

        int i = 0;
        while(s[i] == ' ') ++i;

        if(s[i]=='+' || s[i]=='-') ++i;

        int digits_count = 0;
        while(isdigit(s[i])) {
            ++i;
            ++digits_count;
        }

        if(s[i] == '.') ++i;

        while(isdigit(s[i])) {
            ++i;
            ++digits_count;
        }

        if(digits_count == 0) return false;

        if(s[i]=='e' || s[i]=='E') {
            ++i;
            if(s[i]=='-' || s[i]=='+') ++i;

            digits_count = 0;
            while(isdigit(s[i])) {
                ++i;
                ++digits_count;
            }
            if(digits_count == 0) return false;
        }

        while(s[i] == ' ') ++i;

        return i==n;
    }
};
