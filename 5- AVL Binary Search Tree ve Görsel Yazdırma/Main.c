// Yunus Emre Ay / 21100011016 / Tel:05516524768 / E-posta:TR.yunus.emre.ay@gmail.com / Odev5 \\

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

    int yukseklik;
    int avl;
    struct node *next;

};

struct node *root=NULL;
struct node *q;
struct node *elemanlar[50];

struct node* New_Node(int data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->next=NULL;


    if(root==NULL)
    {
        root=new_node;
    }

    return new_node;
}

struct node* Recursive_Ekleme(struct node *root,int data)
{
    if(root==NULL)
    {
        return New_Node(data);
    }
    else
    {
        if(data < root->data)
        {
            root->left=Recursive_Ekleme(root->left,data);
        }
        else
        {
            root->right=Recursive_Ekleme(root->right,data);
        }
    }
}

int min(struct node* root)
{
    while(root->left != NULL)
    {
        root=root->left;
    }
    return root->data;
}

int max(struct node* root)
{
    while(root->right != NULL)
    {
        root=root->right;
    }
    return root->data;
}

struct node* Silme(struct node* root, int data)
{
    if(root==NULL)
    {
        printf("Agacin ici zaten bos\n");
        return;
    }

    if(root->data==data)
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left != NULL)
        {
            root->data= max(root->left);
            root->left = Silme(root->left,max(root->left));
            return root;
        }
        root->data= min(root->right);
        root->right = Silme(root->right,min(root->right));
        return root;
    }

    if(data < root->data)
    {
        root->left=Silme(root->left,data);
    }
    else
    {
        root->right=Silme(root->right,data);
    }
};

void Node_yukseklik(struct node* root)
{
    int sol=0,sag=0;
    if(root != NULL)
    {
        Node_yukseklik(root->left);
        Node_yukseklik(root->right);
        if(root->left==NULL)
            sol=-1;
        else
            sol=root->left->yukseklik;
        if(root->right==NULL)
            sag=-1;
        else
            sag=root->right->yukseklik;
        if(sol>=sag)
            root->yukseklik=sol+1;
        else
            root->yukseklik=sag+1;
    }
}

void Node_Avl(struct node* root)
{
    int sol=0,sag=0;
    if(root!=NULL)
    {
        Node_Avl(root->left);
        Node_Avl(root->right);
        if(root->left==NULL)
            sol=-1;
        else
            sol=root->left->yukseklik;
        if(root->right==NULL)
            sag=-1;
        else
            sag=root->right->yukseklik;
        root->avl=sol-sag;
    }
}


int Gecici_yukseklik = -1;

void Siniflandirma(struct node* root)
{
    Gecici_yukseklik++;
    if(root!=NULL)
    {
        if(elemanlar[Gecici_yukseklik]==NULL)
        {
            elemanlar[Gecici_yukseklik]=root;
        }
        else
        {
            q=elemanlar[Gecici_yukseklik];
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=root;
        }
        Siniflandirma(root->left);
        Siniflandirma(root->right);
    }
    Gecici_yukseklik--;
};


void Listeleme()
{
    int i,j,k,sayac;
    int cocuk_bulma[50],cocuk;
    int x=0;
    while(elemanlar[x]!=NULL)
    {
        x++;
    }
    printf("************************************************************\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<50;j++)
        {
            cocuk_bulma[j]=2;
        }
        cocuk=0;
        k=0;
        sayac=0;
        q=elemanlar[i];
        while(q!=NULL)
        {
            if((q->data)<10)
                printf("        %d ",q->data);
            else
                printf("        %d",q->data);
            sayac++;
            if(q->left==NULL)
                cocuk_bulma[cocuk]=0;
            else
                cocuk_bulma[cocuk]=1;
            cocuk++;
            if(q->right==NULL)
                cocuk_bulma[cocuk]=0;
            else
                cocuk_bulma[cocuk]=1;
            cocuk++;
            q=q->next;
        }
        printf("\n");
        for(j=0;j<sayac;j++)
        {
            if(j==0)
            {
                printf("       /  \\");
            }
            else
            {
                printf("      /  \\");
            }
        }
        printf("\n");
        for(j=0;j<sayac;j++)
        {
            if(j==0)
            {
                q=elemanlar[i+1];
                if(cocuk_bulma[k]==0)
                {
                    printf("     --");
                }
                else if(cocuk_bulma[k]==1)
                {
                    if((q->data)<10)
                        printf("      %d",q->data);
                    else
                        printf("     %d",q->data);
                    q=q->next;
                }
                k++;

                if(cocuk_bulma[k]==0)
                {
                    printf("    --");
                }
                else if(cocuk_bulma[k]==1)
                {
                    if((q->data)<10)
                        printf("    %d ",q->data);
                    else
                        printf("    %d",q->data);
                    q=q->next;
                }
                k++;
            }
            else
            {
                if(cocuk_bulma[k]==0)
                {
                    printf("  --");
                }
                else if(cocuk_bulma[k]==1)
                {
                    if((q->data)<10)
                        printf("   %d",q->data);
                    else
                        printf("  %d",q->data);
                    q=q->next;
                }
                k++;

                if(cocuk_bulma[k]==0)
                {
                    printf("    --");
                }
                else if(cocuk_bulma[k]==1)
                {
                    printf("    %d",q->data);
                    q=q->next;
                }
                k++;
            }
        }
        printf("\n");
        printf("------------------------------------------------------------\n");


    }
    printf("************************************************************\n");
}

