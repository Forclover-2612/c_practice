


#include<stdio.h>










int main(){




int n=6;//测试n=6




scanf("%d",&n);









char hunters[]={'A','B','C','D','E','F','G','H'};









for(int i=0;i<8;i++){



char hunter=hunters[i];




int count=0;









int A_truth=(hunter=='H'||hunter=='F');




int B_truth=(hunter=='B');




int C_truth=(hunter=='G');




int D_truth=(hunter!='B');




int E_truth=!A_truth;




int F_truth=(hunter!='F'&&hunter!='H');




int G_truth=(hunter!='C');




int H_truth=A_truth;









if(A_truth)count++;




if(B_truth)count++;




if(C_truth)count++;




if(D_truth)count++;




if(E_truth)count++;




if(F_truth)count++;




if(G_truth)count++;




if(H_truth)count++;









printf("hunter=%c:",hunter);




printf("A=%d,B=%d,C=%d,D=%d,E=%d,F=%d,G=%d,H=%d,total=%d\n",




A_truth,B_truth,C_truth,D_truth,E_truth,F_truth,G_truth,H_truth,count);









if(count==n){




printf(">>>MATCH!hunter=%cforn=%d\n",hunter,n);




}




}









return 0;




}


