#include <bits/stdc++.h>
#define ll long long
using namespace std;

int LCS(int lena , int lenb , string a , string b){
    int i , j , L[lena+3][lenb +3];
    for(i=0;i<=lena;i++){
        for(j=0;j<=lenb;j++){
            if(i == 0 || j == 0)
                L[i][j] = 0;
            else if(a[i-1] == b[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[lena][lenb];
}
int main(){
   // freopen("riyad.txt","r",stdin);
    int lena , lenb , i , j;
    string a , b;
    cin>>a>>b;
    lena = a.size();
    lenb = b.size();
    cout<<LCS(lena,lenb,a,b)<<endl;
    return 0;
}
