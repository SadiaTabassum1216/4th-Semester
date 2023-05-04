#include<bits/stdc++.h>
using namespace std;
int n; //number of child;

ofstream output("result.txt");

struct node
{
    int currentNode;
    node *parent,*next;
    string *english,*bangla;
    bool isLeaf;
    node **point;
} ;
node *root,*firstLeaf;

node* createNode()
{
    node *newNode=new node();

    newNode->point = new node *[n+1];
    newNode->english=new string[n];
    newNode->bangla=new string[n];

    newNode->currentNode = 0;
    newNode->parent = NULL;
    newNode->next = NULL;
    newNode->isLeaf = true;
    return newNode;
}


node *findLeaf(node *tempRoot,string english)
{

    while(tempRoot->isLeaf==false)
    {
        int i;
        for(i=0; i<tempRoot->currentNode; i++)
            if(english<tempRoot->english[i])
                break;
        tempRoot = tempRoot->point[i];
    }

    return tempRoot;
}

void insertValueAndPoint(node *parent,string value,node *right)
{
    int i=parent->currentNode-1;
    for(; i>=0; i--)
    {
        if(parent->english[i]<=value)
            break;
        else
        {
            parent->english[i+1] = parent->english[i];
            parent->point[i+2] = parent->point[i+1];
        }
    }
    parent->english[i+1] = value;
    parent->point[i+2] = right;
    parent->currentNode++;
}

void insertMiddle(node *parent,string value,node *left,node *right)
{
    if(parent==NULL)
    {
        parent = createNode();
        parent->english[0] = value;
        parent->point[0] = left;
        parent->point[1] = right;
        parent->currentNode++;
        parent->isLeaf = false;
        root = parent;
        left->parent = parent;
        right->parent = parent;
        return;
    }
    right->parent = parent;
    insertValueAndPoint(parent,value,right);

    if(parent->currentNode==n)
    {
        node *splitNode = createNode();
        splitNode->isLeaf = false;
        int j=0;
        for(int i=parent->currentNode-(n-1)/2; i<n; i++)
        {
            splitNode->english[j] = parent->english[i];
            if(j==0)
            {
                splitNode->point[0] = parent->point[i];
                splitNode->point[0]->parent = splitNode;
            }
            splitNode->point[j+1] = parent->point[i+1];
            splitNode->point[j+1]->parent = splitNode;
            j++;
        }
        parent->currentNode-=(n-1)/2+1;
        splitNode->currentNode = (n-1)/2;
        insertMiddle(parent->parent,parent->english[parent->currentNode],parent,splitNode);
    }

}


void insertLeaf(string english,string bangla)
{
    node *leaf = findLeaf(root,english);
    int i= leaf->currentNode-1;
    if(i>-1)
    {
        for(; i>=0; i--)
        {
            if(english<leaf->english[i])
            {
                leaf->english[i+1] = leaf->english[i];
                leaf->bangla[i+1] = leaf->bangla[i];
            }
            else
                break;
        }
    }
    leaf->english[i+1] = english;
    leaf->bangla[i+1] = bangla;
    leaf->currentNode++;

    if(leaf->currentNode==n)
    {
        node *splitNode = createNode();
        int j=0;
        for(int i=leaf->currentNode-n/2; i<n; i++)
        {
            splitNode->english[j] = leaf->english[i];
            splitNode->bangla[j] = leaf->bangla[i];
            j++;
        }
        leaf->currentNode-=n/2;
        splitNode->currentNode = n/2;
        splitNode->next = leaf->next;
        leaf->next = splitNode;
        insertMiddle(leaf->parent,splitNode->english[0],leaf,splitNode);
    }
}

int main(void)
{
    cout << "Number of Child: ";
    cin >> n;

    root = createNode();
    node *leaf;
    int i=0;
    string english,bangla,searchEnglish;

    cout<<"Enter text to search: ";
    cin>>searchEnglish;

    freopen("words.txt","r",stdin);

    while(cin >> english)
    {
        cin >> bangla;
        insertLeaf(english,bangla);
    }

        leaf= findLeaf(root,searchEnglish);
        for(i=0; i<leaf->currentNode; i++){
            if(searchEnglish==leaf->english[i])
                break;
        }
        if(i==leaf->currentNode)
            cout<<"Not found.\n";
        else{
            output<<searchEnglish<<" = "<<leaf->bangla[i]<<endl;
            cout<<searchEnglish<<" = "<<leaf->bangla[i]<<endl;
        }

}
