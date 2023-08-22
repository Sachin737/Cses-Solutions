#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<int> ManacherAlgorithm(string s){
    int n = s.size();
    s = '&' + s + '%';
    vector<int>p(n+2,0);

    int l = 1, r = 1;
    for(int i=1;i<=n;i++){
        p[i] = max(0ll, min(r-i,p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]){
            p[i]++;
        }
        if(i + p[i] > r){
            l = i - p[i];
            r = i + p[i];
        }
    }

    return vector<int>(p.begin()+1,p.end()-1);
}

vector<int> ManacherAlgorithmEven(string s) {
    string t="";
    for(auto c: s) {
        t += "#";
        t += c;
    }
    t += "#";
    auto res = ManacherAlgorithm(t);
    return vector<int>(res.begin() + 1, res.end() - 1);
}

int32_t main(){
    string s; cin >> s;
    int n = s.size();

    vector<int> pod = ManacherAlgorithm(s);
    vector<int> pev = ManacherAlgorithmEven(s);

    int mx = 0, id = 0;
    for(int i=0;i<n;i++){
        if(pod[i] * 2 - 1 >= mx){
            mx = pod[i] * 2 - 1;
            id = i - pod[i] + 1;
        }
    }

    for(int i=1;i<(int)pev.size();i+=2){
        if(pev[i]-1 >= mx){
            mx = pev[i]-1;
            id = i/2ll - mx/2ll + 1;
        }
    }
    cout << s.substr(id,mx) << "\n";

    
    return 0;
}