#include<bits/stdc++.h>
using namespace std;

#define MAXINT 1000000
const int m = 12;
const int n = 7;
int dp[n][1 << n];
int parent[n][1 << n];
int Visited_all = (1 << n) - 1;

vector<vector<int>> readFile(string fname, int m);
int tsp(vector<vector<int>>& dist, int pos , int mask);

int main(){
    string fname = "2_2_christmas_shopping.csv";
    vector<vector<int>>dist;
    vector<vector<int>>current_data;
    int min_cost = MAXINT,s_cost,p_cost,h_cost,d_cost,t_cost,cost,temp;

    current_data = readFile(fname,m);

    for(int i=1; i<m; i++)      //to make the TSP return from home to worl
        current_data[m-1][i] = 100;
  
    dist = current_data;
    
    for(int t=10; t<=10; t++)
    {
        dist.erase(dist.begin()+t);     //delete row t
    for(int d=7; d<=7; d++)
    {
        dist.erase(dist.begin()+d);     //delete row d
    for(int h=5; h<=5; h++)
    {
        dist.erase(dist.begin()+h);     //delete row h
    for(int p=3; p<=3; p++)
    {
        dist.erase(dist.begin()+p);     //delete row p
    for(int s=2; s<=2; s++)
    {
        dist.erase(dist.begin()+s);     //delete row s

        for(int i=0; i< dist.size(); i++)   // delete columns
        {
            dist[i].erase(dist[i].begin() + t);
            dist[i].erase(dist[i].begin() + d);
            dist[i].erase(dist[i].begin() + h);
            dist[i].erase(dist[i].begin() + p);
            dist[i].erase(dist[i].begin() + s);
        }
        
        memset(dp , -1 , sizeof(dp));
        memset(parent , -1 , sizeof(parent));
        Visited_all = (1 << n) - 1;

        cost = tsp(dist,0,1);
	    cout<<"Travelling Saleman Distance is "<<cost<<endl;
        
        if(cost< min_cost)
            min_cost = cost, s_cost =s, p_cost = p, d_cost = d, t_cost = t, h_cost = h;

        vector<int>path(n);
        int path_counter = 0;
        int cur_node = 0;
        int cur_mask = 1;
        do {
            path[path_counter] = cur_node;
            path_counter = path_counter + 1;
            cur_node = parent[cur_node][cur_mask];
            cur_mask = cur_mask | (1 << cur_node);
        } while(path_counter<n);
        
        for(int i=0; i<n; i++)
            cout<<path[i]<<" ";
        cout<<endl;

        for(int i=0; i< dist.size(); i++)   // insert the deleted columns
        {
            if(i == 0)  temp = 0;
            else if(i == 1) temp = s;
            else if(i == 2) temp = p;
            else if(i == 3) temp = h;
            else if(i == 4) temp = d;
            else if(i == 5) temp = t;
            else if(i == 6) temp = 11;
            dist[i].insert(dist[i].begin() + s,current_data[temp][s]);
            dist[i].insert(dist[i].begin() + p,current_data[temp][p]);
            dist[i].insert(dist[i].begin() + h,current_data[temp][h]);
            dist[i].insert(dist[i].begin() + d,current_data[temp][d]);
            dist[i].insert(dist[i].begin() + t,current_data[temp][t]);
        }

        dist.insert(dist.begin()+s,current_data[s]);     //insert the deleted row s
    }
        dist.insert(dist.begin()+p,current_data[p]);     //insert the deleted row p
    }
        dist.insert(dist.begin()+h,current_data[h]);     //insert the deleted row h
    }
        dist.insert(dist.begin()+d,current_data[d]);     //insert the deleted row d
    }
        dist.insert(dist.begin()+t,current_data[t]);     //insert the deleted row t
    }      

    
    cout<<"Min Cost: "<<min_cost<<endl;
    cout<<"Deleted Rows & Columns: "<<s_cost<<" "<<p_cost<<" "<<h_cost<<" "<<d_cost<<" "<<t_cost<<endl;
    /*for(int i=0;i<dist.size();i++)
    {
        for(int j=0; j<dist[i].size(); j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }
    */
}

vector<vector<int>> readFile(string fname, int m) 
{  
    fstream fin; 
    string line, word;
    vector<int> row; 
    vector<vector<int>> out(m);
    int r=0;
    
    for(int i=0; i< m;i++)  out[i] = vector<int>(m);

    fin.open(fname, ios::in);   
    
    while (r< m) { 
        getline(fin, line);

        stringstream s(line); 

        while (getline(s, word, ','))
        { 
            row.push_back(atoi(word.c_str()));
        }  

        for(int i=0; i<row.size();i++)  out[r][i] = row[i];
        
        row.clear();
        r++; 
    }
    
    return out;
} 

int tsp(vector<vector<int>>& dist, int pos , int mask){
    int temp;
    if( mask == Visited_all){
        return dist[pos][0];
    }
    if(dp[pos][mask] !=  -1) return dp[pos][mask];
    int ans = 10e5;

    for(int city = 0 ; city < n ; city++){
        //unvisited city 
        if(city != pos && (mask&(1 << city) ) == 0 ){
            temp = dist[pos][city] + tsp (dist, city, ( mask|(1<<city) ));
            if(temp < ans)
            {
                ans = temp;
                parent[pos][mask] = city;
            }
        }
    }
    return dp[pos][mask] = ans;
}