class Solution {
public:
    void dfs(string &num,int target,long long cur,long long pre,int idx,string temp,vector<string>&res) {
        if (idx==num.size()) {
            if (cur==target) res.push_back(temp);
            return;
        }
        
        long long s=0;
        string t="";
        for (int i=idx;i<num.size();i++) {
            s=s*10+num[i]-'0';
            if (i>idx&&num[idx]=='0') break;
            t+=num[i];
            if (idx==0) dfs(num,target,s,s,i+1,t,res);
            else {
                dfs(num,target,cur+s,s,i+1,temp+"+"+t,res);
                dfs(num,target,cur-s,-s,i+1,temp+"-"+t,res);
                dfs(num,target,cur-pre+pre*s,pre*s,i+1,temp+"*"+t,res);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num,target,0,0,0,"",res);
        return res;
    }
};
