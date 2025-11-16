#include <iostream>
using namespace std;

int main()
{
    char a[201] = {}, b, c[100] = {}, d[100] = {};
    int e, f = 0, g, h = 0; // e为字符串长度
    cin.getline(a, 201);
    cin >> b >> c;
    for (e = 0; c[e] != '\0'; e++)
        ;
    if (b == 'C')
    {
        g = 0;
        for (int i = 0; a[i] != '\0'; i++)

        {

            if (a[i] == c[f])
                f++;
            else
            {
                f = 0;
                if (a[i] == c[f])
                    f++;
            }
            if (f == e)
            {
                g++;
                f = 0;
            }
        }
        cout << g << endl;
    }
    if (b == 'D')
        g = -10;
    for (int i = 0; a[i] != '\0'; i++)
        if (a[i] == c[f])
            f++;
        else
        {
            f = 0;
            if (a[i] == c[f])
                f++;
        }
    if (f == e)
    {
        g = i - e;
        break;
    }
}

if (g == -10)
{
    cout << a << endl;
    return 0;
}
for (int i = 0; i <= g; i++)
    cout << a[i];
for (int i = g + e + 1; a[i] != '\0'; i++)
    cout << a[i];
cout << endl;
if(b == 'lʼ)
cin>>d;
g =- 10;
for(int i=0;a[i] != '\0';i++)
if(a[i] == c[f]) f++;
else {
    f = 0;
    if (a[i] == c[f])
        f++;}
if(f == e) g=i-e;
}

if (g == -10)
{
    cout << a << endl;
    return 0;
}
for (int i = 0; i <= g; i++)
    cout << a[i];
cout << d;
for (int i = g + 1; a[i] != '\0'; i++)
    cout << a[i];
cout << endl;
}
if (b == 'R')
{
    cin >> d;
    g = -10;
    for (int i = 0; a[i] != '\0'; i++)
        if (a[i] == c[f])
            f++;
        else
        {
            f = 0;
            if (a[i] == c[f])
                f++;
        }
    if (f == e)
        g = i - e;
    for (int j = h; j <= g; j++)
        cout << a[j];
    cout << d;
    f = 0;
    h = i + 1;
}

if (g == -10)
{
    cout << a << endl;
    return 0;
}
for (int i = g + e + 1; a[i] != '\0'; ++)
    cout << a[i];
cout << endl;
}
return 0;
}