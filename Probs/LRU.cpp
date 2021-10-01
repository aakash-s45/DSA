#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
 class LRUCache{
    public:
    LRUCache(int);
    int get(int);
    void set(int,int);


 };

struct entry{
    int key;
    int value;
    entry(int x,int y): key(x),value(y){}
};
list<entry*> glist;
unordered_map<int,list<entry*>::iterator> mp;
int lruSize;
int cap;



LRUCache::LRUCache(int capacity) {
    cap=capacity;
    lruSize=0;
    mp.clear();
    glist.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key)==mp.end())return -1;
    list<entry*>::iterator itr=mp[key];

    entry *temp=*itr;
    mp.erase(mp.find(key));
    glist.erase(itr);

    glist.push_front(temp);
    mp.insert(make_pair(key,glist.begin()));
    return temp->value;
}

void LRUCache::set(int key, int value) {
    if(mp.find(key)==mp.end()){
        if(lruSize>=cap){
            mp.erase(mp.find(glist.back()->key));
            glist.pop_back();

            entry *temp=new entry(key,value);
            glist.push_front(temp);
            mp.insert(make_pair(key,glist.begin()));
        }
        else{
            entry *temp=new entry(key,value);
            glist.push_front(temp);
            mp.insert(make_pair(key,glist.begin()));
            lruSize++;
        }
    }
    else{
        list<entry*>::iterator itr = mp[key];
        entry *temp = new entry(key,value);
        mp.erase(mp.find(key));
        glist.erase(itr);

        glist.push_front(temp);
        mp.insert(make_pair(key,glist.begin()));
    }

}

void disp(vector<int> vec){
    for(int a:vec){
        cout<<a<<' ';
    }
    cout<<endl;
}
void disp(vector<vector<int>> vec){
    for(vector<int> a:vec){
        disp(a);
    }
}

int main(){
    int n;
    cin>>n;

    int cap;
    cin>>cap;
    LRUCache lru(cap);
    vector<int>res;
    while(n--){
        char ch;
        cin>>ch;
        if(ch=='S'){
            int a,b;
            cin>>a>>b;
            lru.set(a,b);
        }
        else if(ch=='G'){
            int a;
            cin>>a;
            res.push_back(lru.get(a));
        }

    }
    cout<<endl;
    cout<<endl;
    disp(res);
    return 0;
}