class CustomStack {
public:
    vector<int> value;
    vector<int> increment1;
    int index;

    CustomStack(int maxSize) {
        value.resize(maxSize);
        increment1.resize(maxSize);
        index = -1;
    }
    
    void push(int x) {
        if (index + 1 == value.size()) {
            return;
        }
        index++;
        value[index] = x;
        increment1[index] = 0;
    }
    
    int pop() {
        if (index == -1) {
            return -1;
        }
        int x = value[index];
        int inc = increment1[index];
        if (index > 0) {
            increment1[index - 1] += increment1[index];
        }
        index--;
        return x + inc;
    }
    
    void increment(int k, int val) {
        int ind = min(k - 1, index);
        if (index >= 0) {
            increment1[ind] += val;
        }
    }
};
