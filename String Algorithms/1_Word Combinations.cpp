// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool havekey(char x)
    {
        return (links[x-'a']!=NULL);
    }

    void put(char c,Node *nxt)
    {
        links[c-'a'] = nxt;
    }

    Node* get(char c)
    {
        return links[c-'a'];
    }

    void setflag()
    {
        flag=true;
    }

    bool getflag()
    {
        return flag;
    }
};

class Trie
{

public:
    Node *root;
    
    // initialize trie data structure
    Trie()
    {
        root = new Node();
    }

    // Insertion of word in trie
    void insert(string word)
    {
        Node* cur = root;
        for(int i=0;i<(int)word.size();i++)
        {
            if(!cur->havekey(word[i]))
            {
                cur->put(word[i],new Node()); 
            }
            cur = cur->get(word[i]);
        }
        cur->setflag();
    }

    // Searching full word in trie
    bool search(string word)
    {
        Node* cur = root;
        for(int i=0;i<(int)word.size();i++)
        {
            if(!cur->havekey(word[i]))return false;
            cur = cur->get(word[i]);
        }
        return cur->getflag();
    }

    // Searching if there exist word which starts with prefix
    bool startswith(string prefix)
    {
        Node* cur = root;
        for(int i=0;i<(int)prefix.size();i++)
        {
            if(!cur->havekey(prefix[i]))return false;
            cur = cur->get(prefix[i]);
        }
        return true;
    }

};

string s;
int n,k;
const int mod = 1e9+7;
vector<int>dp;

int main()
{
    cin >> s >> k;
    n = s.size();
    dp.assign(n+1,0);

    Trie trie;

    for(int i=0;i<k;i++){
        string a;cin >> a;
        trie.insert(a);
    }

    dp[0] = 1;
    for(int i=0;i<n;i++){
        Node* cur = trie.root;
        for(int j=i;j<n;j++){
            if(cur->havekey(s[j])){
                cur = cur->get(s[j]);
            }else{
                break;
            }
            if(cur->getflag()){
                dp[j+1] = dp[j+1] + dp[i];
                dp[j+1] %= mod;
            }
        }
    }
    // for(auto &x:dp)cout<<x<<" ";
    cout<<dp.back();
    

    return 0;
}