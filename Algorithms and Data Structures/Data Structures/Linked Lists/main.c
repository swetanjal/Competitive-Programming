#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node * next;
}node;
node * HEAD;
node * END;
void print(node * curr)
{
    while(curr!=NULL)
    {
        printf("%d ",curr->val);
        curr=curr->next;
    }
}

void add()
{
    if(HEAD==NULL)
    {
        node * tmp=(node *)malloc(sizeof(node));
        scanf("%d",&tmp->val);
        tmp->next=NULL;
        HEAD=tmp;
        END=tmp;
    }
    else
    {
        node * tmp=(node *)malloc(sizeof(node));
        scanf("%d",&tmp->val);
        tmp->next=NULL;
        END -> next = tmp;
        END=tmp;
    }
}

void reverse()
{
    node * curr=HEAD;
    node * prev=NULL;
    while(curr!=NULL)
    {
        node * Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    HEAD=prev;
}

void _remove()
{
    node * tmp=HEAD->next;
    free(HEAD);
    HEAD=tmp;
}

int main()
{
    int Q;
    HEAD=NULL;
    END=HEAD;
    scanf("%d",&Q);
    while(Q--)
    {
        int C;
        scanf("%d",&C);
        if(C==1)add();
        else _remove();
    }
    print(HEAD);
    printf("\n");
    reverse();
    print(HEAD);
    printf("\n");
    return 0;
}
