class Solution {
public:
void dfs(int x,int y,int n,int m,vector<vector<int>>& visited,vector<vector<char>>&board){
    visited[x][y]=1;
    if(x-1>=0 && board[x-1][y]=='O' && visited[x-1][y]==0){visited[x-1][y]=1; dfs(x - 1, y, n, m, visited, board);}
    if(x+1<n && board[x+1][y]=='O' && visited[x+1][y]==0){visited[x+1][y]=1; dfs(x + 1, y, n, m, visited, board);}
    if(y-1>=0 && board[x][y-1]=='O' && visited[x][y-1]==0){visited[x][y-1]=1; dfs(x , y-1, n, m, visited, board);}
    if(y+1<m && board[x][y+1]=='O' && visited[x][y+1]==0){visited[x][y+1]=1; dfs(x , y+1, n, m, visited, board);}
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O') dfs(0,j,n,m,visited,board);
            if(board[n-1][j]=='O') dfs(n-1,j,n,m,visited,board);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O') dfs(i,0,n,m,visited,board);
            if(board[i][m-1]=='O') dfs(i,m-1,n,m,visited,board);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && visited[i][j]==0) board[i][j]='X';
            }
        }
    }
};