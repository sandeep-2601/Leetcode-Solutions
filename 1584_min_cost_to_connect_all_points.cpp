/*
    Problem link -> https://leetcode.com/problems/min-cost-to-connect-all-points/
    T.C O(N²logN)
    S.C O(N)
    where N is the number of coordinates
    Algorithm -> Prim's algorithm for Minimum Spanning Tree 
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int manhattan = 0,idx = 0,minCost = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_set<int> visited;
        pair<int,int> curr;
        
        pq.push({0,0});
        
        while(visited.size() != n) {
            
            curr = pq.top();
            pq.pop();
            
            idx = curr.second;
            
            if(visited.count(idx)) continue;
            
            minCost += curr.first;
            visited.insert(idx);
            
            for(int i=0;i<n;i++) {
                if(!visited.count(i)) {
                    manhattan = abs(points[i][0] - points[idx][0]) + abs(points[i][1] - points[idx][1]);
                    pq.push({manhattan,i});
                }
            }
        
        }
        
        return minCost;
    }
};