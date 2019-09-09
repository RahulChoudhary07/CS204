#include <bits/stdc++.h> 
using namespace std; 


int comparison(string X, string Y) 
{ 
    
    string XY = X.append(Y); 
  
    
    string YX = Y.append(X); 
  
    
    return XY.compare(YX) > 0 ? 1: 0; 
} 
  



int main() 
{ 
    
    long long int  T;
    cin>>T;
    while(T--)
    {
       long long int  n;
       cin>>n;
       string s[n];
       for(long long int  i=0;i<n;i++)
       {
           cin>>s[i];
       }
       sort(s,s+n,comparison);
       for (long long int  i=0; i < n ; i++ ) 
       {
           cout << s[i]; 
       }
       cout<<endl;
    }

   return 0; 
}





