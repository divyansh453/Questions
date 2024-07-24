class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<10;i++){
            mpp[i]=mapping[i];
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];
            int newval=0;
            int mul=1;
            if(val==0){
                ans.push_back(mpp[0]);
            }
            else{
            while(val){
                int mod=val%10;
                val/=10;
                newval+=mpp[mod]*mul;
                mul*=10;
            }
            ans.push_back(newval);
            }
        }

        vector<pair<int, int>> pairedVec;
        for (size_t i = 0; i < nums.size(); ++i) {
        pairedVec.emplace_back(ans[i], nums[i]);
    }

    stable_sort(pairedVec.begin(), pairedVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    for (size_t i = 0; i < nums.size(); ++i) {
        nums[i] = pairedVec[i].second;
    }
        return nums;
    }
};
