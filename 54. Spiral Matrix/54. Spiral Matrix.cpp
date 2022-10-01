class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int t=0, l=0, b=matrix.size()-1, r=matrix[0].size()-1, dir=1;
        
        while(t<=b && l<=r)
        {
            if(dir==1)
            {
                for(int i=l; i<=r; i++)
                {
                    ans.push_back(matrix[t][i]);
                }
                t++;
                dir=2;
            }
            else if(dir==2)
            {
                for(int i=t; i<=b; i++)
                {
                    ans.push_back(matrix[i][r]);
                }
                r--;
                dir=3;
            }
            else if(dir==3)
            {
                for(int i=r; i>=l; i--)
                {
                    ans.push_back(matrix[b][i]);
                }
                b--;
                dir=4;
            }
            else if(dir==4)
            {
                for(int i=b; i>=t; i--)
                {
                    ans.push_back(matrix[i][l]);
                }
                l++;
                dir=1;
            }
        }
        
        return ans;
    }
};