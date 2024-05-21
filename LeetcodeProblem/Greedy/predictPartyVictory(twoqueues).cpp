class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad,dir;
        int n=senate.size();
        for (int i=0;i<n;i++) {
            if (senate[i]=='R') rad.push(i);
            else dir.push(i);
        }
        while(rad.size()&&dir.size()) {
            if (rad.front()<dir.front()) {
                rad.push(n++);
            } else dir.push(n++);
            rad.pop(),dir.pop();
        }
        return (rad.empty())?"Dire":"Radiant";
    }
};
