//
// Created by zmz on 19-2-5.
//

#include "container.h"
#include <iostream>


VectorContainer::VectorContainer() : Container()
{

}

VectorContainer::VectorContainer(Sort *function) : Container(function)
{

}

void VectorContainer::set_sort_function(Sort *sort_function)
{
    this->sort_function = sort_function;
}

void VectorContainer::add_element(Base *element)
{
    vector.push_back(element);
}

void VectorContainer::print()
{
    for(int i = 0; i < vector.size(); i++)
    {
        std::cout<<vector[i]->stringify()<<std::endl;
    }
}

void VectorContainer::sort()
{
    if(sort_function == nullptr)
        throw "uninitialized sort_function";
    sort_function->sort(this);
}

void VectorContainer::swap(int i, int j)
{
    Base* temp = vector[i];
    vector[i] = vector[j];
    vector[j] = temp;
}

Base *VectorContainer::at(int i)
{
    return vector[i];
}

int VectorContainer::size()
{
    return vector.size();
}




void ListContainer::set_sort_function(Sort *sort_function)
{
    this->sort_function = sort_function;
}



void ListContainer::add_element(Base *element)
{
    list.push_back(element);
}

void ListContainer::print()
{
    std::list<Base*>::iterator it;
    for(it = list.begin() ; it != list.end(); ++it)
    {
        std::cout<<(*it)->stringify()<<std::endl;
    }
}

void ListContainer::sort()
{
    sort_function->sort(this);
}

void ListContainer::swap(int i, int j)
{

    std::list<Base*>::iterator it1 = std::next(list.begin(), i);
    std::list<Base*>::iterator it2 = std::next(list.begin(), j);
    Base* temp = *it1;
    list.erase(it1);
    list.insert(std::next(list.begin(), i-1), *it2);


    list.erase(it2);
    list.insert(std::next(list.begin(), j), temp);





}

Base *ListContainer::at(int i)
{
    std::list<Base*>::iterator it = std::next(list.begin(), i);
    return *it;
}


int ListContainer::size()
{
    return list.size();
}
