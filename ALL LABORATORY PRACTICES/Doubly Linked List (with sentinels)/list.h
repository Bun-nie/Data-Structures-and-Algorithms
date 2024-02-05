class List {
    public:
        virtual void addHead(int num) = 0;
        virtual void addTail(int num) = 0;
        virtual void addAt(int num, int pos) = 0;
        virtual void removeFirst() = 0;
        virtual void removeLast() = 0;
        virtual int remove(int num) = 0;       //returns the position where first instance of the number was removed
        virtual int removeAt(int pos) = 0;     //returns the number removed at a specific position
        virtual int removeAll(int num) = 0;    //returns how many instances of the number was removed
        virtual int get(int pos) = 0;          //returns number at that position
        // virtual int retain(int num) = 0;       //returns how many elements were removed
        // virtual int corner(int num) = 0;       //returns how many elements were removed
        // virtual void reverse() = 0;
        // virtual void swap() = 0;
        virtual int insert(int num) = 0; //returns position where element was inserted
        virtual void print() = 0;
};