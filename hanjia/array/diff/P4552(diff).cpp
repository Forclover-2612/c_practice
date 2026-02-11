#include<stdio.h>
#include<math.h>
#include <algorithm>
//所有数都一样-->等于差分数组元素都为0(D[2]~D[n])
//原数组 A 的区间 [L,R] 进行加 1 操作
//D[L]←D[L]+1，D[R+1]←D[R+1]−1
//差分数列中存在正数和负数
//金操作（效率最高）：选一个 D 中的正数和负数，一个+1，一个-1（操作区间[i,j-1])
//银操作（从两头借位）：选个非0数，另一个位置选D[1]或D[n+1],只能让D[i]向0靠拢，另外一个变化浪费在边缘
//(D[1]改变高度，D[n+1]废弃)（操作区间[1,i-1]或[i,n])
//假设D[2]~D[n]中，所有正数之和为P，所有负数绝对值之和为Q
//尽量使用黄金操作，正负抵消   最多进行min(P,Q)次黄金操作
//剩下的|P-Q|个如果不为0，只能使用白银操作一个一个消除
//最终最少操作次数=min(P,Q)+|P-Q|=max(P,Q)
long long a[100005];
long long diff[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }

    long long pos=0;
    long long neg=0;

    for(int i=2;i<=n;i++)
    {
        long long val=a[i]-a[i-1];
        if(val>0)
        pos+=val;
        else
        neg+=-val;
    }

    printf("%lld\n",std::max(pos,neg));
    //最终数字取决于D[1](可以修改到0~|P-Q|)
    printf("%lld",abs(pos-neg)+1);
    return 0;
}