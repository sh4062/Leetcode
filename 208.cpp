class Trie {
bool is_end;
Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        is_end=false;
        memset(next,0,sizeof(next));

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(auto i:word){
            if(node->next[i-'a']==nullptr){
                node->next[i-'a']=new Trie();
            }
            node = node->next[i-'a'];
        }
        node->is_end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(auto i:word){
            if(node->next[i-'a']==nullptr){
                return false;
            }
            node = node->next[i-'a'];
        }
        if(node->is_end==true)return true;
        return false;

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto i:prefix){
            if(node->next[i-'a']==nullptr){
                return false;
            }
            node = node->next[i-'a'];
        }
        return true;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
