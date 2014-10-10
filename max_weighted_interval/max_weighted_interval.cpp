#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval{
    int start;
    int end;
    int weight;
    Interval(int s,int e,int w):start(s),end(e),weight(w){}
};

/*
Amazon question:
Given a set of intervals with their own weights, find a subset of intervals without overlapping
that have the max sum of weights
assume no negative weights
*/

bool cmp(const Interval &itv1,const Interval &itv2){
    return itv1.end<itv2.end;
}

int maxWeightedIntervals(vector<Interval> &intervals){
    int result = 0;
    if(intervals.size()==0) return 0;
    if(intervals.size()==1) return intervals[0].weight;
    std::sort(intervals.begin(),intervals.end(),cmp);
    vector<int> dp(intervals.size(),-1);
    dp[0] = intervals[0].weight;
    for(int i = 1;i<intervals.size();i++){
        int p = 0,q = i-1;
        while(p<q){
            int mid = (p+q)/2;
            if(intervals[mid].end<=intervals[i].start&&intervals[mid+1].end>intervals[i].start){
                p = mid;
                break;
            }
            else if(intervals[mid].end>intervals[i].start) {
                q = mid;
            }
            else {
                p = mid+1;
            }
        }
        dp[i] = intervals[p].end<=intervals[i].start?dp[p]+intervals[i].weight:intervals[i].weight;
    }
    return dp.back();
}


int main(){
    vector<Interval> intervals;
    intervals.push_back(Interval(0,2,4));
    intervals.push_back(Interval(1,2,5));
    intervals.push_back(Interval(2,5,1));
    intervals.push_back(Interval(3,6,2));
    intervals.push_back(Interval(2,3,4));
    cout<<maxWeightedIntervals(intervals)<<endl;

}



