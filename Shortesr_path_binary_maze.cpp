#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>>mat, vector<vector<bool>>&visited, int i, int j)
{
    if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || visited[i][j] == true || mat[i][j] == 0 ) return false;
    return true;
}

void findShortestPath(vector<vector<int>>mat,vector<vector<bool>>&visited, int i, int j, int x, int y, int &min_dist, int dist)
{
    if(i==x && j == y)
    {
        min_dist = min(min_dist,dist);
        return;
    }

    visited[i][j] = true;

    if(isValid(mat,visited,i+1,j)) findShortestPath(mat,visited,i+1,j,x,y,min_dist,dist+1);

    if(isValid(mat,visited,i,j+1)) findShortestPath(mat,visited,i,j+1,x,y,min_dist,dist+1);

    if(isValid(mat,visited,i-1,j)) findShortestPath(mat,visited,i-1,j,x,y,min_dist,dist+1);

    if(isValid(mat,visited,i,j-1)) findShortestPath(mat,visited,i,j-1,x,y,min_dist,dist+1);

    visited[i][j] = false;

}

int findShortestPathLength(vector<vector<int>>mat, pair<int,int>src, pair<int,int>dest)
{
    int dist = INT_MAX;
    int i = src.first;
    int j = src.second;

    int x = dest.first;
    int y = dest.second;

    vector<vector<bool>>visited;
    int row = mat.size();
    int col = mat[0].size();

    visited.resize(row,vector<bool>(col));

    findShortestPath(mat,visited,i,j,x,y,dist,0);

    if(dist!=INT_MAX) return dist;

    return -1;
}

int main()
{
    vector<vector<int>> mat =     {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                   {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                                   {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                   {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                   {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                   {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                   {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                   {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};

    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(3, 4);
    int dist = findShortestPathLength(mat, src, dest);
    if (dist != -1)
        cout << "Shortest Path is " << dist;

    else
        cout << "Shortest Path doesn't exist";
}
