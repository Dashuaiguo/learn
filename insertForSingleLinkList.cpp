void List::insert(int toadd, int pos) {
	ListNode *p1 = this->head, *p2 = this->head->next;
	for (int i = 1; i < pos; ++i)
	{
		if (p2 == NULL)
			return;
		p1 = p2;
		p2 = p1->next;
	}
	ListNode *tp = new ListNode;
	tp->data = toadd;
	p1->next = tp;
	tp->next = p2;
}
