// FILE: sequence2.h
// CLASS PROVIDED: sequence2 (part of the namespace coen70_lab7)
// This is the header file for the project described in Section 5.4
// of "Data Structures and Other Objects Using C++"
// This is called "sequence3" because some students already implemented
// sequence1 (with a fixed array) and sequence2 (with a dynamic array).
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//
//   typedef ____ size_type
//     sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
// CONSTRUCTOR for the sequence class:
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The precursor and cursor are adjusted such that the first
//     item in the sequence becomes the current item (but if the sequence is
//     empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const Item& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and
//     the item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   Item current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
//   iterator begin( )
//   const_iterator begin( ) const
//   iterator end( )
//   const iterator end( ) const
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.

#ifndef COEN_70_SEQUENCE_H
#define COEN_70_SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include "node2.h"  // Provides node class

namespace coen70_lab7
{
    template <class Item>
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef node_iterator<Item> iterator;
        typedef const_node_iterator<Item> const_iterator;
        // CONSTRUCTORS and DESTRUCTOR
        sequence( );
        sequence(const sequence& source);
        ~sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const Item& entry);
        void attach(const Item& entry);
        void operator =(const sequence& source);
	    void remove_current( );
        // CONSTANT MEMBER FUNCTIONS
        size_t size( ) const;
        bool is_item( ) const;
        Item current( ) const;
        // FUNCTIONS TO PROVIDE ITERATORS
        iterator begin( ){ return iterator(head_ptr); }
        node_iterator<Item> begin( ) const {return const_iterator(head_ptr); }
        iterator end( ){return iterator(tail_ptr);}
        const_node_iterator<Item> end( ) const{ return const_iterator(tail_ptr); }
    private:
    	node<Item> *head_ptr;
    	node<Item> *tail_ptr;
    	node<Item> *cursor;
    	node<Item> *precursor;
        size_t many_nodes;

        void init();
    };
}

#include "sequence2.cxx"
#endif
