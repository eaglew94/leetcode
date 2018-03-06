class Solution {
public:
    bool isPalindrome(int x) {
        //获取数字长度
        if(x<0) return false;
        int div=1;
        while(x/div/10>0)
        {
            div*=10;
        }
        if(div == 1 ) return true;
        while(x>0)
        {
            if(x/div!=x%10) return false;
            x=(x%div)/10;
            
            div/=100;
        }
        return true;
    }
    
};