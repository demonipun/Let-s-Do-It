Problem Link: https://www.naukri.com/code360/problems/water-supply-in-a-village_1380956
              https://leetcode.ca/all/1168.html

#include <bits/stdc++.h>

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
	// Connecting houses via pipes or digging wells if the house is not connected
	int m=pipes.size();
	vector<vector<pair<int, int>>> ar(n+1);
	// We assume we are at a dummy node '0' and it has edges to all the nodes with cost = wells[i-1]
	// So now it's a proper MST problem, from node 0 we need to visit all nodes till node N && 
	// node 0 is connected to all the nodes which handles case of just digging wells at some nodes.

	// handle the case digging wells
	for(int i=1;i<=n;i++) {
		ar[0].push_back({i, wells[i-1]});
		ar[i].push_back({0, wells[i-1]});
	}
	for(int i=0;i<m;i++) {
		int x=pipes[i][0], y=pipes[i][1], c=pipes[i][2];
		ar[x].push_back({y, c});
		ar[y].push_back({x, c});
	}
	// MST : PRIMS Algorithm [GREEDY]
	vector<int> minCost(n+1, INT_MAX);
	vector<bool> vis(n+1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	minCost[0]=0;
	pq.push({minCost[0], 0}); // minCost[node], node

	int ans=0;
	while(!pq.empty()) {
		pair<int, int> p=pq.top();
		pq.pop();
		int cost=p.first, node=p.second;
		if(vis[node]) { // if the node is already visited don't add it to the solution set 
			continue;
		}
		vis[node]=true; // path added to the solution set
		ans+=cost;

		for(pair<int, int> x: ar[node]) {
			int child=x.first, w=x.second;
			if(!vis[child] && w<minCost[child]) {
				minCost[child]=w;
				pq.push({w, child});
			}
		}
	}
	return ans;
}