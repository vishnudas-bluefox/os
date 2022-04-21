#include <stdio.h>
#include <stdlib.h>
void printdata(int *processSize,int *allocation,int
n);
void main()
{
int
m,n,i,j,bestIdx,wstIdx,*blockSize,*tempblockSize,*processSize,*allocation;
printf("Enter number of block:");
scanf("%d",&m);
printf("Enter number of process:");
scanf("%d",&n);
blockSize=(int*)malloc(n * sizeof(int));
tempblockSize=(int*)malloc(n * sizeof(int));
processSize=(int*)malloc(m * sizeof(int));
allocation=(int*)malloc(n * sizeof(int));
printf("Enter each block size:\n");
for (i=0; i<m;i++)
{
scanf("%d", &blockSize[i]);
tempblockSize[i]=blockSize[i];
}
printf("Enter each process size:\n");
for (i=0; i<n;i++)
scanf("%d", &processSize[i]);
//first fit
for (i = 0; i < n; i++)
allocation[i] = -1;
for (i = 0; i < n; i++)
{
for ( j = 0; j < m; j++)
{
if (blockSize[j] >= processSize[i])
{
allocation[i] = j;
blockSize[j] -= processSize[i];
break;
}
}
}
printdata(processSize,allocation,n);
//best fit
for (i=0; i<m;i++)
blockSize[i]=tempblockSize[i];
for (i = 0; i < n; i++)
allocation[i] = -1;
for (int i=0; i<n; i++)
{
int bestIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >= processSize[i])
{
if (bestIdx == -1)
bestIdx = j;
else if (blockSize[bestIdx] > blockSize[j])
bestIdx = j;
}
}
if (bestIdx != -1)
{
allocation[i] = bestIdx;
blockSize[bestIdx] -= processSize[i];
}
}
printdata(processSize,allocation,n);
//worst fit
for (i=0; i<m;i++)
blockSize[i]=tempblockSize[i];
for (i = 0; i < n; i++)
allocation[i] = -1;
for (int i=0; i<n; i++)
{
int wstIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >= processSize[i])
{
if (wstIdx == -1)
wstIdx = j;
else if (blockSize[wstIdx] <
blockSize[j])
wstIdx = j;
}
}
if (wstIdx != -1)
{
allocation[i] = wstIdx;
blockSize[wstIdx] -= processSize[i];
}
}
printdata(processSize,allocation,n);
}
void printdata(int *processSize,int *allocation,int
n)
{
printf( "\nProcess No.\tProcess Size\tBlockno.\n");
for (int i = 0; i < n; i++)
{
printf(" %d\t\t %d\t\t",i+1,processSize[i]);
if (allocation[i] != -1)
printf("%d\n", allocation[i] + 1);
else
printf("Not Allocated\n");
}
}