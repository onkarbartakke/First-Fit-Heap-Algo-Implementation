#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;
unordered_map<char,int>mp;
//NAME  - BARTAKKE ONKAR SUHAS
// BT19CSE012
// CPL- ASSIGNMENT 3, 
// Imlementation of 1st fit algo
//GLOBALS

int I1=1;



//Class for Memory Node
class memory_Node
{
    public:
        int tag;
        vector<pair<char,int>>allocated_ids;
        int Total_space;
        int allocated_space;
        int free_space;
        int count;
        memory_Node *next;
        memory_Node *prev;
};



memory_Node* create_free(memory_Node *H, int size)
{
    memory_Node *p;
    p=new memory_Node;
    p->tag=I1;
    (I1)++;
    p->Total_space=size;
    p->allocated_space=0;
    p->free_space=size;
    p->count=0;
    p->next=NULL;
    p->prev=NULL;

    if(H==NULL)
    {
       H=p; 
    }
    else
    {
        memory_Node *t=H;
        while(t->next!=NULL)
        {
            t=t->next;
        }

        t->next=p;
        p->prev=t;
    }

    cout<<"\nBlock with tag id "<<p->tag<<" created for which :- \n";
    cout<<"\nTotal space - "<<p->Total_space;
    cout<<"\nAllocated space - "<<p->allocated_space;
    cout<<"\nFree Space - "<<p->free_space;
    cout<<"\n\n";

    return H;
}

bool Allocate(memory_Node *H, int size, char c)
{
    memory_Node *p=H;

    while(p!=NULL)
    {
        if(p->free_space>=size)
        {
            break;
        }
        p=p->next;
    }

    if(p==NULL)
    {
        cout<<"\nSorry Non of the blocks existing in Current Memory can allocate this much size \n";
        return false;
    }
    pair<char,int>pr;
    pr.first=c;
    mp[c]=p->tag;
    
    pr.second=size;

    (p->allocated_ids).push_back(pr);

    cout<<"\nMemory Successfully allocated in the Block with tag-id "<<p->tag<<"\n";
    cout<<"After Allocation :- \n";
    cout<<"Freespace = "<<p->free_space<<" - "<<size<<" = "<<(p->free_space)-size;
    cout<<"\nAllocated space = "<<p->allocated_space<<" + "<<size<<" = "<<(p->allocated_space)+size;
    (p->free_space)-=size;
    (p->allocated_space)+=size;
    cout<<"\n\n";
    (p->count)++;
    return true;
}


void Delete(memory_Node *H, char c)
{
    //int n=Hash[id];
    int n=mp[c];
    if(n<=0)
    {
        cout<<"\nId doesn't exits to be deleted\n";
        return;
    }
    int i=1;
    memory_Node *p=H;
    while(i<n)
    {
        p=p->next;
        i++;
    }

    for(i=0;i<(p->allocated_ids).size();i++)
    {
        if(c==p->allocated_ids[i].first)
        {
            p->allocated_ids[i].first='\0';
            //Hash[id]=-1;
            cout<<"\nMemory of size "<<p->allocated_ids[i].second<<" by pointer "<<c<<" Deleted from Block with Tag-id "<<n;
            cout<<"\nAfter Deletion:- \n";
            cout<<"Free space = "<<p->free_space<<" + "<<p->allocated_ids[i].second<<" = "<< p->free_space + p->allocated_ids[i].second;
            cout<<"\nAllocated space = "<<p->allocated_space<<" - "<<p->allocated_ids[i].second<<" = "<< p->allocated_space - p->allocated_ids[i].second;
            p->allocated_space -= p->allocated_ids[i].second;
            p->free_space += p->allocated_ids[i].second;
            p->allocated_ids[i].second=0;
            p->allocated_ids[i].first='\0';
            cout<<"\n\n";
            (p->count)--;
           return;
        }
    }
}


void Display(memory_Node* H, vector<int>Blocks , vector<int>process_sizes)
{
    int i;
    cout<<"\nMemory Blocks are :- \n";
    cout<<"Tag-id \t Block-size\n";
    for(i=0;i<Blocks.size();i++)
    {
        cout<<i+1<<" \t "<<Blocks[i]<<"\n";
    }

    cout<<"\n\n";
    

    cout<<"Memory Stats :- \n";
    cout<<"\n\n";
    while(H)
    {
        cout<<"\nBlock Tag id - "<<H->tag<<"\n";
        cout<<"Free Space - "<<H->free_space<<"\n";
        cout<<"Allocate Space - "<<H->allocated_space<<"\n";
        cout<<"Total Space - "<<H->Total_space<<"\n";
        cout<<"Number of Process blocks(POINTERS) it contains : "<<H->count;
        if(H->count>0)
        {
            cout<<"\nProcess Blocks are :-\n";
            for(i=0;i< H->allocated_ids.size();i++)
            {
                if(H->allocated_ids[i].first!='\0')
                cout<<"Pointer name :- "<<H->allocated_ids[i].first<<" | Process size(memory occupied) "<<H->allocated_ids[i].second<<"\n";
            }
        }
        cout<<"\n";
        H=H->next;
    }
}


int main()
{
    int n,i,j;
    cout<<"Enter the Number of FREE Memory Blocks in the Heap : ";
    cin>>n;

    vector<int>Blocks(n);
    memory_Node *Head=NULL;
    cout<<"\nEnter the sizes of this "<<n<<" Blocks : \n";
    for(i=0;i<n;i++)
    {
        cin>>Blocks[i];
        Head=create_free(Head,Blocks[i]);
    }

    cout<<"\nMemory is Ready for Allocation and Deletion process \n\n";
    vector<int>process_sizes;
    int flag=1;
    while(flag)
    {
        cout<<"Select from Following :- \n";
        cout<<"1)Allocate \n";
        cout<<"2)Delete \n";
        cout<<"3)Display Memory stats \n";
        cout<<"4)Exit the program\n\n";

        cin>>i;
        int sp;
        int id;
        char c;
        switch(i)
        {
            case 1:
                cout<<"\nEnter the space to be allocated : ";
                cin>>sp;
               
                cout<<"\nEnter the name of pointer which will point to that space : ";
                cin>>c;
                if(Allocate(Head,sp,c))
                {
                    cout<<"\nAllocated-memory with pointer  "<<c<<"\n\n";
                    process_sizes.push_back(sp);
                }
                break;
            case 2:
                cout<<"\nEnter the pointer name for Deletion of allocated Process memory : ";
                cin>>c;
                Delete(Head,c);
                break;
            case 3:
                Display(Head,Blocks,process_sizes);
                break;
            default :
                flag=0;
                break;

        }
    }
}