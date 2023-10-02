    #include <bits/stdc++.h>
    using namespace std;
    bool prime(int x){
        if(x<2)return false;
        for(int i = 2;i*i<=x;i++){
            if(x%i==0)return false;
        }
        return true;
    }
    signed main() {
        int n;
        cin >> n;
        if ((n & 1) and n>1) {
            cout <<  1 << endl;

        }
        else {
            for (int i = 2; i <= 1000; i++) {
                int cmd = i*n + 1;
                if (prime(cmd)== false) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
