#include <bits/stdc++.h>
#include <vector>
#define INF 1e18
using namespace std;

/*In this problem due to large weight we are going to do some changes in the state of dp
 since maximum possible value is 10^5 so in place of finding 
 MAX(ind,weight_left) --> gives maximum possible value at this state
 we are going to find 
 MAX(ind,value_left) --> gives miminum possible weight for the given value , if
 this minimum weight is <= W(capacity) then this value is the possible answer 
 so further all we need is to maximize the possible values.
*/

int wt[105];
int val[105];
long long dp[105][100005];

long long MAX(int i,int val_left){
    if(val_left==0) return 0;
    if(i<0) return INF;
    if(dp[i][val_left]!=-1) return dp[i][val_left];
    long long ans = MAX(i-1,val_left);
    if(val_left>=val[i])
    ans = min(ans,MAX(i-1,val_left-val[i])+wt[i]);
    return dp[i][val_left] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;
    for(int i=0 ; i<n ; i++) cin>>wt[i]>>val[i];
    for(int i=100000 ; i>=0 ; i--){
        if(MAX(n-1,i)<=w){
            cout<<i<<"\n";
            break;
        }
    }
    return 0;
}