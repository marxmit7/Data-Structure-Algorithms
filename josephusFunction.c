Node josephus(int m)
{
    Node p=start,q=start;
    int count;

    while(p->next!=p)
    {   count=1;
        while(count!=m)
        {   count++;
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);

        p=q->next;
        i=k
    }
    printf("the last value of the element is %d\n",q->data);

return q;
}
