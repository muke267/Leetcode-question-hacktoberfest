class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        int num1=-1;
        int num2=-1;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(num1==nums[i])
            {  
                cnt1++;
            }
            else if(num2==nums[i])
            {
                cnt2++;
            }
            else if(cnt1==0)
            {
                num1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0)
            {
                num2=nums[i];
                cnt2=1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
            
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(num1==nums[i])
                cnt1++;
            else if(num2==nums[i])
                cnt2++;
        }
        if(n/3<cnt1)
            v.push_back(num1);
        if(n/3<cnt2)
            v.push_back(num2);
        return v;
    }
};