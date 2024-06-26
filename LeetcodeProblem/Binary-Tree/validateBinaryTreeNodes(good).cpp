class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root=findRoot(n,leftChild,rightChild);
        if (root==-1) return false;
        unordered_set<int> seen;
        stack<int> st;
        seen.insert(root);
        st.push(root);
        while(st.size()) {
            int node=st.top();
            st.pop();
            int children[]={leftChild[node],rightChild[node]};
            for (int child: children) {
                if (child!=-1) {
                    if (seen.find(child)!=seen.end()) return false;
                    st.push(child);
                    seen.insert(child);
                }
            }
        }
        return seen.size()==n;
    }
    int findRoot(int n,vector<int> &left,vector<int> &right) {
        unordered_set<int> children;
        children.insert(left.begin(),left.end());
        children.insert(right.begin(),right.end());
        for (int i=0;i<n;i++) {
            if (children.find(i)==children.end()) return i;
        }
        return -1;
    }
};
