#include<bits/stdc++.h>
using namespace std;
const int maxN=300;
int n,m;
bool a[maxN][maxN],visit[maxN][maxN];
vector<int> slicks;
int moveX={0,0,1,-1};
int moveY={1,-1,0,0};
void reset(){
	slicks.clear();
	for (int i=1;i<=n;i++) 
	fill_n(visit[i],m+1,false);
}
void bfs(int sx,int sy) {
	int sizeSlicks=1;
	queue<pair<int,int>> q;
	q.push({sx,sy});
	visit[sx][sy]=true;
	while(q.size()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for (int i=0;i<4;i++) {
			int u=x+moveX[i];
			int v=y+moveY[i];
			if (u>n||u<1) continue;
			if (v>m||v<1) continue;
			if (a[u][v]&&!visit[u][v]) {
				visit[u][v]=true;
				sizeSlicks++;
				q.push({u,v});
			}
		}
	}
	return sizeSlicks;
}
int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) cin>>a[i][j];
		for (int i=1;i<=n;i++) 
		for (int j=1;j<=m;j++) 
		if (a[i][j]&&!visit[i][j])
		slicks.push_back(bfs(i,j));
		
	}
}
