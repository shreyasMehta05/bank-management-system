#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define max_name 50
#define MAX_NO 1000
int hash_accountNum[MAX_NO];
typedef enum {
    savings,
    current
}AccountType;

typedef struct AccountInfo{
    int num;
    char name[max_name];
    AccountType type;
    float balance;
}AccountInfo;

typedef struct Node{
    AccountInfo data;
    struct Node* next;
}Node;
typedef Node* linkedlist;

typedef struct bank{
    linkedlist members;
    int size;
}bank;


linkedlist append( linkedlist l,AccountInfo a){
    linkedlist Head=l;
    Node *D=(Node*)malloc(sizeof(Node));
    D->data=a;
    D->next=NULL;
    if(l==NULL){
        Head=D;
        return D;
    }
    else{
      while(l->next!=NULL){
        l=l->next;
      }
    l->next=D;
      return Head;
    }
}
linkedlist sorted(bank *b){
    Node* l=b->members;
    Node* head =l;
    Node* temp2=l;
    if(l==NULL|| l->next==NULL){
        return l;
    }
    for(int i=0;i<b->size;i++){
        l=temp2;
    while(l->next!=NULL){
        AccountInfo temp;
        if(l->data.num>l->next->data.num){
            temp=l->data;
            l->data=l->next->data;
            l->next->data=temp;
        }
        l=l->next;
    }
    temp2=temp2->next;
    }
    return head;
}
void display(bank b){
    if(b.members==NULL){
        printf("---------------------------------------------------------\n");
        printf("No Accounts to display\n");
        printf("---------------------------------------------------------\n");


    }
    else{
        sorted(&b);
    printf("---------------------------------------------------------\n");
    printf("ACCOUNT NO.\t NAME\t ACCOUNT TYPE\t BALANCE\n");
    char use[][15]={
        "Savings","Current"
    };
    while(b.members!=NULL){
        printf("%d\t\t%s\t  %s\t %.2f\n",b.members->data.num,b.members->data.name,use[b.members->data.type],b.members->data.balance);
      b.members= b.members->next;
    }
        printf("---------------------------------------------------------\n");

    }
}
bool checkDuplicates(char* name,AccountType type,bank b){
    bool flag=true;
    for(int i=0;i<b.size;i++){
        if((strcmp(name,b.members->data.name)==0)&&(type==b.members->data.type)){
            flag=false;
        printf("---------------------------------------------------------\n");
        printf("Invalid: User Already Exists\n");
        printf("---------------------------------------------------------\n");

            break;
        }
        b.members=b.members->next;
    }
    return flag;
}
// static int x=100;
bank createAccount(bank* b){
    
    // printf("Enter Name:\n");
    
    // printf("\nEnter Account type:\nEnter 1 for Savings\nEnter 2 for Current \n");
    char type1[15];
    scanf("%s",type1);
    int type;
    if(strcmp(type1,"savings")==0) type=1;
    else if(strcmp(type1,"current")==0) type=2;
    else printf("INVALID TYPE!\n");
    

    char name1[max_name];
    scanf("%s",name1);
    float amount;
    scanf("%f",&amount);
    
   if(checkDuplicates(name1,type-1,*b)==1){
    AccountInfo* a=(AccountInfo*)malloc(sizeof(Node));
    strcpy(a->name,name1);
    a->balance=0;
    if(type==1) a->type=savings;
    else a->type=current;
    a->balance=amount;
    

    int i=0;
    for( i=0;i<b->size+1;i++){
        if(hash_accountNum[i]==0){
            hash_accountNum[i]=1;
            break;
        }
    }
    //
   
        a->num=100+i;
       
    
    b->members=append(b->members,*a);
    
    b->size++;
    printf("---------------------------------------------------------\n");
    printf("Account Created Succesfully\n");
     char use1[][15]={
        "Savings","Current"
    };
    printf("Account Number: %d\nAccount Holder: %s\nAccount Type: %s\nBalance: Rs %.2f\n",a->num,a->name,use1[a->type],a->balance);
    printf("---------------------------------------------------------\n");
    
    return*b;
   }
}

