class ProductOfNumbers {
    // prefix[i] = product of all numbers added since the last zero (prefix[0] = 1).
    vector<int> prefix;

public:
    ProductOfNumbers() {
        prefix = {1};
    }

    void add(int num) {
        if (num == 0) {
            // Any window that includes this zero has product 0, so reset.
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();
        // If the last k numbers reach back past the most recent zero, the product is 0.
        if (k >= n) return 0;
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
