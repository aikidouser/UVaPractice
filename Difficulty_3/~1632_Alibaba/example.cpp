#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mi(a,b) (a) >= (b) ? (b) : (a)
using namespace std;
const int N = 1e4 + 5;
const int inf = 0x3f3f3f3f;
int dp[N][N][2];

struct node
{
    int p,d;
    node(){};
    node(int x,int y):p(x),d(y){};
}a[N];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
    int n;
    while (scanf("%d",&n) == 1)
    {
        memset(dp,inf,sizeof(dp));
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&a[i].p,&a[i].d);
        }
        int k = 1;
        for (int i = 1;i <= n;i++)
        {
            if (a[i].d < a[k].d)
            {
                k = i;
            }
        }
        dp[k][k][0] = dp[k][k][1] = 0;
        for (int i = k;i >= 1;i--)
        {
            for (int j = k;j <= n;j++)
            {
                if (i == j) continue;
                int &x = dp[i][j][0];
                int &y = dp[i][j][1];
                x = mi(x,a[i+1].p - a[i].p + dp[i+1][j][0]);
                x = mi(x,a[j].p - a[i].p + dp[i+1][j][1]);
                y = mi(a[j].p - a[j-1].p + dp[i][j-1][1],y);
                y = mi(y,a[j].p - a[i].p + dp[i][j-1][0]);
                if (x >= a[i].d) x = inf;
                if (y >= a[j].d) y = inf;
				
				printf("dp[%d][%d][0] = %d\n", i, j, x);
				printf("dp[%d][%d][1] = %d\n", i, j, y);
            }
        }
        int ans = min(dp[1][n][1],dp[1][n][0]);
        if (ans == inf) printf("No solution\n");
        else printf("%d\n",ans);
    }
	fclose(stdout);
	fclose(stdin);
    return 0;
}