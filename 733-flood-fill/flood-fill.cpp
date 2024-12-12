class Solution {
public:
void dfs(vector<vector<int>>& image,vector<vector<int>> visited,int i,int j,int value,int color){
    image[i][j]=color;
    visited[i][j]=1;
    if(i-1>=0 && image[i-1][j]==value && visited[i-1][j]==0) dfs(image,visited,i-1,j,value,color);
    if(i+1<image.size() && image[i+1][j]==value && visited[i+1][j]==0) dfs(image,visited,i+1,j,value,color);
    if(j-1>=0 && image[i][j-1]==value && visited[i][j-1]==0) dfs(image,visited,i,j-1,value,color);
    if(j+1<image[0].size() && image[i][j+1]==value && visited[i][j+1]==0) dfs(image,visited,i,j+1,value,color);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int n=image.size();
      int m=image[0].size();
      vector<vector<int>> visited(n,vector<int>(m,0));
      int value=image[sr][sc];
      dfs(image,visited,sr,sc,value,color);
      return image;
    }
};