void Next_null(struct node* root)
{
    if(root!=NULL)
    {
        Next_null(root->left);
        root->next=NULL;
        Next_null(root->right);
    }
}


int kontrol=0;
void AVL_kontrol(struct node* root,struct node* q)
{
    if((root!=NULL)&&(kontrol==0))
    {
        AVL_kontrol(root->left,root);
        AVL_kontrol(root->right,root);
        if((abs(root->avl)>1)&&(kontrol==0))
        {
            kontrol=1;
            if((root->avl)>=0) //AVL degeri pozitifse
            {
                if((root->left->avl)>=0) // LL
                {
                    LL(root,q);
                }
                else // LR
                {
                    LR(root,q);
                    LL(root,q);
                }
            }
            else //AVL degeri negatifse
            {
                if((root->right->avl)>=0) // RL
                {
                    RL(root,q);
                    RR(root,q);
                }
                else // RR
                {
                    RR(root,q);
                }
            }
        }
    }
}

void LL(struct node* root2,struct node* q)
{
    if(q!=NULL)
    {
        q->left=root2->left;
        root2->left=q->left->right;
        q->left->right=root2;
    }
    else
    {
        q=root2->left;
        root2->left=root2->left->right;
        q->right=root2;
        root=q;
    }

}

void RR(struct node* root2,struct node* q)
{
    if(q!=NULL)
    {
        q->right=root2->right;
        root2->right=q->right->left;
        q->right->left=root2;
    }
    else
    {
        q=root2->right;
        root2->right=root2->right->left;
        q->left=root2;
        root=q;
    }

}

void LR(struct node* root,struct node* q)
{
    root->left->right->left=root->left;
    root->left=root->left->right;
    root->left->left->right=NULL;
    //LL(root,q);
}

void RL(struct node* root,struct node* q)
{
    root->right->left->right=root->right;
    root->right=root->right->left;
    root->right->right->left=NULL;
    //RR(root,q);
}

int main()
{
    int data,tercih,i;
    while(0==0)
    {
        printf("--------------------------------------------------\n");
        printf("1)Agaca Eleman Ekleme.\n2)Agactan Eleman Silme.\n3)Elemanlari Gorsel Olarak Listeleme.\n4)Cikis.");
        printf("\n\n---> ");
        scanf("%d",&tercih);
        switch(tercih)
        {
            case 1:
                printf("Data Giriniz --> ");
                scanf("%d",&data);
                Recursive_Ekleme(root,data);
                Node_yukseklik(root);
                Node_Avl(root);
                kontrol=0;
                AVL_kontrol(root,NULL);
                break;
            case 2:
                printf("Silinecek Elamanin Datasini Giriniz --> ");
                scanf("%d",&data);
                Silme(root,data);
                Node_yukseklik(root);
                Node_Avl(root);
                kontrol=0;
                AVL_kontrol(root,NULL);
                break;
            case 3:

                Next_null(root);
                for(i=0;i<50;i++)
                {
                    elemanlar[i]=NULL;
                }
                Gecici_yukseklik = -1;
                Siniflandirma(root);
                Listeleme();
                break;
            case 4:
                return 0;

        }
    }
    return 0;
}
