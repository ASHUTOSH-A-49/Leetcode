class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int,vector<int>, greater<int>> minH;
    int signum(int leftSize, int rightSize) {
        if (leftSize == rightSize) return 0;
        return (leftSize > rightSize) ? 1 : -1;
    }
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxH.empty()) {
            maxH.push(num);
            return;
        }
        switch (signum(maxH.size(), minH.size())) {   
            case 0:
                if (num < maxH.top()) {
                    maxH.push(num);
                } else {
                    minH.push(num);
                }
                break;  
            case 1:
                if (num < maxH.top()) {
                    minH.push(maxH.top());
                    maxH.pop();
                    maxH.push(num);
                } else {
                    minH.push(num);
                }
                break;
            case -1:
                if (num > minH.top()) {
                    maxH.push(minH.top());
                    minH.pop();
                    minH.push(num);
                } else {
                    maxH.push(num);
                }
                break;
        }
    }
    
    double findMedian() {
        switch (signum(maxH.size(), minH.size())) {
            case 1:  return (double)maxH.top();
            case -1: return (double)minH.top();
            default: return ((double)maxH.top() + minH.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */