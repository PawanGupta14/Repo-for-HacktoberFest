#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

#define rep(i,a,b) for(i=a;i<b;i++)
typedef long long ll;
typedef unsigned long long ull;
#define test(t) int t; cin>>t; while(t--)

int knapsack(int w[],int s,int n) {
    int dp[n+1][s+1];
    int c=0,i,j,k;
    for(i=0;i<=s;i++) dp[0][i]=0;
    for(i=0;i<=n;i++) dp[i][0]=1;
    for(i=1;i<=n;i++) {
        for(j=1;j<=s;j++) {
            if(j<w[i-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]= dp[i-1][j] + dp[i][j-w[i-1]] ;
        }
    }

    // for(i=0;i<=n;i++) {
    //     for(j=0;j<=s;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return dp[n][s];
}

int main()
{
    IOS;
    int i,j,k,n,s;
    cin>>n>>s;
    int w[n],v[n];
    for(i=0;i<n;i++) cin>>w[i];
    // for(i=0;i<n;i++) cin>>v[i];
    k=knapsack(w,s,n); 
    cout<<k;
    return 0;
}