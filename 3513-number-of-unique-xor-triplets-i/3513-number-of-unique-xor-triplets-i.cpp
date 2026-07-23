class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return n;
        int res=1;
        while(res<=n) res<<=1;
        return res;

    }
};