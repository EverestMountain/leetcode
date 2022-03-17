#include "header/common.h"
class Solution {
    int getDistance(vector<int>&a, vector<int>&b){
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int d=getDistance(points[i],points[j]);
                mp[d]=(mp.find(d)==mp.end())?1:(mp[d]+1);
            }
            for(auto& kv:mp){
                ans+=kv.second*(kv.second-1);
            }
            mp.clear();
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> points={{0,0},{1,0},{-1,0},{0,1},{0,-1}};
    Solution sol;
    cout<<sol.numberOfBoomerangs(points)<<endl;
    return 0;
}