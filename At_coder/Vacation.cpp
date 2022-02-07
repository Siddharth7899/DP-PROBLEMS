#include <bits/stdc++.h>
#include <vector>
#define ll long long int
using namespace std;
/***************************************************************************************************/
const int N = 1e5+5;
int a[N][3];
ll dp[N][3];
ll MAX(int i,int j){
  if(i<0) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  ll cost = 0;
  if(j==0){
    cost = max(cost,MAX(i-1,1)+a[i][0]);
    cost = max(cost,MAX(i-1,2)+a[i][0]);
  }
  if(j==1){
    cost = max(cost,MAX(i-1,0)+a[i][1]);
    cost = max(cost,MAX(i-1,2)+a[i][1]);
  }
  if(j==2){
    cost = max(cost,MAX(i-1,0)+a[i][2]);
    cost = max(cost,MAX(i-1,1)+a[i][2]);
  }
  return dp[i][j] = cost;
}

void solve()
{
  memset(dp,-1,sizeof(dp));
  int n;cin>>n;
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<3 ; j++){
      cin>>a[i][j];
    }
  }
  ll ans = 0;
  for(int j=0 ; j<3 ; j++){
    ans = max(ans,MAX(n-1,j));
  }
  cout<<ans<<"\n";
}
/***************************************************************************************************/
int main()
{
  solve();
  return 0;
}