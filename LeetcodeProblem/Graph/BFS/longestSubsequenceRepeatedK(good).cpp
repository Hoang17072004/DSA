class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=26;
        string res="";
        queue<string> q;
        q.push("");
        while(q.size()) {
            int size=q.size();
            while(size--) {
                string cur=q.front();
                q.pop();
                for (int i=0;i<n;i++) {
                    string next=cur+(char)('a'+i);
                    if (isSub(s,next,k)) {
                        res=next;
                        q.push(next);
                    }
                }
            }
        }
        return res;
    }
    bool isSub(string s,string sub,int k) {
        int j=0;
        int repeat=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]==sub[j]) {
                j++;
                if (j==sub.size()) {
                    repeat++;
                    if (repeat==k) return true;
                    j=0;
                }
            }
        }
        return false;
    }
};
