class Queue {
    public:
        //Normal Queue
        virtual void enqueue(int e) = 0;
        virtual int dequeue() = 0; //removes and returns first element of the queue
        virtual int peek() = 0; //returns the first element of the queue without removing it
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
        //General
        virtual void print() = 0;

        //Additional
        virtual void reverse() = 0;
};