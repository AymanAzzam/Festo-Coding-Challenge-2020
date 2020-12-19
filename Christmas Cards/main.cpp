#include<bits/stdc++.h>
using namespace std;

const int n = 10;
int dp[n][1 << n];
int parent[n][1 << n];

int dist[10][10] = {
    {0,6,10,4,1,9,2,9,7,0},
    {0,0,8,7,4,3,5,5,12,5},
    {0,11,0,16,12,11,10,5,20,15},
    {0,7,13,0,3,10,5,11,4,5},

    {0,4,10,3,0,8,2,8,7,5},
    {0,3,8,11,8,0,8,4,15,7},
    {0,5,8,6,2,8,0,7,10,7},
    {0,6,4,13,10,6,8,0,17,11},
    {0,10,16,3,6,14,8,15,0,8},
    {0,1000,1000,1000,1000,1000,1000,1000,1000,1000}
};

int Visited_all = (1 << n) - 1;
int tsp ( int pos , int mask){
    int temp;
    if( mask == Visited_all){
        return dist[pos][0];
    }
    if(dp[pos][mask] !=  -1) return dp[pos][mask];
    int ans = 10e5;

    for(int city = 0 ; city < n ; city++){
        //unvisited city 
        if(city != pos && (mask&(1 << city) ) == 0 ){
            temp = dist[pos][city] + tsp (city, ( mask|(1<<city) ));
            if(temp < ans)
            {
                ans = temp;
                parent[pos][mask] = city;
            }
        }
    }
    return dp[pos][mask] = ans;
}
int main(){
    memset(dp , -1 , sizeof(dp));
	cout<<"Travelling Saleman Distance is "<<tsp(0,1)<<endl;
    
    vector<int>path(n);
    int path_counter = 0,maxi = 0;
    int cur_node = 0;
    int cur_mask = 1;
    do {
        maxi++;
        path[path_counter] = cur_node;
        path_counter = path_counter + 1;
        cur_node = parent[cur_node][cur_mask];
        cur_mask = cur_mask | (1 << cur_node);
    } while(maxi<n);
    
    for(int i=1; i<n-1; i++)
        cout<<path[i]<<" ";
    cout<<endl;
}