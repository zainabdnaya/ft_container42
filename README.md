# ft_container42

The aim of this project is to The multiple available containers in C++ , so we gonna re-implement them!
Here are the specificities of the five containers:

      Vector: a dynamic array that allows insertion at the end of the container. Elements can be easily access thanks with the corresponding index, but it's not the most optimal container if a lot of insertion / deletion are needed.
      Map: a sorted container using an Red-Black tree (auto-equilibrates itself to optimize the time to find a value in the tree), in order to store the data like in a dictionnary (a key associated to its value).
      Stack: a container adaptator (LIFO, last in first out).
      Set: a container that store unique elements following a specific order,is implimented as Red-Black tree (auto-equilibrates itself to optimize the time to find a value in the tree).

# Resources

<a href="https://docs.microsoft.com/fr-fr/cpp/standard-library/vector-class?view=msvc-170&viewFallbackFrom=vs-2019">microsift-vectors-libraty</a>

<a href="https://www.cplusplus.com/reference/vector/vector/?kw=vector"> cpp_vectors</a>

<a href="https://www.oreilly.com/library/view/c-in-a/059600298X/re673.html">iterators_traits</a>

# Questions:

## what is a container specifically?

    An iterator is an object (like a pointer) that points to an element inside the container.
    We can use iterators to move through the contents of the container. They can be
    visualised as something similar to a pointer pointing to some location and we can
    access content at that particular location using them.
    Iterators play a critical role in connecting algorithm with containers along with the
    manipulation of data stored inside the containers. The most obvious form of iterator is a
    pointer. A pointer can point to elements in an array, and can iterate through them using
    the increment operator (++). But, all iterators do not have similar functionality as that of
    pointers.
    Depending upon the functionality of iterators they can be classified into five categories,
    as shown in the diagram below with the outer one being the most powerful one and
    consequently the inner one is the least powerful in terms of functionality.

## Why do I need iterator_traits ?

    Synopsis
    template<typename Iterator>
    struct iterator_traits{
      typedef typename Iterator::difference_type difference_type;
      typedef typename Iterator::value_type value_type;
      typedef typename Iterator::pointer pointer;
      typedef typename Iterator::reference reference;
      typedef typename Iterator::iterator_category iterator_category;
    };

The iterator_traits class template declares traits for an iterator. If you use the iterator class template as the base for your custom iterator, you don’t need to specialize iterator_traits. If you are writing a custom container or algorithm, you should always use iterator_traits to obtain the traits of an iterator. If you use a plain pointer as an iterator, the standard library specializes iterator_traits for you. See the next subsection.

If you write your own specialization, the iterator_category type must be one of the five iterator tag classes. (See the iterator class template.) For an output iterator, difference_type and value_type are void.

When writing a generic algorithm or other function that uses iterators, you can use iterator_traits to specialize the behavior for certain kinds of iterators. See Example 13-19 (under distance), which shows how iterator traits can be used to improve the performance of a function.

## Use of Enable_if

    template <bool, typename T = void>
    struct enable_if
    {};

    template <typename T>
    struct enable_if<true, T> {
      typedef T type;
    };

It's so useful because it's a key part in using type traits, a way to restrict templates to types that have certain properties.

## Red Black Tree

    Red-Black trees are a type of self-balancing binary search tree.
    They are a type of binary search tree that has the following properties:
    1. The left subtree of a node is always smaller than the right subtree.
    2. The left and right subtrees of a node are either both red or both black.
    3. The root is black.
    4. All leaves (NIL) are black.
    5. If a node is red, then both its children are black.
    6. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.

## References:

<a href="http://www.btechsmartclass.com/data_structures/red-black-trees.html" >Red-Black Tree</a>

<a href="https://www.cs.usfca.edu/~galles/visualization/Algorithms.html">Data Structures visualisation</a>

<a href="https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/">Red-Black Tree</a>
