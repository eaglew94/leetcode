class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxLength=0;
        for(int i=0;i<s.length();i++)
        {
            string str_at_i="";
            str_at_i+=s[i];
            for(int j=i+1;j<s.length();j++)
            {
                bool bRepeat=false;
                for(int k=0;k<str_at_i.length();k++)
                {
                    if(s[j] == str_at_i[k])
                    {
                        bRepeat=true;
                        break;
                    }
                }
                if(bRepeat) break;
                str_at_i.append(1,s[j]);
            }
            if(str_at_i.length()>maxLength) maxLength=str_at_i.length();
        }
        return maxLength;

        
        
    }
};
