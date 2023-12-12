#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int time;
    cin>>time;
    while(time--){
        string s;
        cin>>s;
        int len = s.length();
        int odd = 0;
        int even = 0;
        int cur = 0;
        for (int i = 0; i < len; i++){
            if (s[i] == '.') cur = cur;
            else if(cur % 2 == 1){
                odd += s[i]-'0';
                cur++;
            }
            else if(cur % 2 == 0){
                even += s[i]-'0';
                cur++;
            }
        }
        //cout<<odd<<" "<<even<<endl;
        if (odd == even or (odd-even) % 11 == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}