#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+1;
int f,s,g,u,d;
int visit[maxN],number[maxN];
void bfs() {
	fill_n(number,f+1,0);
	fill_n(visit,f+1,false);
	queue<int> q;
	q.push(s);
	visit[s]=true;
	while(q.size()) {
		int x=q.front();
		q.pop();
		if (x==g) return;
		for (int y:{x+u,x-d}) {
			if (y>f||y<1) continue;
			if (!visit[y]) {
				visit[y]=true;
				number[y]=number[x]+1;
				q.push(y);
			}
		}
	}
	number[g]=-1;
}
int main() {
	cin>>f>>s>>g>>u>>d;
	bfs();
	if (number[g]!=-1) cout<<number[g];
	else cout<<"use the stairs";
}
