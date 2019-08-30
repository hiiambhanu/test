#include<bits/stdc++.h>
using namespace std;
int main(){
    char m[100], sub[100];
    cout<<"Enter main and sub";
    cin>>m>>sub;
    char temp[100];
    int j;
    int count = 0;
    for(int i = 0; i < strlen(m);i++){
        
        if(m[i]==sub[0])
        for( j = i ; j < strlen(sub) ;j ++ ){

            if(m[i]!=sub[j-i])                                      //bhanu
                                                                    //an
                break;
        }

        if(j-i==strlen(sub))
            count++;
    }

    cout<<count;
    return 0;
}