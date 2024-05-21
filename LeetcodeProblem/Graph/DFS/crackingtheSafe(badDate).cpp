class Solution {
public:
    int n,k,total;
    bool backtrack(string &ans,unordered_set<string>&visited) {
        if (visited.size()==total) return true;
        for (int i='0';i<'0'+k;i++) {
            ans.push_back(i);
            string cur=ans.substr(ans.size()-n);
            if (visited.find(cur)==visited.end()) {
                visited.insert(cur);
                if(backtrack(ans,visited)) return true;
                visited.erase(cur);
            }
            ans.pop_back();
        }
        return false;
    }
    string crackSafe(int n, int k) {
        this->n=n;
        this->k=k;
        total=pow(k,n);
        string ans(n,'0');
        unordered_set<string> visited={ans};
        backtrack(ans,visited);
        return ans;
    }
};