linkedlist deleteAccount(bank* b, AccountType type, char* username) {
    Node* head = b->members;
    if (head == NULL) {
        printf("---------------------------------------------------------\n");
        printf("No Accounts to delete\n");
        printf("---------------------------------------------------------\n");
        return NULL;
    } else if ((strcmp(head->data.name, username) == 0) && (head->data.type == type)) {
        b->members = head->next;
        hash_accountNum[head->data.num-100]=0;
        free(head);
        b->size--;
        printf("---------------------------------------------------------\n");
        printf("Account Deleted Successfully\n");
        printf("---------------------------------------------------------\n");
        return b->members;
    } else {
        while (head->next != NULL) {
            if ((head->next->data.type == type) && (strcmp(head->next->data.name, username) == 0)) {
                Node* current = head->next;
                head->next = current->next;
                hash_accountNum[current->data.num-100]=0;
                free(current);
                b->size--;
                printf("---------------------------------------------------------\n");
                printf("Account Deleted Successfully\n");
                printf("---------------------------------------------------------\n");
                return b->members;
            }
            head = head->next;
        }
        printf("---------------------------------------------------------\n");
        printf("User Account Does Not Exist\n");
        printf("---------------------------------------------------------\n");
        return b->members;
    }
}
void ADDMONEY(bank*b,int accountNUM,float money){
Node* head=b->members;
if(head==NULL){
    return;
}
while(head!=NULL){
    if(head->data.num==accountNUM){
        head->data.balance=head->data.balance+money;
        printf("---------------------------------------------------------\n");
        printf("Updated Balance is Rs %.2f\n",head->data.balance);
        printf("---------------------------------------------------------\n");
        return;
    }
    head=head->next;
}
printf("---------------------------------------------------------\n");
printf("INVALID Account Number: %d does not exist\n",accountNUM);
printf("---------------------------------------------------------\n");
return;
}
void lowBalanceAccounts(float x,bank*b){
    Node* head=b->members;
     printf("---------------------------------------------------------\n"); 
     printf("Low Account\n");
     int count=0;
    while(head!=NULL){
        if(head->data.balance<x){
              
            printf("Account NO.: %d, Account Holder: %s, Balance: %.2f\n",head->data.num,head->data.name,head->data.balance);
            count++;
        }
        head=head->next;
    }
    if(count==0) printf("No Account has low balance than Rs %.2f\n",x);
    printf("---------------------------------------------------------\n");
}
void WITHDRAWmoney(bank*b,int accountName,float x){
    Node*head=b->members;

    while(head!=NULL){
        if(head->data.num==accountName){
            if(head->data.balance-x>=100){
                head->data.balance=head->data.balance-x;
                printf("---------------------------------------------------------\n"); 
                printf("Updated Balance: RS %.2f\n",head->data.balance);
                printf("---------------------------------------------------------\n"); 
                return;
            }
            else{
                    printf("---------------------------------------------------------\n"); 
                    printf("Insufficient funds for transaction.\nCurrent Balance: Rs %.2f\n",head->data.balance);
                    printf("---------------------------------------------------------\n"); 
                    
                    return;
            }
        }
        head=head->next;
    }
    printf("---------------------------------------------------------\n"); 
    printf("Invalid User does not exist\n");
    printf("---------------------------------------------------------\n"); 
}

void transaction(bank*b){
    
    int n;
    scanf("%d",&n);
    float money;
    scanf("%f",&money);
    int code;
    scanf("%d",&code);
    if(code==1){
        ADDMONEY(b,n,money);
    }
    else if(code==0){
        WITHDRAWmoney(b,n,money);
    }
    else {
        printf("INVALID CODE!\n");
    }

}
int main(){
    int flag=0;

   bank b={
    .members=NULL,
    .size=0
   };
   start:


flag=0;
char operation[15];
scanf("%s",operation);
if(strcmp(operation,"CREATE")==0){
    createAccount(&b);
}
else if(strcmp(operation,"DELETE")==0){
 
   
    char type[20];
  
    scanf("%s",type);
    char name[max_name];
    scanf("%s",name);
    if(strcmp(type,"savings")==0) deleteAccount(&b,savings,name);
    else if(strcmp(type,"current")==0)deleteAccount(&b,current,name);
    
}
else if(strcmp(operation,"DISPLAY")==0){
    display(b);
}
else if(strcmp(operation,"TRANSACTION")==0){
   
    transaction(&b);
    
}
else if(strcmp(operation,"LOWBALANCE")==0){

lowBalanceAccounts(100,&b);
}
else if(strcmp(operation,"EXIT")==0){
    flag=1;
    return 0;
}
    goto start;
    return 0;
}