class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int found;
        int max = 0;
        
        if(s.size() == 1) return 1;
        
        for(end; end < s.size(); end++)
        {
            found = s.substr(0, end).rfind(s[end])+1;
            if(found != string::npos)
            {
                if(found >= start)
                {
                    start = int(found);
                }
            }
            max = std::max(max, end-start+1);
        }
        return max;
    }
};