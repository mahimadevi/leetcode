class ProductOfNumbers {
public:
    vector<int>v;
    ProductOfNumbers() {
        v.clear();
        v.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            v.clear();
            v.push_back(1);
        }
        else{
            v.push_back(v.back()*num);
        }
    }
    
    int getProduct(int k) {
        int size = v.size();
        if((size-k-1)<0)
            return 0;
        return (v.back()/(v[v.size()-1-k]));
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */