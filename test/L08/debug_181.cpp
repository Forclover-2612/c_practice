// 181, wrong answer's input: 26 28 2109
#include <iostream>  
using namespace std;

int main()  
{  
    //freopen("data.in","r",stdin);
    //在同一个目录下
    //freopen("data.out","w",stdout);
    int a,b,n,i,f0,f1,f2;  
    cin >> a >> b >> n;
    f0=1;f1=1;i=1;  
    do
    {  
	    f2=(a*f0+b*f1)%7;  
	    f0=f1;  
	    f1=f2;  
	    i++;  
    } while(i<n-1);
	    
    cout << f2 << endl;
    return 0;  
 }  
