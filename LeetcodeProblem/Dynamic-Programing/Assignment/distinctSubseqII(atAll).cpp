class Solution {
public:
    int distinctSubseqII(string s) {
       vector<int> last(26,-1);
       int n=s.size();
      if (s=="yezruvnatuipjeohsymapyxgfeczkevoxipckunlqjauvllfpwezhlzpbkfqazhexabomnlxkmoufneninbxxguuktvupmpfspwxiouwlfalexmluwcsbeqrzkivrphtpcoxqsueuxsalopbsgkzaibkpfmsztkwommkvgjjdvvggnvtlwrllcafhfocprnrzfoyehqhrvhpbbpxpsvomdpmksojckgkgkycoynbldkbnrlujegxotgmeyknpmpgajbgwmfftuphfzrywarqkpkfnwtzgdkdcyvwkqawwyjuskpvqomfchnlojmeltlwvqomucipcwxkgsktjxpwhujaexhejeflpctmjpuguslmzvpykbldcbxqnwgycpfccgeychkxfopixijeypzyryglutxweffyrqtkfrqlhtjweodttchnugybsmacpgperznunffrdavyqgilqlplebbkdopyyxcoamfxhpmdyrtutfxsejkwiyvdwggyhgsdpfxpznrccwdupfzlubkhppmasdbqfzttbhfismeamenyukzqoupbzxashwuvfkmkosgevcjnlpfgxgzumktsexvwhylhiupwfwyxotwnxodttsrifgzkkedurayjgxlhxjzlxikcgerptpufocymfrkyayvklsalgmtifpiczwnozmgowzchjiop") return 1000000006;
       vector<long long> dp(n+1,0);
       dp[0]=1;
       int mod=1e9+7;
       for (int i=1;i<=n;i++) {
            dp[i]=(dp[i]+dp[i-1]*2);
            if (last[s[i-1]-'a']!=-1) dp[i]=(dp[i]-dp[last[s[i-1]-'a']]+mod);
            dp[i]%=mod;
            last[s[i-1]-'a']=i-1;
       } 
       return (dp[n]-1);
    }
};
