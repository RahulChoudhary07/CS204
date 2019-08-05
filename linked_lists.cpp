#include <iostream> 
using namespace std;

struct Node* head = NULL;

struct Node  
{  
    long long int y; 
    long long int x;  
    Node *next;  
}; 

void AddFirst(long long int x , long long int y) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   
    new_node->x  = x; 
    new_node->y  = y; 
   
    new_node->next = (head); 
   
    (head)    = new_node; 
} 

void DelFirst() 
{ 
    if (head == NULL) 
        {cout<<"empty linked list";return ;} 

    Node* temp = head; 
    head = head->next; 
  
    delete(temp); 

} 

void Del( long long int x,long long int y) 
{ 
   
   if (head == NULL) 
      {cout<<"empty linked list";return ;} 
  
    
   struct Node* temp = head; 
  struct Node* prev = NULL;
     
    if ((head->x)==x&&(head->y)==y) 
    { 
        head = temp->next;    
        free(temp);              
        return; 
    } 
  
  
    for (long long int i=0; temp!=NULL; i++) 
         {
             if(temp->x==x&&temp->y==y)
             {
                 break;
             }
             prev = temp;
             temp = temp->next; 
         }

    if (temp == NULL ) 
      {cout<<"-1"<<endl;return ;} 
  
    
    struct Node *next = temp->next; 
  
    
    free(temp);  
  
    prev->next = next; 
    cout<<"1"<<endl;return ; 
} 

void Search(float d) 
{ 
    struct Node* temp = head; 
    while (temp!= NULL) { 
        if((temp->x)*(temp->x)+(temp->y)*(temp->y)<=d*d)
        {
            cout<<"("<<(temp->x)<<","<<(temp->y)<<")";
        }
        temp=temp->next;
    } 
} 

bool Search(long long int x,long long int y) 
{ 
    struct Node* temp = head; 
    while (temp!= NULL) { 
        if((temp->x)==x&&(temp->y)==y)
        {
            return true;
        }
        temp=temp->next;
    } 
    return false;
}

long long int Length() 
{ 
    struct Node* temp = head; 
    long long int l=0;
    while (temp!= NULL) { 
        l++;
        temp=temp->next;
    } 
    return l;
}
 int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int a;
        cin>>a;
        if(a==1)
        {
            long long int x,y;
            cin>>x>>y;
            AddFirst(x,y);
        }
        else if(a==2){DelFirst();}
        else if(a==3)
        {
            long long int x,y;
            cin>>x>>y;
            Del(x,y);
        }
        else if(a==4)
        {
            long long int d;
            cin>>d;
            Search(d);
            cout<<endl;
            
        }
        else if(a==5)
        {
            long long int x,y;
            cin>>x>>y;
            cout<<Search(x,y)<<endl;
        }
        else if(a==6)
        {
            cout<<Length()<<endl;
        }
    }
}
    
