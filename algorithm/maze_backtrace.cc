#include <cstdio>
using namespace std;


#define WALL   0  //墙
#define CORRIDOR 1 //通道
#define PATH  9 //为路径上的一块
#define TRIED 2 //

#define ROW_NUM    7 //迷宫数组行数
#define COL_NUM   13 //列数

#define TRUE 1
#define FALSE 0
#define MAXSIZE 50
typedef struct 
{
    int row;
    int col;
}PosType;

typedef struct 
{
    int ord;      //通道块在路径上的"序号"
    PosType seat; //通道块在迷宫中的坐标
    int di;       //当前通道块的方向
}SElemType;
typedef struct 
{
    SElemType S[MAXSIZE];
    int top;
}MazeType;
//迷宫
int grid[ROW_NUM][COL_NUM]={{1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
                            {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
                            {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
                            {1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1},
                            {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
//当前位置是否可以通过
bool Valid(PosType pos)
{
    if(pos.row>=0&&pos.row<=ROW_NUM&&pos.col>=0&&pos.col<=COL_NUM&&grid[pos.row][pos.col]==CORRIDOR)
        return TRUE;
    else
        return FALSE;
}
void FootPrint(PosType pos)//留下足迹
{
    grid[pos.row][pos.col]=PATH;
}
void Undo(PosType pos) //留下不能通过的标识
{
    grid[pos.row][pos.col]=TRIED;
}
//当前位置的下一个位置
PosType NextPos(PosType cur,int di)
{
    PosType next;
    switch(di)
    {
    case 0: //东
        next.row=cur.row;
        next.col=cur.col+1;
        break;
    case 1: //南
        next.row=cur.row+1;
        next.col=cur.col;
        break;
    case 2:  //西
        next.row=cur.row;
        next.col=cur.col-1;
        break;
    case 3:  //北
        next.row=cur.row-1;
        next.col=cur.col;
        break;
    }
    return next;
}
//是否到达终点
bool Done(PosType cur,PosType end)
{
    if(cur.row==end.row&&cur.col==end.col)
        return TRUE;
    else
        return FALSE;
}
//寻找迷宫路径
bool MazePath(MazeType &path,PosType start,PosType end)
{
    SElemType e;
    path.top=-1;
    int step=1;
    PosType curpos=start;
    do
    {
        if(Valid(curpos))
        {
            FootPrint(curpos);
            e.ord=step;
            e.di=0;
            e.seat=curpos;
            path.S[++path.top]=e;
            if(Done(curpos,end))
                return TRUE;
            curpos=NextPos(curpos,0);
            step++;
        }
        else
        {
            if(path.top>-1)//棧不空
            {
                e=path.S[path.top--];
                while(e.di==3&&path.top>-1)
                {
                    Undo(e.seat);
                    e=path.S[path.top--];
                }
                if(e.di<3)
                {
                    e.di++;
                    path.S[++path.top]=e;
                    curpos=NextPos(e.seat,e.di);
                }
            }//if
        }//else
    }while(path.top>-1);
    return FALSE;
}
//输出路径
void PrintPath(MazeType path)
{
    int i=0;
    while(i<=path.top)
    {
        printf("第%d步:(%d,%d)\n",path.S[i].ord,path.S[i].seat.row,path.S[i].seat.col);
        i++;
    }
}
//输出路径
void PrintPath2()
{
    for(int i=0;i<ROW_NUM;i++)
        for(int j=0;j<COL_NUM;j++)
        if(grid[i][j]==PATH)
            printf("(%d,%d)\n",i,j);
}
int main()
{
    MazeType path;
    PosType start={0,0},end={6,12};
    if(MazePath(path,start,end))
        PrintPath(path);
    else
        printf("not reachable!\n");

    PrintPath2();
}
