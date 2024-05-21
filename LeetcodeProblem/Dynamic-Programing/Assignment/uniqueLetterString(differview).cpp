class Solution {
public:
	//Sometimes you should see the problem at the different view
	//the important thing of the dse is use know the base knowldege and you
	//shoud show problem at the different view base on your base knowldge and
	//(Try something else it can make you better)
    int uniqueLetterString(string S) {
        int index[26][2],res=0,N=S.length(),mod=1e9+7;
        memset(index,-1,sizeof(int)*52);
        for (int i=0;i<N;i++) {
            int c=S[i]-'A';
            res=(res+(i-index[c][1])*(index[c][1]-index[c][0])%mod)%mod;
            index[c][0]=index[c][1];
            index[c][1]=i;
        }
        for (int c=0;c<26;c++) {
            res=(res+(N-index[c][1])*(index[c][1]-index[c][0])%mod)%mod;
        }
        return res;
    }
};
