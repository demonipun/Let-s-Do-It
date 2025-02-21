Problem Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int inf=1e6;
        vector<vector<int>> dist(n, vector<int>(n, inf)); // initially each node is at infinity from another
        for(vector<int> edge: edges) {
            int u=edge[0], v=edge[1], w=edge[2];
            dist[u][v]=w;
            dist[v][u]=w;

            dist[u][u]=0;
            dist[v][v]=0;
        }

        // Floyd Warshall
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(dist[i][k]+dist[k][j]<dist[i][j]) {
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }

        // Only those cities are counted whose shortest distance from source node <= distanceThreshold
        int ans=-1, minCities=inf;
        for(int i=0;i<n;i++) {
            int cities=0;
            for(int j=0;j<n;j++) {
                if(i==j) {
                    continue;
                }
                if(dist[i][j]<=distanceThreshold) {
                    cities++;
                }
            }

            if(cities<=minCities) {
                minCities=cities;
                ans=i;
            }
        }
        return ans;
    }
};