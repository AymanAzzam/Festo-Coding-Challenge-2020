#include "md5.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string hashed = "002a8a8b23d03e70", out,cmp;

    for (char i = '0'; i <= 'Z'; i+=1)
        for (char j = 'f'; j <= 'f'; j+=1)
            for (char k = 'i'; k <= 'i'; k+=1)
            for (char l = 'd'; l <= 'd'; l+=1)
            for (char m = '0'; m <= 'Z'; m+=1)
            for (char n = '0'; n <= 'Z'; n+=1)
            for (char o = '0'; o <= 'Z'; o+=1)
            for (char p = '0'; p <= 'Z'; p+=1)
            {   
                //if((k>"9" && k<"A") || (k>"Z" && k<"a"))    continue;
                out = string(1,i)+string(1,j)+string(1,k);
                out += string(1,l)+string(1,m)+string(1,n);
                out += string(1,o)+string(1,p);
                cmp = md5(out);
                
                if(hashed == cmp.substr(0,hashed.size()))
                    cout<<out<<endl;
            }
}