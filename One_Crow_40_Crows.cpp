#include <bits/stdc++.h>
using namespace std;
struct data{
    short u, v, cost;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    short n, m, k;
    cin>>n>>m>>k;

    queue<data> myData;
    vector<short> cost (n+1, 0);
    vector<short> lens(n+1,0);
    vector<short> visNode;
    short u, v, myCost;

    for(int i = 0; i<m; i++){
        data d;
        cin>>d.u>>d.v>> d.cost;
        cost[u] = d.cost;
        myData.push(d);
    }


    list<short> que;
    que.push_back(k);
    lens[k] = cost[k];

    while (!que.empty()){
        short index = que.front();
        que.pop_front();
        visNode.push_back(index);
        for(short j=0; j < myData.size(); ++j){
            data d = myData.front();
            if(d.u == index){
                que.push_back(d.v);
                myData.pop();

                lens[j]= max(lens[j], lens[index]+cost[j]);

            } else{
                myData.pop();
                myData.push(d);
            }
        }
    }


    int result = -1;
    if(visNode.size() >= n) {
        for (auto s: lens) {
            result = max(result, s);
        }
    }

    cout << result << "\n";

    return 0;
}