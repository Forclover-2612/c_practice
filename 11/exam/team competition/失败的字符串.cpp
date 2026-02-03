#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char input[10000][50];
// char t[10000][50];
int isfind(char str[],char c[]){
    int len1=strlen(str);
    int len2=strlen(c);
    if(len1<len2){
        return 0;
    }
    for(int i=0;i<len2;i++){
        if(str[i]!=c[i]){
            return 0;
        }
    }
    return 1;

}
int main(){
    // freopen("error.in","r",stdin);
    // freopen("111","w",stdout);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>input[i];
    }
    char c[50];
    cin>>c;
    int y=0;
    char *p[10000];

    for(int i=0;i<N;i++){
        if(isfind(input[i],c)==0){            
            // strcpy(t[y],input[i]);
            p[y]=input[y];//直接指过去
            y++;
        }
    }
    
    for(int i=0;i<y;i++){
        for(int j=i+1;j<y;j++){
            if(strcmp(p[i],p[j])>0){
                char *mid=p[i];
                p[i]=p[j];
                p[j]=mid;
            }
        }
    }
    for(int i=0;i<y;i++){
        cout<<p[i]<<'\n';
    }
    return 0;
}