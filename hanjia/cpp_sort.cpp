#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Student {
    int score;
    int age;
};
bool cmpStudent(Student a,Student b)
{
    if(a.score!=b.score)
    return a.score>b.score;//成绩高的在前面
    return a.age<b.age;
}
int main()
{
    vector<int> v={5,2,8,1};
    //默认是从小到大
    //从大到小
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    // sort(v.begin(),v.end(),cmpStudent);
    return 0;
}