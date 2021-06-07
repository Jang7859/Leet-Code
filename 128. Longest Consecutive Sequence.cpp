class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int max_ = 0;
        
        for(int i:nums){
            if(m[i])continue;
            
            int left = m[i-1];
            int right = m[i+1];
            m[i] = m[i-left] = m[i+right] = left+right+1;
            max_ = max(max_, m[i]);
            
        }
        return max_;
    }
};