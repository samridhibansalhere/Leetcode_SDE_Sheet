class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();
      int count=0;
      vector<vector<int>> height(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            height[i][j]=(mat[i][j]==0?0:(i==0?1:1+height[i-1][j]));
        }
      }  
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
           int  minh=height[i][j];
            for(int k=j;k>=0 && minh>0;k--){
                minh=min(minh,height[i][k]);
                count+=minh;
            }
        }
      }
      return count;
    }
};