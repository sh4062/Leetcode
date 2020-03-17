class Solution {
private:
    void split(const string& s,vector<string>& sv,const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back((temp));
    }
    return;
}
public:
    string defangIPaddr(string address) {
        string res;
        vector<string> sv;
    split(address, sv, '.');
    int i = 0;
    for (const auto& s : sv) {
        res = res + s;
        if(i<3){
        res = res + +"[.]";
            i++;}
    }
        return res;
    }
};