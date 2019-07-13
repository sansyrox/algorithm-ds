void deleteNode(Node *node)
{
   // Your code here
   Node* temp = node->next;
   node->data = node->next->data;
   node->next = node->next->next;
   temp->next=NULL;
   delete temp;
}

void deleteNode(Node *node)
{
Node *temp = node->next;
*node = *(node->next);
delete temp;
}