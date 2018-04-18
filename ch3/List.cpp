#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreateList();
void DeleteList(List l);
int IsEmpty(List l);
int IsLast(Position p);
Position Find(int x, List l);
Position FindPrevious(int x, List l);
void Delete(int x, List l);
void Insert(int x, List l, Position p);
void PrintList(List l);
/* Functions have not finished.
Position Header(List l);
Position First(List l);
Position Advance(Position p);
int Retrieve(Position p);
*/


struct Node
{
    Node(){
        next = NULL;
    }
    int element;
    Position next;
};
List CreateList() {
    List l = (Node *) malloc(sizeof(Node));
    if(l == NULL) printf("Out of space!\n");
    return l;
}

void DeleteList(List l) {
    Position p, temp;
    p = l->next;
    l->next = NULL;
    while(p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}

int IsEmpty(List l) {
    return l->next == NULL;
}

int IsLast(Position p) {
    return p->next == NULL;
}

/* return last if x is not found */
Position Find(int x, List l) {
    Position p = l;
    while(p->next != NULL && p->element != x) {
        p = p->next;
    }
    return p;
}

Position FindPrevious(int x, List l) {
    Position p = l;
    while(p->next != NULL && p->next->element != x) {
        p = p->next;
    }  
    return p;
}

void Delete(int x, List l) {
    Position p = FindPrevious(x,l);
    if(!IsLast(p)) {
        Position temp = p->next;
        p->next = temp->next;
        free(temp);
    }
    else
        printf("Illegal data!\n");
}

void Insert(int x, List l, Position p) {
    Position temp;
    temp = (Node *) malloc(sizeof(Node));
    if(temp == NULL) printf("Out of space!\n");
    temp->element = x;
    temp->next = p->next;
    p->next = temp;
}

void PrintList(List l) {
    Position p = l->next;
    while(!IsLast(p)) {
        printf("%d\n", p->element);
        p = p->next;
    }
    printf("%d\n", p->element);
}

int main() {
    List l = CreateList();
    printf("%d\n", IsEmpty(l));
    Insert(1,l,l);
    Position p = Find(1,l);
    Insert(2,l,p);
    PrintList(l);
    return 0;
}

