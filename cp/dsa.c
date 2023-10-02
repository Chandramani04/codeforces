// C program to read string from user
#include <stdio.h>

int main() {
    // declaring string
    char str[100];

    // reading string
    scanf("%s", str);

    // print string
    // printf("%s", str);
    int ans[10]={0};
    for(int i = 0;i<50;i++){
        if(str[i]==' ')break;
        int cur = str[i]-'0';
        if(cur>=0 && cur<10){
            ans[cur]++;
        }
    }
    for(int i = 0;i<10;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}
