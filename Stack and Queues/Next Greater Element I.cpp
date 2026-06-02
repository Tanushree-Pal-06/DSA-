class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        unordered_map<int,int> mpp;
        for(int i=0;i<nums2.size();i++){
            mpp[nums2[i]]=i;
        }
        for(int i=0;i<nums1.size();i++){
            int index=mpp[nums1[i]];
            while(index<nums2.size()){
                if(nums2[index]>nums1[i]){
                    ans[i]=nums2[index];
                    break;
                }
                if(index==nums2.size()-1 && nums2[index]<=nums1[i]){             ans[i]=-1;

                }
                index++;
            }
        }
        return ans;
    }
};
