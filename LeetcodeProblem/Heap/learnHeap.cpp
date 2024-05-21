#include<iostream>
#include<set>
using namespace std;
int main() {
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.erase(9);
	for (int x: s) {
		cout<<x<<" ";
	}
}
