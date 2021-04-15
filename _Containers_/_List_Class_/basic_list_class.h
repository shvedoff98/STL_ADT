template <typename T>

class List {

    protected:
        int size;

    public:
        List(void); // Constructor

        // get methods
        virtual int Listsize(void) const;
        virtual int ListEmpty(void) const;
        virtual int Find(T& item) = 0;

        // modification methods of the list
        virtual void Insert(const T& item) = 0;
        virtual void Delete(const T& item) = 0;
        virtual void ClearList(void) = 0;
};

