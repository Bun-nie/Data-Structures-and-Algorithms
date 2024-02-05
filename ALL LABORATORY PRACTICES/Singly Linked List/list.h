class List {
    public:
    virtual void addHead(int num) = 0;
    virtual void addTail(int num) = 0;
    virtual int get(int pos) = 0;
    virtual int getHead() = 0;
    virtual int remove(int num) = 0;
    virtual int removeAt(int pos) = 0;
    virtual int removeHead() = 0;
    virtual void addAt(int num, int pos) = 0;
    virtual int removeAll(int num) = 0;
    virtual void flip() = 0;
    virtual void print() = 0;
};