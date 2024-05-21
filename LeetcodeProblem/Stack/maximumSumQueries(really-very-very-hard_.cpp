class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int,int>> data;
        const int n=nums1.size();
        for (int i=0;i<n;i++) {
            data.push_back({nums1[i],nums2[i]});
        }
        sort(data.rbegin(),data.rend());
        vector<tuple<int,int,int>> qq;
        const int m=queries.size();
        for (int j=0;j<m;j++) {
            auto &q=queries[j];
            qq.push_back({q[0],q[1],j});
        }
        sort(qq.rbegin(),qq.rend());
        
        vector<int> result(m);
        vector<pair<int,int>> mono;
        int i=0;
        for (auto [x,y,j]:qq) {
            while(i<n&&data[i].first>=x) {
                auto [a,b]=data[i++];
            
                int sum=a+b;
                while(mono.size()&&mono.back().second<=sum) mono.pop_back();
                if (mono.empty()||b>mono.back().first) mono.push_back({b,sum});
            }
            auto it=lower_bound(mono.begin(),mono.end(),pair<int,int>{y,INT_MIN});
            result[j]=(it==mono.end())?-1: it->second;
        }
        return result;
    }
};
