int balancedString(string s) {
        int n=s.size();
        int qtn=n/4;
        map<char,int> m;
        for (int i=0;i<n;i++) {
            m[s[i]]++;
        }
        int i=0,res=n;
        if (m['Q']==qtn&&m['W']==qtn&&m['R']==qtn&&m['E']==qtn) return 0;
        for (int j=0;j<n;j++) {
            m[s[j]]--;
            while(i<=j&&m['Q']<=qtn&&m['W']<=qtn&&m['R']<=qtn&&m['E']<=qtn) {
           m[s[i]]++;
        //    cout<<"m["<<s[i]<<"]"<<m[s[i]]<<"\t";
        //    cout<<"j="<<j<<"\ti="<<i<<endl;
            res=min(res,j-i+1);
                
                
                i++;
            }
        }
        return res;

    }
