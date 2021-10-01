#include <bits/stdc++.h>
using namespace std;

// typedef list<entry*>::iterator Litr;
 
struct entry{
    int key;
    int value;
    entry(int x,int y): key(x),value(y){}
};
list<entry*> glist;
unordered_map<int,list<entry*>::iterator> mp;
int lruSize;
int cap;

void init(int capacity) {
    cap=capacity;
    lruSize=0;
    mp.clear();
    glist.clear();
}

int get(int key) {
    if(mp.find(key)==mp.end())return -1;
    list<entry*>::iterator itr=mp[key];
    entry *temp=*itr;
    glist.erase(itr);
    glist.push_front(temp);
    return temp->value;
}

void set(int key, int value) {
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
        glist.erase(itr);
        glist.push_front(temp);
    }

}

int main(){
    
    return 0;
}