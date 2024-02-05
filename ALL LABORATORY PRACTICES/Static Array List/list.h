class List {
  public:
    virtual int add(int num) = 0;
    virtual int addAt(int num, int pos) = 0;
    virtual int remove(int num) = 0;
    virtual int size() = 0;
    virtual void print() = 0;
};
