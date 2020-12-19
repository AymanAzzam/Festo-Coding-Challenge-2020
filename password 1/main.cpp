#include "md5.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string hashed = "351635d71448baca", out,cmp;

    for (char i = '0'; i <= '9'; i+=1)
        for (char j = '0'; j <= '9'; j+=1)
            for (char k = '0'; k <= '9'; k+=1)
            for (char l = '0'; l <= '9'; l+=1)
            for (char m = '0'; m <= '9'; m+=1)
            for (char n = '0'; n <= '9'; n+=1)
            for (char o = '3'; o <= '3'; o+=1)
            for (char p = '0'; p <= '0'; p+=1)
            for (char q = '0'; q <= '0'; q+=1)
            {   
                //if((k>"9" && k<"A") || (k>"Z" && k<"a"))    continue;
                out = string(1,i)+string(1,j)+string(1,k);
                out += string(1,l)+string(1,m)+string(1,n);
                out += string(1,o)+string(1,p)+string(1,q);
                out += "631";
                cmp = md5(out);
                
                if(hashed == cmp.substr(0,hashed.size()))
                    cout<<out<<endl;
            }
}