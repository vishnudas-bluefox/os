#include <stdio.h>
int main()
{
int
i,j,k,n,m,allocation[10][10],max[10][10],available[10];
printf("Enter number of process:");
scanf("%d",&n);
printf("Enter number of resources:");
scanf("%d",&m);
for(i=0;i<n;i++)
{
printf("Enter Rallocation for %d\n",i+1);
for(j=0;j<m;j++)
{
scanf("%d",&allocation[i][j]);
}
}
for(i=0;i<n;i++)
{
printf("Enter MaxClaim for %d\n",i+1);
for(j=0;j<m;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("Enter available resources:\n");
for(i=0;i<m;i++)
{
scanf("%d",&available[i]);
}
int f[n], ans[n], ind = 0;
for (k = 0; k < n; k++) {
f[k] = 0;
}
int need[n][m];
for (i = 0; i < n; i++) {
for (j = 0; j < m; j++)
need[i][j] = max[i][j] - allocation[i][j];
}
int y = 0;
for (k = 0; k < 5; k++) {
for (i = 0; i < n; i++) {
if (f[i] == 0) {
int flag = 0;
for (j = 0; j < m; j++) {
if (need[i][j] > available[j]){
flag = 1;
break;
}
}
if (flag == 0) {
ans[ind++] = i;
for (y = 0; y < m; y++)
available[y] += allocation[i][y];
f[i] = 1;
}
}
}
}
int flag = 1;
for(int i=0;i<n;i++)
{
if(f[i]==0)
{
flag=0;
printf("The following system is not safe");
break;
}
}
if(flag==1)
{
printf("Following is the SAFE Sequence\n");
for (i = 0; i < n-1; i++)
printf(" P%d ->", ans[i]+1);
printf(" P%d", ans[n - 1]+1);
}
return (0);
// This code is contributed by Deep Baldha (CandyZack)
}