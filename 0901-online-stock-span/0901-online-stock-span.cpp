class StockSpanner {
public:
    stack<pair<int,int>> mono_stack_;         // monotonically decreasing stack

    StockSpanner() {
        
    }
    
    // Time: O(1) (amortized time complexity)
    // Space: O(N)
    int next(int price) {
        int span = 1;
        while (!mono_stack_.empty() && mono_stack_.top().first <= price) {
            span += mono_stack_.top().second;
            mono_stack_.pop();
        }

        mono_stack_.push({ price, span });
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */