#include "bits/stdc++.h"
using namespace std;
map < pair <char, int> , vector <string > > H;
vector < vector <string> > V;
vector < pair < string, string > > start;
vector < pair <string, string > > last;
vector < string > stock;
int N;

bool count111(string a, string b){
    string str = a;
    int l1 = str.size();
    int cnt1 = 0;
    for(int j = 0; j < l1; ++j)
    {
        if(str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u')
            cnt1++;
    }
    str = b;
    int l2 = str.size();
    int cnt2 = 0;
    for(int j = 0; j < l2; ++j)
    {
        if(str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u')
            cnt2++;
    }
    return (cnt1 == cnt2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        string str;
        cin >> str;
        int L = str.size();
        int cnt = 0;
        char ch;
        for(int j = 0; j < L; ++j){
            if(str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u')
                cnt++, ch = str[j];
        }
        H[{ch, cnt}].push_back(str);
    }
    for(int i = 1; i <= 1000000; ++i){
        if(H.find({'a', i}) != H.end())
            V.push_back(H[{'a', i}]);
        if(H.find({'e', i}) != H.end())
            V.push_back(H[{'e', i}]);
        if(H.find({'i', i}) != H.end())
            V.push_back(H[{'i', i}]);
        if(H.find({'o', i}) != H.end())
            V.push_back(H[{'o', i}]);
        if(H.find({'u', i}) != H.end())
            V.push_back(H[{'u', i}]);
    }
    int LLL = V.size();
    for(int i = 0; i < LLL; ++i){
        int len = V[i].size();
        if((len % 2) != 0){
            stock.push_back(V[i][len - 1]);
            V[i].pop_back();
            --len;
        } 
        while(V[i].empty() == false){
            start.push_back({V[i][len - 1], V[i][len - 2]});
            V[i].pop_back();
            V[i].pop_back();
            --len;
            --len;
        }
    }
    LLL = stock.size();
    for(int i = 0; i < LLL; ++i){
        if(i != (LLL - 1)){
            if(count111(stock[i], stock[i + 1])){
                last.push_back({stock[i], stock[i + 1]});
                ++i;
            }
        }
    }
    while(start.size() > last.size()){
        pair <string, string> k = start[start.size() - 1];
        last.push_back(k);
        start.pop_back();
    }
    int lol =  min(last.size(), start.size());
    cout << lol << endl;
    for(int i = 0; i < lol; ++i){
        cout << last[i].first << " " << start[i].first << endl;
        cout << last[i].second <<  " " << start[i].second << endl;
    }
    return 0;
}