class Heap {
    public:
        virtual void insert(int num) = 0;
        virtual int remove(int num) = 0;
        virtual int removeMax() = 0;
        virtual int search(int num) = 0; //return position of element index + 1

        virtual int getSize() = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
};