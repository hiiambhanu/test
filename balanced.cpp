#include<bits/stdc++.h>
using namespace std;
int main(){

    char a[100];
    cin>>a;
    stack<char> s;
    for(int i = 0 ; a[i]!='\0' ; i++){
        if(a[i]=='(')
            s.push(a[i]);
        else if(a[i]==')')
            {
                if(s.empty()){
                    cout<<"No";
                    return 1;
                }

                else 
                    s.pop();
            }
    }
    
    if(!s.empty()) 
        cout<<"Ni";
    else 
        cout<<"yes";

    return 0;
}