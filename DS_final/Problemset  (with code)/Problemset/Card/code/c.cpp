#include<bits/stdc++.h> 
using namespace std;
	
int main() {
    int N;
    cin>>N;
    int M;
    cin>>M;
    while(M>0){
    	int idx=1;
    	int a[105];
	    for(int i=1;i<=N;i++){
	    	cin>>a[i];
	    }
	    stack<int> st;
	    for(int i=1;i<=N;i++){
	    	st.push(i);
	    	while( !st.empty() &&st.top()==a[idx]){
	    		idx++;
	    		st.pop();
	    	}
	    }
	    if(idx==N+1) cout<<"Yes\n";
	    else cout<<"No\n";
	    M--;
    }
}