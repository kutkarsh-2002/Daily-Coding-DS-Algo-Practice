class MedianFinder {
public:
    priority_queue<int>max_heap;
    priority_queue<int, vector<int>, greater<int>>min_heap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(max_heap.size()==0){
            max_heap.push(num);
        }
        else if(max_heap.size()==min_heap.size()){
            if(num<min_heap.top()){
                max_heap.push(num);
            }else{
                int temp=min_heap.top();
                min_heap.pop();
                min_heap.push(num);
                max_heap.push(temp);
            }
        }
        
        else{
            
            if(min_heap.size()==0){
                
                if(num>max_heap.top()){
                min_heap.push(num);
                }
                else{
                    int temp=max_heap.top();
                    max_heap.pop();
                    max_heap.push(num);
                    min_heap.push(temp);
                }
            }
            else if(num>=min_heap.top()){
                min_heap.push(num);
            }
            else{
                
                if(num<max_heap.top()){
                    int temp=max_heap.top();
                    max_heap.pop();
                    max_heap.push(num);
                    min_heap.push(temp);
                }
                else{
                    min_heap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        
        int lsize=max_heap.size();
        int rsize=min_heap.size();
        
        if(lsize>rsize){
            
            return (double)(max_heap.top());
        }
        else{
            return ((double)max_heap.top()+(double)min_heap.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */