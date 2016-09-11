void List::remove(int pos) {
	ListNode *p1 = this->head, *p2 = this->head->next;
	for (int i = 1; i < pos; ++i)
	{
		if (p2 == NULL)
			return;
		p1 = p2;
		p2 = p2->next;
	}
	if (p2->next == NULL) {
		delete p2;
	} else {
		p1->next = p2->next;
		p2->next = NULL;
		delete p2;
	}
}