#include <iostream>
#include<vector>
using namespace std;


class heap{
private:
    vector<int> vec;
    void swap(int &a,int &b);
    void heapify();
    int vec_size;

public:
    heap();
    void push(int val);
    int top();
    void disp();
    void pop();
    bool empty(){
        return (vec_size==0)?true:false;
    }
};

heap::heap(){
    vec.clear();
    vec.push_back(-1);
    vec_size=0;
}
void heap::swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void heap::push(int val){
    vec.push_back(val);
    vec_size++;
    int index = vec_size;
    int parent_index=index/2;
    
    while(index>1){
        parent_index=index/2;
        if((vec[index])>(vec[parent_index])){
            swap(vec[index],vec[parent_index]);
            index=parent_index;
        }
        else {
            return;
        }
    }  
}
int heap::top(){
    return vec[1];
}
void heap::heapify(){
   int start=1;
   int end=vec_size;
   while (start<end){
       int left=vec[2*start];
       int right=vec[2*start+1];
       int larger=left>right?(2*start):(2*start+1);
       if(vec[start]<vec[larger]){
           swap(vec[larger],vec[start]);
           start=larger;
       }
       else return;
   }  
}
void heap::pop(){
    vec.erase(vec.begin()+1);
    vec_size--;
    heapify();
}
void heap::disp(){
    for (int i = 1; i < vec_size; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}





int main(){
    heap h1=heap();

    h1.push(1);
    h1.push(5);
    h1.push(4);
    h1.push(2);
    h1.push(7);
    h1.push(9);

    while (!h1.empty()){
        cout<<h1.top()<<" ";
        h1.pop();
    }
    

    return 0;
}