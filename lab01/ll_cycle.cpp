#include "ll_cycle.h"

bool ll_has_cycle(node *head) {
    if(head == nullptr)
    {
        return 0;
    }
    node *hare, *snail;
    hare = head;
    snail = head;
    int value = 2;
    do
    {
        if(hare->next != nullptr)
        {
            hare = hare->next;
            snail = snail->next;
            if(hare->next != nullptr)
            {
                hare = hare->next;
                if(hare == snail)
                {
                    value = 1;
                }
            }
            else
            {
                value = 0;
            }
        }
        else
        {
            value = 0;
        }
    }while(value == 2);
    if(value == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    /* Ваш код должен быть написан только внутри этой функции */
    return true;
}
