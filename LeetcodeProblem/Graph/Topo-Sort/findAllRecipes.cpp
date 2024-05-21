class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> s(supplies.begin(),supplies.end());
        unordered_map<string,vector<string>> g;
        unordered_map<string,int> fre;
        for (string &s: recipes) fre[s]=0;
        for (int i=0;i<recipes.size();i++) {
            for (int j=0;j<ingredients[i].size();j++) {
                if (s.find(ingredients[i][j])==s.end()) {
                    g[ingredients[i][j]].push_back(recipes[i]);
                    fre[recipes[i]]++;
                }
            }
        }
        queue<string> q;
        for (auto &x: fre) if (x.second==0) q.push(x.first);
        vector<string> res;
        while(q.size()) {
            string u=q.front();
            res.push_back(u);
            q.pop();
            for (string v: g[u]) {
                fre[v]--;
                if (fre[v]==0) {
                    q.push(v);
                }
            }
        }
        return res;
    }
};
