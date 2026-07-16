class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd;
        int maximum=0;
        for(int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
            prefixGcd.push_back(__gcd(maximum,nums[i]));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int smallest=0;
        int largest=n-1;
        long long ans=0;
        while(smallest<largest)
        {
            ans+=__gcd(prefixGcd[smallest],prefixGcd[largest]);
            smallest++;
            largest--;

        }
        return ans;

    }
};