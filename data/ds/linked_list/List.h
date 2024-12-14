#ifndef LIBRARY_SYSTEM_LIST_H
#define LIBRARY_SYSTEM_LIST_H

// Specification of the class

template<class keyType, class dataType>
class List {
    //data members
    class node {
    public:
        keyType key;
        dataType data;
        node *next;
    };

    typedef node *NodePointer;

    //pointers
    NodePointer head, prev, cursor;

    //operations/functions
public:
    List();

    // Prevent shallow copying
    List(const List &other);            // Copy constructor
    List &operator=(const List &other); // Copy assignment operator

    ~List();

    bool listIsEmpty() const;

    bool cursorIsEmpty() const;

    void toFirst();

    bool atFirst() const;

    void advance();

    void toEnd();

    bool atEnd() const;

    int listSize() const;

    void updateData(const dataType &d);

    void retrieveData(dataType &d) const;

    void retrieveKey(keyType &k) const;

    void insertFirst(const keyType &k, const dataType &d);

    void insertAfter(const keyType &k, const dataType &d);

    void insertBefore(const keyType &k, const dataType &d);

    void insertEnd(const keyType &k, const dataType &d);

    void deleteNode();

    void deleteFirst();

    void deleteEnd();

    void makeListEmpty();

    bool search(const keyType &k);

    void orderInsert(const keyType &k, const dataType &d);

    void traverse();
};

#endif //LIBRARY_SYSTEM_LIST_H