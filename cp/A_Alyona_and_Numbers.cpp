#include <bits/stdc++.h>
using namespace std;
void max(int a,int b){
    
}
signed main()
{
   int ans = 1 ; 
   int n;cin>>n;
   int ans = 0 ;
   while(n!=0){
    int temp = n%10;
    ans = max(ans,temp);
    n/=10;

   }
   cout<<ans<<endl;
}
