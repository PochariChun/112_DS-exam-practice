#include <bits/stdc++.h>
using namespace std;

int main() {
    int time;
    cin>>time;
    while(time--){
        string s;
        cin>>s;
        int len = s.length();
        int arr[len] = {0};
        
        arr[0]++;
        int next = (s[0] - '0') % len;
        int travel = len - 1;
        
        while (travel--){
            arr[next]++;
            next = (next + (s[next] - '0')) % len;
        }
        
        int judge = 1;
        for (auto i: arr)
            if (i != 1)
                judge = 0;
        
        if (judge == 0) printf("No");
        else printf("Yes");
        cout<<endl;
    }
    return 0;
}