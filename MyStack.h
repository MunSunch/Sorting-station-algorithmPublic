#ifndef CALCULATOR_MYstack_H
#define CALCULATOR_MYstack_H

#include <iostream>

using std::cout;
using std::endl;

template <typename DataType> struct stack
{
    DataType inf;
    stack* next;
};

template <typename DataType> bool isEmpty(stack<DataType>* st){
    return st==NULL;
}

template <typename DataType> void push(stack<DataType>*& st, DataType inf)
{
    stack<DataType>* tmp = new stack<DataType>;
    tmp->inf = inf;
    tmp->next = st;
    st = tmp;
}

template <typename DataType> DataType pop(stack<DataType>*& st)
{
    if(st != NULL)
    {
        stack<DataType>* tmp = st;
        DataType inf = tmp->inf;
        st = tmp->next;
        delete tmp;
        return inf;
    }
}

template <typename DataType> void clean(stack<DataType>*& st)
{
    for(stack<DataType>* ptr = st; ptr!=NULL; ptr=ptr->next)
    {
        pop(st);
    }
}

template <typename DataType> void reverse(stack<DataType>*& st)
{
    stack<DataType>* buf = nullptr;
    for(stack<DataType>* ptr = st; ptr!=NULL; ptr=ptr->next)
    {
        push(buf, ptr->inf);
    }
    clean(st);
    st = buf;
}

template <typename DataType>
stack<DataType>* copy(stack<DataType>*& st, bool reverse = true)
{
    stack<DataType>* buf = nullptr;
    for(stack<DataType>* ptr = st; ptr!=NULL; ptr=ptr->next)
    {
        push(buf, ptr->inf);
    }
    if(!reverse)
    {
        reverse(buf);
    }
    return buf;
}

template <typename DataType> DataType getTop(stack<DataType>*& st)
{
    return st->inf;
}

#endif //CALCULATOR_MYstack_H
