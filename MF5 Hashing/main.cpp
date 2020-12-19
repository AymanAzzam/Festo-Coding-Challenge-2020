#include "md5.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string hashed = "19acf8371f", out,cmp;

    for (char i = '0'; i <= 'z'; i+=1)
    {
        //if((i>'9' && i<'A') || (i>"Z" && i<"a"))    continue;
        for (char j = '0'; j <= 'z'; j+=1)
        {
            //if((j>"9" && j<"A") || (j>"Z" && j<"a"))    continue;
            for (char k = '0'; k <= 'z'; k+=1)
            {   
                //if((k>"9" && k<"A") || (k>"Z" && k<"a"))    continue;
                out = string(1,i)+string(1,j)+string(1,k);
                cmp = md5(out);
                
                if(hashed == cmp.substr(0,10))
                {
                    cout<<i<<endl<<j<<endl<<k<<endl<<endl;
                    cout<<cmp<<endl<<endl;
                    cout<<out<<endl;
                }
            }
        }
        
    }
}