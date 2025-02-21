Problem Link: https://leetcode.ca/all/1820.html

class Solution {
private:
    int bfs(unordered_map<int, vector<int>>& ar, vector<vector<int>>& capacity, vector<int>& parent, int src, int tar) {
        fill(parent.begin(), parent.end(), -1); // for new values of parents each time
        parent[src]=-2;
        queue<pair<int, int>> q;
        q.push({src, INT_MAX});
        while(!q.empty()) {
            int curr=q.front().first, flow=q.front().second;
            q.pop();
            for(int next: ar[curr]) {
                cout<<curr<<" "<<next<<" "<<capacity[curr][next]<<endl;
                if(parent[next]==-1 && capacity[curr][next]) {
                    parent[next]=curr;
                    int newFlow=min(flow, capacity[curr][next]);
                    if(next==tar) {
                        cout<<newFlow<<endl;
                        return newFlow;
                    }
                    q.push({next, newFlow});
                }
            }
        }
        return 0;
    }
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        // 'm' boys & 'n' girls
        unordered_map<int, vector<int>> ar;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    ar[i].push_back(m+j); // generalizing algorithm by adding 1 as the node weight
                    ar[m+j].push_back(i);
                }
            }
        }
        // Now we have a directed graph starting from Source to boy nodes
        // then from boy nodes to girl nodes and ultimately, to the Target.
        // We need to find the Maximum Flow with weight of each edge being 1.
        // add 'source' node -> connects to 'm' boys
        vector<vector<int>> capacity(m+n+3, vector<int>(m+n+3));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                capacity[i][m+j]=grid[i][j];
            }
        }
        int src=m+n;
        for(int i=0;i<m;i++) {
            ar[src].push_back(i);
            capacity[src][i]=1;
        }
        // add 'target' node -> connects to 'n' girls
        int tar=m+n+1;
        for(int j=0;j<n;j++) {
            ar[m+j].push_back(tar);
            capacity[m+j][tar]=1;
        }
        int flow=0, newFlow;
        vector<int> parent(m+n+3);
        while(newFlow=bfs(ar, capacity, parent, src, tar)) { // newFlow!=0
            flow+=newFlow;
            int curr=tar;
            while(curr!=src) {
                int prev=parent[curr];
                capacity[prev][curr]-=newFlow;
                capacity[curr][prev]+=newFlow;
                curr=prev;
            }
        }
        return flow;
    }
};