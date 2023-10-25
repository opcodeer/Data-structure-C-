#include <iostream>
using namespace std;
bool palindromecheck(string s){
    int len = s.length();
    int i=0,j=len-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    string s = "aabba";
    cout<<palindromecheck(s)<<endl;
    return 0;
}