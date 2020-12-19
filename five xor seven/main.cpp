#include <iostream>

using namespace std;

int main()
{
    int counter =0;
    for(char i='0'; i<='9';i+=1)
        for(char j='0'; j<='9';j+=1)
            for(char k='0'; k<='9';k+=1)
                for(char l='0'; l<='9';l+=1)
                    for(char m='0'; m<='9';m+=1)
                    {
                        if(i=='7' || j=='7' || k=='7' || l=='7' || m=='7')
                        {
                            if(i!='5' && j!='5' && k!='5' && l!='5' && m!='5')
                                counter++;
                        }
                        if(i=='5' || j=='5' || k=='5' || l=='5' || m=='5')
                        {
                            if(i!='7' && j!='7' && k!='7' && l!='7' && m!='7')
                                counter++;
                        }
                        if(counter==1000)
                        {
                            cout<<i<<j<<k<<l<<m<<endl;
                            return 0;
                        }
                    }
}