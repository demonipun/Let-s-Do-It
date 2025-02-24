Problem Link: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/

class Solution {
private:
    void dfs(unordered_map<int, vector<int>>& ar, vector<int>& vis, vector<int>& outTime, int node) {
        vis[node]=true;
        for(int child: ar[node]) {
            if(!vis[child]) {
                dfs(ar, vis, outTime, child);
            }
        }
        outTime.push_back(node);
    }

    int maxHeight(unordered_map<int, vector<int>>& ar, int from, int notTo) {
        int ans=1;
        for(int child: ar[from]) {
            if(child==notTo) {
                continue;
            }
            ans=max(ans, maxHeight(ar, child, notTo)+1);
        }
        return ans;
    }
public:
    int maximumInvitations(vector<int>& fav) {
        int n=fav.size();
        
        // answer is maximum of maximum length cycle
        // but if u,v form 2 length cycle then
        // max(maximum length cycle, distance(u to leaf without covering any cycle) + distance(v to leaf without covering any cycle))

        // APPROACH - 1: Kosaraju (DFS)
        // (i). build graph and its transposed graph
        unordered_map<int, vector<int>> ar, tr;
        for(int i=0;i<n;i++) {
            // Each employee has a favorite person and they will attend the meeting only 
            // if they can sit next to their favorite person at the table.
            // i is dependent of fav[i]
            int u=fav[i], v=i;
            ar[u].push_back(v);
            tr[v].push_back(u);
        }

        // (ii). arrange nodes in ascending order of out-time in the original graph
        vector<int> vis(n, false);
        vector<int> outTime;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(ar, vis, outTime, i);
            }
        }

        // (iii). mark cells as unvisited & start dfs with cell having highest (decreasing) outTime on the Transposed graph
        for(int i=0;i<n;i++) {
            vis[i]=false;
        }
        
        int max_scc_sz=0;
        int sum_of_two_length_cycle=0;
        for(int i=n-1;i>=0;i--) {
            if(!vis[outTime[i]]) {
                vector<int> scc;
                dfs(tr, vis, scc, outTime[i]);
                // cout<<outTime[i]<<" "<<scc.size()<<endl;
                max_scc_sz=max(max_scc_sz, (int)scc.size());

                int sz=scc.size();
                // special case when only 2 components are connected
                if(sz==2) {
                    int a=scc[0], b=scc[1];
                    sum_of_two_length_cycle+=maxHeight(ar, a, b)+maxHeight(ar, b, a);
                }
            }
        }

        return max(max_scc_sz, sum_of_two_length_cycle);
    }
};