class Solution {
public:
    
    struct Node{
        Node* child[26];
        int num;
        vector<int> idx;
        Node() {
            memset(child,NULL,sizeof(child));
            num=-1;
            idx.clear();
        }
    };
    Node *root=new Node();
    bool check(string &word,int i,int j) {
        while(i<j) {
            if (word[i++]!=word[j--]) return false;
        }
        return true;
    }
    
    
    void add_string(string &s,int k) {
        Node *p =root;
        for (int i=s.size()-1;i>=0;i--) {
            int c=s[i]-'a';
            if (p->child[c]==NULL) p->child[c]=new Node();
            if (check(s,0,i)) p->idx.push_back(k);
            p=p->child[c];
        }
        p->num=k;;
       p->idx.push_back(k);
    }
    
    void find_string(string &s,int start,vector<vector<int>> &res) {
        Node *p=root;
        for (int i=0;i<s.size();i++) {
            int c=s[i]-'a';
            int t=p->num;
            if (t>=0&&t!=start&&check(s,i,s.size()-1)) res.push_back({start,t});
            if (p->child[c]==NULL) return ;
            p=p->child[c];
        }
        for (int j: p->idx) {
            if (j==start) continue;
            res.push_back({start,j});
        }
    }

    
    vector<vector<int>> palindromePairs(vector<string>& words) {

        for (int i=0;i<words.size();i++) add_string(words[i],i);
        vector<vector<int>> res;
        for (int i=0;i<words.size();i++) {
           find_string(words[i],i,res);
           
            
        }
        return res;
    }
};
