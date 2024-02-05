class List {
    public:
        virtual void addHead(int num) = 0;
        virtual void addTail(int num) = 0;
        virtual int get(int pos) = 0;
        virtual void removeFirst() = 0;
        virtual void removeLast() = 0;
        virtual int remove(int num) = 0;
        //virtual DoublyLinkedList* combine(List *l1, List* l2) = 0;
        //virtual void addAt(int num, int pos) = 0;
        //virtual int removeAt(int pos) = 0; //returns int that was removed
        virtual int retain(int num) = 0;
        virtual int corner(int left, int right) = 0;
        //virtual int removeAll(int num) = 0; //returns how many instances of the number removed
        virtual void print() = 0;
};