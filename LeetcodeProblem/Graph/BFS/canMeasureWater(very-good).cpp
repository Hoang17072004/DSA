class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x=jug1Capacity,y=jug2Capacity,z=x+y;
        int steps[]={x,-x,-y,y};
        vector<bool> visit(z+1,0);
        queue<int> q;
        q.push(0);
        visit[0]=1;
        while(q.size()) {
            int node=q.front();
            q.pop();
            if (node==targetCapacity) return true;
            for(int i=0;i<4;i++) {
                int newNode=node+steps[i];
                if (newNode>=0&&newNode<=z&&!visit[newNode]) {
                    visit[newNode]=1;
                    q.push(newNode);
                }
            }
        }
        return false;
    }
};
