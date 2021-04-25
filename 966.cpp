class Solution {
public:
void ToLowerString(string &str)  
{  
    transform(str.begin(), str.end(), str.begin(), (int (*)(int))tolower);  
}  
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;
        unordered_map<string,int>mp1;
        unordered_map<string,string>mp2;
        unordered_map<string,string>mp3;
        for(auto i:wordlist){
            string tmp = i;
            mp1[i]++;
            ToLowerString(i);
            if(mp2.find(i)==mp2.end())
            mp2[i]=tmp;
            string tmp2 = tmp;
            for(auto &j:i)
            {
                 if(j=='a'||j=='e'||j=='i'||j=='o'||j=='u'||j=='A'||j=='E'||j=='I'||j=='O'||j=='U')
                   j='*';


            }
            if(mp3.find(i)==mp3.end())
            mp3[i]=tmp2;
            //cout<<tmp2<<endl;
        }
        for(auto i:queries){
            string tmp = i;
            ToLowerString(tmp);
            if(mp1.find(i)!=mp1.end()){
                res.push_back(i);

            }
            else if(mp2.find(tmp)!=mp2.end()){
                res.push_back(mp2[tmp]);

            }else{
                
                for(auto &j:tmp){
                  
                    if(j=='a'||j=='e'||j=='i'||j=='o'||j=='u'||j=='A'||j=='E'||j=='I'||j=='O'||j=='U')
                   j='*';}
                   if(mp3.find(tmp)!=mp3.end()){
                res.push_back(mp3[tmp]);

            }else{
                res.push_back(string(""));
            }


                

            }

        }
        return res;

    }
};
