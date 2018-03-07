class Solution {
public:
    int reverse(int x) {
        bool flag=x>0?true:false;
        string str=to_string(x);
        const uint max0=2147483647;
        const uint max1=2147483648;
        if(flag)
        {
            std::reverse(str.begin(),str.end());
        }
        else
        {
            std::reverse(str.begin()+1,str.end());
        }
      
        string ustr=flag ? str.substr(0,str.length()): str.substr(1,str.length());
        
        istringstream iss(ustr);  
        uint y=0;
        iss>>y;

        if(flag)
        {
            if(y>max0) return 0;
        }
        else
        {
            if(y>max1) return 0;
        }
        //判断是否超过32位的int
        
        return stoi(str); 
    }
};


class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x)
        {
            int tmp=res*10+(x%10);
            if(tmp/10!=res) return 0;
            res=tmp;
            x=x/10;
        }
        return res;
    }
};