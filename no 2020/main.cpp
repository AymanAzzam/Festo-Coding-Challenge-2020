#include <iostream>

using namespace std;

int main()
{
    string out,s = "2020";
    int s_index,out_index;
    int counter =-1;
    for(char i='0'; i<='9';i+=1)
        for(char j='0'; j<='9';j+=1)
            for(char k='0'; k<='9';k+=1)
                for(char l='0'; l<='9';l+=1)
                    for(char m='0'; m<='9';m+=1)
                    for(char n='0'; n<='9';n+=1)
                    for(char o='0'; o<='9';o+=1)
                    {
                        out = string(1,i) + string(1,j) + string(1,k) + string(1,l);
                        out += string(1,m) + string(1,n) + string(1,o);
                        s_index = out_index = 0;
                        while(s_index<s.size() && out_index<out.size())
                        {
                            if(out[out_index]==s[s_index])  s_index++;
                            
                            out_index++;
                        }
                        
                        if(s_index !=s.size())  counter++;

                        if(counter==1000000)
                        {
                            cout<<i<<j<<k<<l<<m<<n<<o<<endl;
                            return 0;
                        }
                    }
}