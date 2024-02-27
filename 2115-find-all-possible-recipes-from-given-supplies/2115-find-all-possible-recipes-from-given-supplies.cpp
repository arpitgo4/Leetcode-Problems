class Solution {
public:
    
    // Time: O(V + E)
    // Space: O(V + E)
    
    unordered_map<string, vector<string>> G;
    unordered_map<string,int> in;
    
    void build_graph(vector<string>& recipes, vector<vector<string>>& ingredients) {
        int N = recipes.size();
        
        for (int i = 0; i < N; i++) {
            for (string& ingredient : ingredients[i]) {
                G[ingredient].push_back(recipes[i]);
                in[recipes[i]]++;
            }
        }
    }
    
    vector<string> kahns_topological_sorting(vector<string> supplies) {
        queue<string> q;
        for (string& s : supplies)
            q.push(s);
        
        vector<string> res;
        while (!q.empty()) {
            string ing = q.front();
            q.pop();
            
            for (string& next : G[ing]) {
                in[next]--;
                if (in[next] == 0) {
                    res.push_back(next);
                    q.push(next);
                }
            }
        }
        
        return res;
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        build_graph(recipes, ingredients);
    
        return kahns_topological_sorting(supplies);
    }
};