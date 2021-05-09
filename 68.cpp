class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        string tmp;
        int cnt1 = 0;
        int cnt2 = 0;
        int interval1 = -1;
        int pre = 0;
        int i = 0;
        for(i= 0;i<words.size();i++){
            cnt1+=words[i].size();
            if(cnt1+interval1>=maxWidth){
                int cur_len = 0;
                for(int j = pre;j<i;j++){
                    cur_len+=words[j].size();
                    //tmp=tmp+words[j];
                }
                int lefts = maxWidth-cur_len;
                if(interval1==0)interval1=1;
                int mean = lefts/interval1;
                //cout<<cur_len<<endl;
                int mean_left = lefts%interval1;
                for(int j = pre;j<i-1;j++){
                    
                    tmp=tmp+words[j];
                    if(j!=i-1)
                    for(int k = 0;k<mean;k++){
                        tmp=tmp+" ";
                    }
                    if(mean_left){
                        tmp=tmp+" ";
                        mean_left--;
                    }
                }
                tmp=tmp+words[i-1];
                while(tmp.size()<maxWidth){
                tmp=tmp+" ";
                }
                cnt2++;
                cnt1=0;
                interval1=-1;
                pre = i;
                i--;
                
                res.push_back(tmp);
                tmp.clear();
                continue;
            }
            interval1+=1;
        }
        //cout<<pre;
        tmp.clear();
        for(int j = pre;j<words.size();j++){
                    
                tmp=tmp+words[j];
                if(j!=words.size()-1)
                tmp=tmp+" ";
        }
        while(tmp.size()<maxWidth){
            tmp=tmp+" ";
        }
        res.push_back(tmp);
        return res;

    }
};
