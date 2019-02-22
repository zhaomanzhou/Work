#include "sort.h"

BubbleSort::BubbleSort() : Sort()
{

}

SelectionSort::SelectionSort() : Sort()
{

}

void BubbleSort::sort(Container *container)
{
    for(int i = 0; i < container->size()-1; i++)
    {
        for(int j = 0; j < container->size()-1-i; j++)
        {
            if(container->at(j)->evaluate() > container->at(j+1)->evaluate())
                container->swap(j, j+1);
        }
    }
}

void SelectionSort::sort(Container *container)
{
    for(int i = 0; i < container->size()-1; i++)
    {
        double max = container->at(0)->evaluate();
        int index = 0;
        for(int j = 1; j < container->size()-i; j++)
        {
            if(container->at(j)->evaluate() > max)
            {
                max = container->at(j)->evaluate();
                index = j;
            }
        }
        container->swap(index, container->size()-1-i);
    }
}
