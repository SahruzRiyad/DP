#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll last[30];

ll CountSub(string a){
    memset(last,-1,sizeof(last));
    ll i , j , len;
    len = a.size();
    ll dp[len + 3];
    dp[0] = 1;
    for(i=1;i<=len;i++){
        dp[i] = 2 * dp[i-1];//for disting character 2^n
        if(last[a[i-1] - 65] != -1)//check repetation
            dp[i] -= dp[last[a[i-1] - 65]];//subtract with the prevously overlapped character ind
        last[a[i-1] - 65] = i - 1;//remembering the previous index for the character to proceed line 16
    }
    return dp[len];
}

int main(){
    string a;
    cin>>a;
    cout<<CountSub(a)<<endl;
    return 0;
}
