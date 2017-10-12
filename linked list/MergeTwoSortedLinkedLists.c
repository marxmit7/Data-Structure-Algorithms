Node* MergeLists(Node* headA, Node* headB)
{ Node *newnode=NULL,*tmp,*p,*q;
	p=headA;
	q=headB;
	if(headA==NULL)
		return headB;
	else if(headB==NULL)
		return headA;
	
	if(p&&q)
	{
		if(p->data<=q->data)
			{
				tmp=p;
				p=tmp->next;
			}
		else if(q->data<p->data)
			{
				tmp=q;
				q=tmp->next;
			}
		newnode=tmp;
		while(p&&q)
		{
			if(p->data<=q->data)
			{	tmp->next=p;
				tmp=p;
				p=tmp->next;
			}
		else if(q->data<p->data)
			{	tmp->next=q;
				tmp=q;
				q=tmp->next;
			}

		}
		if(p==NULL)
		tmp->next=q;
		if(q==NULL)
		tmp->next=p;

		
	}
	return newnode;
}
