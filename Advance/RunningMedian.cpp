#include<bits/stdc++.h>
using namespace std;

typedef struct mini{
    int no;
    bool operator < (const mini& p)const{
        if(p.no<no){
            return true;
        }
        return false;
    }
}mini;

typedef struct maxi{
    int no;
    bool operator < (const maxi& p)const{
        if(p.no>no){
            return true;
        }
        return false;
    }
}maxi;


priority_queue<mini> minHeap;
priority_queue<maxi> maxHeap;


int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int no;
        scanf("%d",&no);
        if(minHeap.empty() && maxHeap.empty()){
            maxi p;
            p.no=no;
            maxHeap.push(p);
        }
        else{
            if(maxHeap.top().no>no){
                maxi p;
                p.no=no;
                maxHeap.push(p);

                if(maxHeap.size() > minHeap.size()+1){
                    mini p;
                    p.no = maxHeap.top().no;
                    maxHeap.pop();
                    minHeap.push(p);
                }
            }else{
                mini p;
                p.no=no;
                minHeap.push(p);

                if(! (minHeap.size()==maxHeap.size() || minHeap.size()==maxHeap.size()-1) ){
                    maxi p;
                    p.no = minHeap.top().no;
                    minHeap.pop();
                    maxHeap.push(p);
                }
            }
        }

        if(maxHeap.size()>minHeap.size()){
            printf("%.1lf\n",(double)maxHeap.top().no);
        }else if(maxHeap.size()==minHeap.size()){
            printf("%.1lf\n",((double)maxHeap.top().no+(double)minHeap.top().no)/(double)2.0);
        }
    }
}
