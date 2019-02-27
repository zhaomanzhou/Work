#ifndef __SORT_HPP__
#define __SORT_HPP__

#include "container.h"

class Container;

class Sort {
    public:
        /* Constructors */
        Sort(){};

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

class SelectionSort: public Sort
{
public:
    SelectionSort();

    void sort(Container *container) override;
};

class BubbleSort: public Sort
{
public:
    BubbleSort();

    void sort(Container *container) override;
};

#endif //__SORT_HPP__
