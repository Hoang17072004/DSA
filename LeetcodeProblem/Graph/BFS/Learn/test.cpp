#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> a={1,2,1,2,3,3,5,4,4};
	int s=0;
	for (int i=0;i<a.size();i++) s^=a[i];
	cout<<s<<endl;
}