// class HeapNode;
class vertex_list;
class Heap{
    public:
    Heap(vertex_list ** vertices);
    ~Heap();
    // HeapNode ** build_heap();
    int extract_min();
    void heapify(int i, int n);
    int * get_heap();
    double * get_cost_list();
    int * get_prev();
    int get_size();
    void swap(int a, int b);
    void increment();
    private:
    int * heap = nullptr;
    double * cost_list = nullptr;
    int * prev = nullptr;
    int size{0};

};