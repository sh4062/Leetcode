class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char,int>need,window;
        for(char c:t)need[c]++;
        int left = 0,right = 0;
        int valid = 0;
        //输出
        int start=0,len=INT_MAX;
        while(right<s.size()){
            char c = s[right];
            //增大窗口
            right++;
            //更新window
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid++;
                }
            }
            //cout<<valid<<"  "<<right<<endl;
            while(valid==need.size()){
                //更新输出
                if(right-left<len){
                    len=right-left;
                    start=left;
                }
                char d = s[left];
                //缩小窗口 
                left++;
                //更新window
                if(need.count(d)){
                    if(window[d]==need[d]){
                        valid--;
                    }
                    window[d]--;
                }
                
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};
