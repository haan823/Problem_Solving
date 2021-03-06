#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, l;
vector<int> v;
deque<pair<int, int>> dq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i=0; i<n; i++){
        if(!dq.empty() && dq.front().second <= i - l){
            dq.pop_front();
        }
        while(!dq.empty() && dq.back().first > v[i]){
            dq.pop_back();
        }
        dq.push_back(make_pair(v[i], i));
        cout << dq.front().first << " ";
    }
}