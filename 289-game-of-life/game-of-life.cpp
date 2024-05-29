#include<iostream>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> a=board;
    int n=board.size();
    int m=board[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int c=0;
            for(int x=-1;x<=1;x++)
            {
                for(int y=-1;y<=1;y++)
                {
                    if(i+x>=0 && i+x<n && j+y>=0 && j+y<m && a[i+x][j+y]==1) c++;
                }
            }
            if(a[i][j]==1) c--;
            if(a[i][j]==0 && c==3) board[i][j]=1;
            else if(a[i][j]==1 && c<2) board[i][j]=0;
            else if(a[i][j]==1 && c>3) board[i][j]=0;
        }
    }    
    }
};