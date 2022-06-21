class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int,vector<int>,greater<int>>heap;
        for(int i=0;i<n-1;i++){
            int k=heights[i+1]-heights[i];
            if(bricks==0 && ladders<=0 && k>0){
                return i;
            }
            if(k>0){
                if(heap.empty() || ladders>0){
                    heap.push(k);
                    ladders-=1;
                }
                else{
                    if(k>heap.top()){
                        bricks=bricks-heap.top();
                        heap.pop();
                        heap.push(k);
                    }
                    else{
                        bricks=bricks-k;
                    }
                }
            }
            if(bricks<0){
                return i;
            }
        }
        return n-1;
    }
};