#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char input;
    struct node *prev;
    struct node *next;
}Node;

int main(){
    Node *head=(Node*)malloc(sizeof(Node));
    Node *tail=(Node*)malloc(sizeof(Node));
    head->next=tail;
    head->prev=tail;
    tail->next=head;
    tail->prev=head;
    char tmp[1000001]={};
    int testcase=0;
    scanf("%s %d",tmp,&testcase);
    for(int i=0;tmp[i]!=0;i++){
        Node *nchar=(Node*)malloc(sizeof(Node));
        nchar->input=tmp[i];
        nchar->next=tail;
        nchar->prev=tail->prev;
        tail->prev->next=nchar;
        tail->prev=nchar;
    }

    Node *curssor=tail;
    char ctmp;
    while(testcase--){
        scanf(" %c",&ctmp);
        switch (ctmp) {
            case 'L':
                if(curssor==head->next);
                else{
                    curssor=curssor->prev;
                }
                break;
            case 'D':
                if(curssor==tail);
                else{
                    curssor=curssor->next;
                }
                break;
            case 'B':
                if(curssor==head->next);
                else{
                    Node *del=curssor->prev;
                    curssor->prev->prev->next=curssor;
                    curssor->prev=curssor->prev->prev;
                    free(del);
                }
                break;
            case 'P':
            {
                scanf(" %c",&ctmp);
                Node *nchar=(Node*)malloc(sizeof(Node));
                nchar->input=ctmp;
                nchar->next=curssor;
                nchar->prev=curssor->prev;
                curssor->prev->next=nchar;
                curssor->prev=nchar;
                break;
            }
        }
    }

    Node *watch=head->next;
    while(watch!=tail){
        printf("%c",watch->input);
        watch=watch->next;
    }

    return 0;
}
