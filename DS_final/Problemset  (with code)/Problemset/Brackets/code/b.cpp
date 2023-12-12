#include <bits/stdc++.h>
using namespace std;

int main() {
    int time;
    cin>>time;
    while(time--){
        string s;
        cin>>s;
        int len = s.length();
        
        stack<char> st;
        
        for (int i = 0; i < len; i++){
        	if (s[i] == '('){
        		st.push(s[i]);
        	}
        	if (s[i] == '['){
        		st.push(s[i]);
        	}
        	if (s[i] == ')'){
        		if ((!st.empty()) and st.top() == '(') st.pop();
        		else st.push(s[i]);
        	}
        	if (s[i] == ']'){
        		if ((!st.empty()) and st.top() == '[') st.pop();
        		else st.push(s[i]);
        	}
        }
        
        if (st.empty()) printf("VALID\n");
        else printf("NOT VALID\n");
    }
    return 0;
}