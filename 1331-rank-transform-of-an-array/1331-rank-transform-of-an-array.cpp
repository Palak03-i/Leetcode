class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_array=arr;
        sort(sorted_array.begin(),sorted_array.end());
        unordered_map<int,int> rank;
        int r=1;
        for(int n:sorted_array){
            if(rank.find(n)==rank.end(n)){
                rank[n]=r++;
            }
        }
        vector<int> res;
        for(int n:arr){
            res.push_back(rank[n]);
        }
        return res;
    }
};