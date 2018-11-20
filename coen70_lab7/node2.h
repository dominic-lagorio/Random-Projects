// FILE: node2.h
//
//
// By:   Dominic Lagorio
// Date: 5/24/2017
//
//
// PROVIDES: A template class for a node in a linked list, and list manipulation
// functions, all within the namespace coen70_lab7
//
// TYPEDEF for the node class:
//     Each node of the list contains a piece of data and a pointer to the
//     next node. The type of the data is given by Item. The value_type may be any
//     of the built-in C++ classes (int, char, ...) or a class with a copy
//     constructor, an assignment operator, and a test for equality (x == y).
//
// CONSTRUCTOR for the node class:
//   node(
//     const Item& init_data = value_type(),
//     node* init_link = NULL
//   )
//     Postcondition: The node contains the specified data and link.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the value_type. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. The init_link has a default value of NULL.
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is node*) and a const version (where the return value
//   is const node*).
// EXAMPLES:
//    const node *c;
//    c->link( ) activates the const version of link
//    list_search(c,... calls the const version of list_search
//    node<Item> *p;
//    p->link( ) activates the non-const version of link
//    list_search(p,... calls the non-const version of list_search
//
// MEMBER FUNCTIONS for the node class:
//   void set_data(const Item& new_data)
//     Postcondition: The node now contains the specified new data.
//
//   void set_link(node<Item>* new_link)
//     Postcondition: The node now contains the specified new link.
//
//   Item data( ) const
//     Postcondition: The return value is the data from this node.
//
//   const node<Item>* link( ) const <----- const version
//   node<Item>* link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this node.
//
// FUNCTIONS in the linked list toolkit:
//   size_t list_length(const node<Item>* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list.
//
//   void list_head_insert(node<Item>*& head_ptr, const Item& entry)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   void list_insert(node<Item>* previous_ptr, const node::value_type& entry)
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.
//
//   const node<Item>* list_search(const node<Item>* head_ptr, const Item& target)
//   node* list_search(node<Item>* head_ptr, const <Item>& target)
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing
//     the specified target in its data member. If there is no such node, the
//     null pointer is returned.
//
//   const node<Item>* list_locate(const node<Item>* head_ptr, size_t position)
//   node* list_locate(node<Item>* head_ptr, size_t position)
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The pointer returned points to the node at the specified
//     position in the list. (The head node is position 1, the next node is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned.
//
//   void list_head_remove(node<Item>*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The head node has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   void list_remove(node<Item>* previous_ptr)
//     Precondition: previous_ptr points to a node in a linked list, and this
//     is not the tail node of the list.
//     Postcondition: The node after previous_ptr has been removed from the
//     linked list.
//
//   void list_clear(node<Item>*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.
//
//   void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr)
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that contains the same items as the list pointed to by
//     source_ptr. The original list is unaltered.
//
//   void list_piece(
//     const node<Item* start_ptr, const node<Item>* end_ptr,
//     node<Item>*& head_ptr, node<Item>*& tail_ptr
//   )
//    Precondition: start_ptr and end_ptr are pointers to nodes on the same
//    linked list, with the start_ptr node at or before the end_ptr node
//    Postcondition: head_ptr and tail_ptr are the head and tail pointers for a
//    new list that contains the items from start_ptr up to but not including
//    end_ptr.  The end_ptr may also be NULL, in which case the new list
//    contains elements from start_ptr to the end of the list.
//
//   size_t list_occurrences(node<Item>* head_ptr, const Item& target)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The return value is the count of the number of times
//     target appears as the data portion of a node on the linked list.
//     The linked list itself is unchanged.
//
//   void list_insert_at(node<Item>*& head_ptr, const Item& entry, size_t position)
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0 and position <= list_length(head_ptr)+1.
//     Postcondition: A new node has been added to the linked list with entry
//     as the data. The new node occurs at the specified position in the list.
//     (The head node is position 1, the next node is position 2, and so on.)
//     Any nodes that used to be after this specified position have been
//     shifted to make room for the one new node.
//
//   node<Item>::value_type list_remove_at(node*& head_ptr, size_t position)
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0 and position <= list_length(head_ptr).
//     Postcondition: The node at the specified position has been removed from
//     the linked list and the function has returned a copy of the data from
//     the removed node.
//     (The head node is position 1, the next node is position 2, and so on.)
//
//   node<Item>* list_copy_segment(node<Item>* head_ptr, size_t start, size_t finish)
//     Precondition: head_ptr is the head pointer of a linked list, and
//     (1 <= start) and (start <= finish) and (finish <= list_length(head_ptr)).
//     Postcondition: The value returned is the head pointer for
//     a new list that contains copies of the items from the start position to
//     the finish position in the list that head_ptr points to.
//     (The head node is position 1, the next node is position 2, and so on.)
//     The list pointed to by head_ptr is unchanged.
//
//
// FORWARD ITERATORS to step through the nodes of a linked list
// A node_iterator can change the underlying linked list through the
// * operator, so it may not be used with a const node. The
// node_const_iterator cannot change the underlying linked list
// through the * operator, so it may be used with a const node.
// WARNING:
// This classes use std::iterator as its base class;
// Older compilers that do not support the std::iterator class can
// delete everything after the word iterator in the second line:
//
// DYNAMIC MEMORY usage by the toolkit:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy,
//   list_piece.

#ifndef COEN_70_NODE_H
#define COEN_70_NODE_H
#include <cstdlib> // Provides size_t and NULL
#include <iterator>
#include <cassert>

namespace coen70_lab7
{
    template <class Item>
    class node
    {
    public:
    	

    	// CONSTRUCTOR
    	node (const Item& init_data = Item( ), node<Item>* init_link = NULL)
    	{
            data_field = init_data;
            link_field = init_link;
        }

    	// Member functions to set the data and link fields:
    	void set_data(const Item& new_data) { data_field = new_data; }
    	void set_link(node* new_link) { link_field = new_link; }

    	// Constant member function to retrieve the current data:
    	Item& data( ) { return data_field; }
        const Item& data( ) const { return data_field; }
    	// Two slightly different member functions to retreive
    	// the current link:
    	const node* link( ) const { return link_field; }
        node* link( ) { return link_field; }

    private:
    	Item data_field;
    	node* link_field;
    };

    // FUNCTIONS for the linked list toolkit
    template <class Item>
    std::size_t list_length(const node<Item>* head_ptr);
    
    template <class Item>
    void list_head_insert(node<Item>*& head_ptr, const Item& entry);
    
    template <class Item>
    void list_insert(node<Item>* previous_ptr, const Item& entry);
    
    template <class Item>
    node<Item>* list_search(node<Item>* head_ptr, const Item& target);
    
    template <class Item>
    const node<Item>* list_search
	(const node<Item>* head_ptr, const Item& target);
    
    template <class Item>
    node<Item>* list_locate(node<Item>* head_ptr, std::size_t position);
    
    template <class Item>
    const node<Item>* list_locate(const node<Item>* head_ptr, std::size_t position);
    
    template <class Item>
    void list_head_remove(node<Item>*& head_ptr);
    
    template <class Item>
    void list_remove(node<Item>* previous_ptr);
    
    template <class Item>
    void list_clear(node<Item>*& head_ptr);
    
    template <class Item>
    void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);
    
    // YOU NEED TO IMPLEMENT THE FOLLOWING FUNCTIONS
    template <class Item>
    void list_piece(node<Item>* start_ptr, node<Item>* end_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);
    
    template <class Item>
    size_t list_occurrences(node<Item>* head_ptr, const Item& target);
    
    template <class Item>
    void list_insert_at(node<Item>*& head_ptr, const Item& entry, size_t position);
    
    template <class Item>
    Item list_remove_at(node<Item>*& head_ptr, size_t position);
    
    template <class Item>
    node<Item>* list_copy_segment(node<Item>* head_ptr, size_t start, size_t finish);






    template <class Item>
    class node_iterator
    // : public std::iterator<std::forward_iterator_tag, Item>
    {
    public:
        
        node_iterator(node<Item>* initial = NULL){ current = initial; }
        
        Item& operator *( ) const { return current -> data(); }     // Dereference, gets data of current node
        
        node_iterator& operator ++( ){
            current = current -> link();
            return *this;
        }                                                           // Prefix ++
        
        node_iterator operator ++(int){
            node_iterator orig(current);
            current = current -> link();
            return *this;
        }                                                           // Postfix ++
        
        bool operator ==(const node_iterator other) const{ return current == other.current; }
        
        bool operator !=(const node_iterator other) const{ return current != other.current; }
        
    private:
        node<Item>* current;
    };


    template <class Item>
    class const_node_iterator
    // : public std::iterator<std::forward_iterator_tag, Item>
    {
    public:
        
        const_node_iterator(const node<Item>* initial = (node<Item>*)NULL){ current = initial; }
        
        const Item& operator *( ) const{ return current -> data(); }       // Dereference, gets data of current node
        
        const_node_iterator& operator ++( ){
            current = current -> link();
            return *this;
        }                                                                  // Prefix ++
        
        const_node_iterator operator ++(int){
            const_node_iterator orig(current);
            current = current -> link();
            return *this;
        }                                                                  // Postfix ++
        
        bool operator ==(const const_node_iterator other) const{ return current == other.current; }
        
        bool operator !=(const const_node_iterator other) const{ return current != other.current; }
        
    private:
        const node<Item>* current;
    };
    
}
#include "node2.cxx"
#endif
