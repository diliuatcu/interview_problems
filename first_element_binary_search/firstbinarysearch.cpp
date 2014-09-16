#include <iostream>

using namespace std;

// Given a sorted integer array and a specific integer, find the
// first position of that integer. Array contains lots of
// duplicate.

int findfirst(int* a,int pos){
    if(pos==0) return pos;
    if(a[pos]!=a[pos-1]) return pos;
    int offset = 1;
    while((offset<<1)>0&&pos-(offset<<1)>=0&&a[pos-(offset<<1)]==a[pos]) offset = offset<<1;
    return findfirst(a,pos-offset);
}

int binarysearch(int* a,int s,int e,int target){
    if(s>e){
        return -1;
    }
    else if(s==e){
        if(a[s]==target){
            return findfirst(a,s);
        }
        else return-1;
    }
    else{
        int mid = (s+e)/2;
        if(a[mid]==target) return findfirst(a,mid);
        else if(a[mid]>target) return binarysearch(a,s,mid,target);
        else return binarysearch(a,mid+1,e,target);
    }
}


int main(){

    int a[] = {1,1,2,3,3,3,4,6,7,7,7};
    int n = 11;
    cout<<binarysearch(a,0,n-1,1)<<endl;
    cout<<binarysearch(a,0,n-1,3)<<endl;
    cout<<binarysearch(a,0,n-1,5)<<endl;
    cout<<binarysearch(a,0,n-1,4)<<endl;
    cout<<binarysearch(a,0,n-1,7)<<endl;
    cout<<binarysearch(a,0,n-1,10)<<endl;

}
