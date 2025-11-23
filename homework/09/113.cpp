#include<stdio.h>
#define N 20
#define D 1000
int queen[N];
int col[N];
int d1[D];
int d2[D];
int Total;
// int n=8;
void dfs(int i,int n);
int check_safe(int i,int j,int n);
void set_conflict(int i,int j,int n);
void unset_conflict(int i,int j,int n);
void output();
int main()
{
    int n;
    scanf("%d",&n);
    dfs(1,n);
    printf("%d",Total);
    return 0;
}
void dfs(int i,int n)
{
    if(i>n)
    {
        // output();
        Total++; 
        return;
    }
    for(int j=1;j<=n;j++)
    {
        if(check_safe(i,j,n))
        {
            set_conflict(i,j,n);
            dfs(i+1,n);
            unset_conflict(i,j,n);
        }
        // unset_conflict(i,j);//注意不能放在外面
    }
}
int check_safe(int i,int j,int n)
{
    return (!col[j]&&!d1[i-j+n]&&!d2[i+j]);
}
void set_conflict(int i,int j,int n)
{
    col[j]=1;
    d1[i-j+n]=1;
    d2[i+j]=1;
}
void unset_conflict(int i,int j,int n)
{
    col[j]=0;
    d1[i-j+n]=0;
    d2[i+j]=0;
}