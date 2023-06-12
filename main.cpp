#include <bits/stdc++.h>
using namespace std;
struct data{
    short u,v, cost;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    short n, m, k;
    cin>>n>>m>>k;

    queue<data> myData;
    vector<int> cost (n+1, 0);
    vector<short> visNode;

    for(int i = 0; i<m; i++){
        data d;
        cin>>d.u>>d.v>> d.cost;
        myData.push(d);
    }


    list<short> que;
    que.push_back(k);

    while (!que.empty()){
        short index = que.front();
        que.pop_front();
        visNode.push_back(index);
        int size = myData.size();

        for(short j=0; j < size; ++j){
            data d = myData.front();
            if(d.u == index){
                que.push_back(d.v);
                cost[d.v] = max(cost[d.v], cost[d.u]+d.cost);
                myData.pop();
            } else{
                myData.pop();
                myData.push(d);
            }
        }

    }
    int result = -1;
    if(visNode.size() >= n) {
        for (auto s: cost) {
            result = max(result, s);
        }
    }

    cout << result << "\n";


    return 0;
}
