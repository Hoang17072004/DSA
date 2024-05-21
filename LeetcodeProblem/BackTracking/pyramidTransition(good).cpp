class Solution {
public:
    bool helper(string bottom,unordered_map<string,vector<char>>&m,int start,string next) {
        if (bottom.size()==1) return true;
        if (invalid.count(bottom)) return false;
        if (start==bottom.size()-1) return helper(next,m,0,"");
        for (char c: m[bottom.substr(start,2)]) if (helper(bottom,m,start+1,next+c)) return true;
        invalid.insert(bottom);
        return false;
    }
    unordered_set<string> invalid;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> m;
        for (int i=0;i<allowed.size();i++) {
            m[allowed[i].substr(0,2)].push_back(allowed[i][2]);
        }
        return helper(bottom,m,0,"");
    }
};
