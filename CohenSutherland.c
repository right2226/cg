#include <stdlib.h>
#include <stdio.h>
#include<conio.h>
#include<graphics.h>
int xwmax=300,xwmin=200,ywmax=100,ywmin=200,ax,ay,bx,by;
void input()
{
    printf("Enter points in a & b:\n");
    scanf("%d%d%d%d",&ax,&ay,&bx,&by);
}
void draw()
{
    rectangle(xwmin,ywmin,xwmax,ywmax);
}
void clip(int x,int y,int p[4])
{
    if(y<ywmax)
        p[0]=1;
    if(y>ywmin)
        p[1]=1;
    if(x>xwmax)
        p[2]=1;
    if(x<xwmin)
        p[3]=1;
    else
        p[3]=0;
}
void main()
{
    int gd=DETECT,gm,y,x,c,p1[4],p2[4],p3[4],i;
    float m;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    cleardevice();
    input();
    cleardevice();
    clip(ax,ay,p1);
    clip(bx,by,p2);
    for(i=0;i<4;i++)
        p3[3]=p1[i]&&p2[i];
    for(i=0;i<4;i++)
        if(p3[i]==1)
            break;
    draw();
    line(ax,ay,bx,by);
    getch();
    cleardevice();
    if(i!=4)
        draw();
    else
    {
        m=(float)(by-ay)/(bx-ax);
        if(p1[0]==1)
            y=ywmax;
        if(p1[1]==1)
            y=ywmin;
        if(p1[0]==1||p1[1]==1)
        {
            ax=ax+(y-ay)/m;
            ay=y;
        }
        if(p2[0]==1)
            y=ywmax;
        if(p2[1]==1)
            y=ywmin;
        if(p2[0]==1||p2[1]==1)
        {
            bx=bx+(y-by)/m;
            by=y;
        }
        if(p1[2]==1)
            x=xwmax;
        if(p1[3]==1)
            x=xwmin;
        if(p1[2]==1||p1[3]==1)
        {
            ay=ay+m*(x-ax);
            ax=x;
        }
        if(p2[2]==1)
            x=xwmax;
        if(p2[3]==1)
            x=xwmin;
        if(p2[2]==1||p2[3]==1)
        {
            by=by+m*(x-bx);
            bx=x;
        }
        draw();
        line(ax,ay,bx,by);
    }
    getch();
    closegraph();
    restorecrtmode();
}