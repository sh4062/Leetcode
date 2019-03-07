/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：242.cpp
*   Creator    ：Max
*   Date       ：2019/03/07
*   Description：
*
================================================================*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> a,b;
        for(auto i:s){
            a[i]++;
        }
        for(auto i:t){
            b[i]++;
        }
        for(auto i:a){
            for(auto j:b){
                if(i.first==j.first){
                    if(i.second!=j.second)
                        return false;
                }else{
                    if(a.find(j.first)==a.end()||b.find(i.first)==b.end())
                        return false;
                }
            }
    }
        return true;}
        
};
