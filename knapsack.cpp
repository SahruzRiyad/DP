#include <bits/stdc++.h>
using namespace std;

struct Knap{
    int wt;
    int val;
}G[1005];

bool cmp(Knap &a , Knap &b){
    if(a.wt == b.wt)
        return a.val < b.val;
    return a.wt < b.wt;
}

void Knapsack(int n , int w){
    int i , j;
    int k[n+3][w+3];
    for(i=0;i<=n;i++){
        for(j=0;j<=w;j++){
            if(i == 0 || j == 0)
                k[i][j] = 0;
            else if(G[i-1].wt <= j)
                k[i][j] = max(G[i-1].val + k[i-1][j-G[i-1].wt],k[i-1][j]);//val+previous state ind - weight , previous state
            else
                k[i][j] = k[i-1][j];//copy the previous state value
        }
    }
    cout<<k[n][w]<<endl;
}

int main(){
    int i , j , n , w , v;
    cin>>n;
    for(i=0;i<n;i++)
        scanf("%d",&G[i].val);
    for(i=0;i<n;i++)
        scanf("%d",&G[i].wt);
    sort(G,G+n,cmp);//sorting val/weight in ascending order
    cin>>w;
    Knapsack(n,w);
}
