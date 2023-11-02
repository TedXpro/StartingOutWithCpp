class Solution
{
public:
    bool checkPalindrome(string str)
    {
        string temp = "";
        for (int i = str.length() - 1; i >= 0; i--)
            temp += str[i];
        return temp == str;
    }
    string longestPalindrome(string s)
    {
        string substring = "";
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            int n = s.find(ch, i);
            while (n != -1 && n < s.length())
            {
                string str = s.substr(i, n - i + 1);
                if (checkPalindrome(str) && str.length() > substring.length())
                    substring = str;
                n = s.find(ch, n);
            }
        }
        return substring;
    }
};