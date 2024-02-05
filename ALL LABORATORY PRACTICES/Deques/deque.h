class Deque {
    public:
        //Deque (A Deque is a double-ended queue that allows us to access elements from both the start and end of the queue)
        virtual void addFirst(int e) = 0;
        virtual void addLast(int e) = 0;
        virtual int removeFirst() = 0;
        virtual int removeLast() = 0;
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
        //General
        virtual void print() = 0;
};