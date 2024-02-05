class List {
    public:
        virtual void addFirst(int num) = 0;
        virtual void addLast(int num) = 0;
        virtual void rotate() = 0;
        virtual int removeFirst() = 0;
        virtual void display() = 0;
};