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
    bool dp[n+1][s+1];
    int c=0,i,j,k;
    for(i=0;i<=s;i++) dp[0][i]=false;
    for(i=0;i<=n;i++) dp[i][0]=true;
    for(i=1;i<=n;i++) {
        for(j=1;j<=s;j++) {
            if(j<w[i-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]= dp[i-1][j] || dp[i-1][j-w[i-1]] ;
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
    int w[n];
    for(i=0;i<n;i++) cin>>w[i];
    // for(i=0;i<n;i++) cin>>v[i];
    if(knapsack(w,s,n)) cout<<"Sum present\n";
    else cout<<"Sum not present\n";
    return 0;
}