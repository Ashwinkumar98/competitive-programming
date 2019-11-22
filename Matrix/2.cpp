#include<iostream>
#include<stdlib.h>
#include<queue>
#include<string.h>
#define ROW 9
#define COL 10

using namespace std;

struct Point {
    int x;
    int y;
};

struct Queuenode {
    Point p;
    int dist;
};

bool valid(int r,int c,int mat[ROW][COL],bool visited[ROW][COL])
{
    return(r>=0 && c>=0 && r<ROW && c<COL && (mat[r][c]==1 && !visited[r][c]));
}

int FindPath(Point src,Point dest,int mat[ROW][COL])
{
    int i,j;
    bool visited[ROW][COL];
    memset(visited,false,sizeof(visited));
    queue<Queuenode> q;

    if(mat[src.x][src.y]==0 || mat[dest.x][dest.y]==0){
        return -1;
    }
    Queuenode node = {src,0};
    q.push(node);

    int rowK[]={-1,0,1,0};
    int colK[]={0,1,0,-1};

    while(!q.empty()){
        Queuenode curr = q.front();
        Point pt = curr.p;
        q.pop();

        if(pt.x==dest.x && pt.y==dest.y){
            return curr.dist;
        }

        for(i=0;i<4;i++){

            int row = rowK[i]+pt.x;
            int col = colK[i]+pt.y;

            if(valid(row,col,mat,visited)){
                visited[row][col]=true;
                Queuenode adjNode = {{row,col},curr.dist+1};
                q.push(adjNode);
            }

        }
    }

    return -1;
}

int main()
{
     int mat[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };

    Point src = {4, 0};
    Point dest = {8, 9};
    int dist = FindPath(src,dest,mat);

    if(dist==-1){
        cout<<"NO SUCH PATH AVAILABLE";
    }else{
        cout<<"SHORTEST DISTANCE IS "<<dist;
    }
    return 0;
}
