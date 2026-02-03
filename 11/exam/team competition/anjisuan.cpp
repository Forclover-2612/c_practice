#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<cstring>
using namespace std;
typedef struct{
    char name[4];
    int w;
}protein;
char input[10][4];
protein p[10]={{"Gly",75},{"Ala",89},{"Ser",105},{"Thr",119},{"Cys",121},{"Asn",132},{"Asp",133},{"Gln",146},{"Glu",147},{"Met",149}};
int ans[10000][5];
int t_weight=0;
int num[10]={0};
int y=0;
void start(int M,int N,int t_weight,int ans[][5],int k){
    if(t_weight+18>N){
        cout<<ans[y][0]<<ans[y][1]<<ans[y][2];
        y++;
        return;
    }
    for(int i=0;i<M;i++){
        t_weight+=num[i];
        t_weight-=18;
        ans[y][k]=i;
        start(M,N,t_weight,ans,k+1);
        t_weight-=num[i];
        t_weight+=18;
    }
}
int main()
{
    int M,N;
    cin>>M>>N;
    int flag[10]={0};
    
    int t=0;
    for(int i=0;i<M;i++){
        cin>>input[i];
        for(int j=0;j<10;j++){
            if(strcmp(input[i],p[j].name)==0){
                flag[j]=1;
                num[t]=p[j].w;
                t++;
                break;
            }
        }
        
        
    }
    int k=0;
    start(M,N,0,ans,k);
    
    

    

    return 0;
}