class Solution {
public:
    void dfs(string &airport,unordered_map<string,vector<string>> &g,vector<string>&itinerary) {
        while(g[airport].size()) {
            string next=g[airport].back();
            g[airport].pop_back();
            dfs(next,g,itinerary);
        }
        itinerary.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> g;
        for (auto &ticket: tickets) {
            g[ticket[0]].push_back(ticket[1]);
        }
        for (auto &temp: g) {
            sort(temp.second.rbegin(),temp.second.rend());
        }
        vector<string> initerary;
        string jfk="JFK";
        dfs(jfk,g,initerary);
        reverse(initerary.begin(),initerary.end());
        return initerary;
    }
};
