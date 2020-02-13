
#include "object.h"

class linked_array : public Object
{
    public:
        void **items;
        size_t max;
        size_t size;
        linked_array *next;

    linked_array()
    {
        items = new void*[2];
        max = 2;
        size = 0;
    }

    linked_array(size_t ss)
    {
        items = new void*[ss];
        max = ss;
        size = 0;
    }
    
    ~linked_array()
    {
        if(next)
        {
            delete(next);
        }
        for(int ii = 0; ii < size; ii++)
        {
            delete(items[ii]);
        }
        delete[](items);
    }

    void push_back(void *item)
    {
        if(size == max)
        {
            if(next)
            {
                next->push_back(item);
                return;
            }
            else
            {
                next = new linked_array(2 * max);
                next->push_back(item);
                return;
            }
        }
        else
        {
            items[size] = item;
            size++;
            return;
        }
    }

    void* get(int index)
    {
        if(index > max)
        {
            if(next)
            {
                index -= max;
                return next->get(index);
            }
            else
            {
                return 0;
            }
            
        }
        if(index >= size)
        {
            return 0;
        }
        else
        {
            return items[index];
        }
    }

    void* set(int index, void *item)
    {
        if(index >= max)
        {
            index -= max;
            if(next)
            {
                return next->set(index, item);
            }
            else
            {
                if(index == 0)
                {
                    push_back(item);
                    return 0;
                }
            }
            
        }
        else
        {
            if(index < size)
            {
                void *ret = items[index];
                items[index] = item;
                return ret;
            }
            if(index == size)
            {
                items[index] = item;
                return 0;
            }
        }
        return 0;
    }
};
