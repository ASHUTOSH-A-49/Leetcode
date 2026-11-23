class ProductOfNumbers {
public:
    vector<int> stream;
    vector<int> preProd;
    int prod = 1;
    ProductOfNumbers() {

    }
    
    void add(int num) {
        stream.push_back(num);
        prod*=num;
        if(prod==0){
            preProd.clear();
            prod = 1;
        }else{
            preProd.push_back(prod);
        }
        
    }
    
    int getProduct(int k) {
        int n = preProd.size();
        if(n<k) return 0;
        if(n==k) return preProd[n-1];
        return preProd[n-1] / preProd[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */