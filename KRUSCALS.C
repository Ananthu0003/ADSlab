#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int i,j,k,a,b,u,v,n,ned=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void main()
{
  clrscr();
  printf("Minimum cost spanning tree\n");
  printf("\nImplimentation of Kurskal's Algm\n");
  printf("Enter the No.of vertices:\n");
  scanf("%d",&n);
  printf("Enter the cost using adjacencey Matrix:\n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
      scanf("%d",&cost[i][j]);
      if(cost[i][j]==0)
      {
	cost[i][j]=999;
      }
  }
    printf("The Edge of minimum cost spanning tree");
    while(ned<n)
    {
      for(i=1,min=999;i<=n;i++)
      {
	for(j=1;j<=n;j++)
	{
	  if(cost[i][j]<min)
	  {
	    min=cost[i][j];
	    a=u=i;
	    b=v=j;
	  }
	}
      }
      u=find(u);
      v=find(v);
      if(uni(u,v))
      {
	printf("Edge %d(%d->%d)=%d\n",ned++,a,b,min);
	mincost+=min;
      }
      cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimum cost=%d\n",mincost);
    getch();

}
  int find(int i)
  {
    while(parent[i])
      i=parent[i];
      return i;
  }
    int uni(int i,int j)
    {
      if(i!=j)
      {
	parent[j]=i;
	return 1;
      }
      return 0;
    }


















