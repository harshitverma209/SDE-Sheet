
Node * Solve(Node* A, Node* B){
    if(A==NULL){
        return B;
    }
    if(B==NULL){
        return B;
    }
    Node* C;
    if(A->data<B->data){
        C=A;
        C->bottom=Solve(A->bottom,B);
    }else{
        C=B;
        C->bottom=Solve(A,B->bottom);
    }
    return C;
}

Node *flatten(Node *root)
{
  // Your code here
    Node *A=root;
    Node *B=root->next;
    while(B){
        A=Solve(A,B);
        B=B->next;
    }
    return A;
}