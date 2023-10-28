#include <iostream>
#include<stack>
#include<math.h>
using namespace std;
int postfixeval(string s){
      stack<int>st;
      for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op2+op1);
                break;
            case '-':
                st.push(op2-op1);
                break;
            case '*':
                st.push(op2*op1);
                break;
            case '/':
                st.push(op2/op1);
                break;
            case '^':
                st.push(pow(op2,op1));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string s = "46+2/5*7+";
    int ans = postfixeval(s);
    cout<<"The evaluated value of postfix expression is "<<ans<<endl;
    return 0;
}