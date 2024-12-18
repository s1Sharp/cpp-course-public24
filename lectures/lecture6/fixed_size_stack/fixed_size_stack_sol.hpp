class Stack {
public:
    explicit Stack(int capacity)
        : capacity_(capacity)
        , arr_(new int[capacity])
        {}

    void Push(int value) {
        if (curr_top_ == capacity_ - 1) {
            return;
        }

        arr_[++curr_top_] = value;
    }

    int Top() {
        if (curr_top_ == -1) {
            return -1e9 + 7; // throw exception
        }

        return arr_[curr_top_];
    }

    void Pop() {
        if (curr_top_ == -1) {
            return;
        }
        --curr_top_;
    }

    ~Stack() {
        delete[] arr_;
    }

private:
    int capacity_;
    int curr_top_ = -1;
    int* arr_;
};