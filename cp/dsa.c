// C program to read string from user
#include <stdio.h>

int main() {

    int n;
    scanf("%d",&n);
    int ans = 0 ; 
    while(n!=0){
        int cur = n%10;
        if(ans<cur)ans = cur ; 
        n= n/10;
    }
    printf("%d",ans);

    return 0;
}
