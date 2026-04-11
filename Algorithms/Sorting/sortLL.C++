Node *sortWithNSpace(Node *head)
{
    Node *newHead = nullptr, *newList;
    while(head != nullptr)
    {
        // Create new node for each of the nodes of the given LL and find its correct position
        int x = head->val;
        Node *curr = new Node(x);

        // newHead = null => list is null => create the head
        if(newHead == nullptr) 
        {
            newHead = curr;
        }
        
        // Check if the current node is lesser than the head replace it
        else if(x <= newHead->val)
        {
            curr->next = newHead;
            newHead = curr;
        }
        
        // Insert in the of the LL finding correct place
        else
        {
            while(newList->next != nullptr && x > newList->next->val)
            {
                newList = newList->next;
            }
            
            curr->next = newList->next;
            newList->next = curr;
        }
        
        newList = newHead;
        head = head->next;
    }

    return newHead;
}
