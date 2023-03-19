// Yunus Emre Ay / E-posta:TR.yunus.emre.ay@gmail.com

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;
struct node *q;
struct node *temp;

int eleman_sayisi = 0;

struct node* New_Node(int data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    eleman_sayisi++;

    if(root==NULL)
    {
        root=new_node;
    }

    return new_node;
}


void Dongu_Ekleme(int data)
{
    int kontrol;
    if(root == NULL)
    {
        New_Node(data);

    }
    else
    {
        q = root;
        while(0==0)
        {
            if(q==NULL)
            {
                if(kontrol==0)
                {
                    temp->left=New_Node(data);
                }
                else
                {
                    temp->right=New_Node(data);
                }
                break;
            }
            if(data < q->data)
            {
                kontrol=0;
                temp=q;
                q=q->left;
            }
            else
            {
                kontrol=1;
                temp=q;
                q=q->right;
            }
        }
    }
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



void Listeleme(struct node* root)
{
    if(root!=NULL)
    {
        Listeleme(root->left);
        printf("%d ",root->data);
        Listeleme(root->right);
    }
};

struct node* Arama(struct node* root, int data)
{
    if(root==NULL)
    {
        printf("***Eleman Bulunamadi***\n");
    }
    else if(root->data==data)
    {
        printf("***Eleman Bulundu***\n");
    }
    else
    {
        if(data < root->data)
        {
            Arama(root->left,data);
        }
        else
        {
            Arama(root->right,data);
        }
    }
};

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
            eleman_sayisi--;
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



int Gecici_yukseklik = -1,Gercek_yukseklik=0,Gercek_yukseklik_indis,sayac=0,yukseklikler[50]={0};

void Yukseklik(struct node* root)
{
    Gecici_yukseklik++;
    if(root!=NULL)
    {
        if ((root->left==NULL)||(root->right==NULL))
        {
            yukseklikler[sayac]=Gecici_yukseklik;
            sayac++;
        }
        Yukseklik(root->left);
        Yukseklik(root->right);
    }
    Gecici_yukseklik--;
};

int Yukseklik_Belirleme()
{
    int i;
    Gercek_yukseklik=0;
    for(i=0;i<50;i++)
    {
        if(yukseklikler[i]>=Gercek_yukseklik)
        {
            Gercek_yukseklik=yukseklikler[i];
            Gercek_yukseklik_indis = i;
        }
    }
    return Gercek_yukseklik;
}

int Full_Binary_Tree()
{
    int height,i,sonuc=1;
    Gecici_yukseklik = -1;
    sayac=0;
    for(i=0;i<50;i++)
    {
        yukseklikler[i]=0;
    }
    Yukseklik(root);
    height=Yukseklik_Belirleme();

    for(i=0;i<height+1;i++)
    {
        sonuc*=2;
    }
    sonuc--;


    if (eleman_sayisi==sonuc)
        return 1;
    return 0;
}

int Complete_Binary_Tree()
{
    int height,i;
    Gecici_yukseklik = -1;
    Gercek_yukseklik_indis=0;
    sayac=0;
    for(i=0;i<50;i++)
    {
        yukseklikler[i]=0;
    }
    Yukseklik(root);
    height=Yukseklik_Belirleme();

    for(i=0;i<=Gercek_yukseklik_indis;i++)
    {
        if(yukseklikler[i]!=height)
            return 0;
    }
    return 1;

}




int main()
{
    int data,tercih,i;
    while(0==0)
    {
        printf("--------------------------------------------------\n");
        printf("1)Dongu Kullanarak Agaca Eleman Ekleme.\n2)Recursive Kullanarak Agaca Eleman Ekleme.\n3)inOrder Siralama.\n4)Eleman Arama.\n5)Eleman Silme.\n6)Yukseklik Hesaplama.\n7)Agac Full Binary Tree mi?\n8)Agac Complete Binary Tree mi?\n9)Cikis.");
        printf("\n\n---> ");
        scanf("%d",&tercih);
        switch(tercih)
        {
            case 1:
                printf("Data Giriniz --> ");
                scanf("%d",&data);
                Dongu_Ekleme(data);
                break;
            case 2:
                printf("Data Giriniz --> ");
                scanf("%d",&data);
                Recursive_Ekleme(root,data);
                break;
            case 3:
                Listeleme(root);
                printf("\n");
                break;
            case 4:
                printf("Aranacak Elamanin Datasini Giriniz --> ");
                scanf("%d",&data);
                Arama(root,data);
                break;
            case 5:
                printf("Silinecek Elamanin Datasini Giriniz --> ");
                scanf("%d",&data);
                Silme(root,data);
                break;
            case 6:
                Gecici_yukseklik = -1;
                sayac=0;
                for(i=0;i<50;i++)
                {
                    yukseklikler[i]=0;
                }
                Yukseklik(root);
                printf("Agacin Yuksekligi: %d \n",Yukseklik_Belirleme());
                break;
            case 7:
                if(Full_Binary_Tree())
                {
                    printf("Agac Yapisi: Full Binary Tree\n");
                }
                else
                {
                    printf("Agac Yapisi: Full Binary Tree Degil\n");
                }
                break;
            case 8:
                if(Complete_Binary_Tree())
                    printf("Agac Yapisi: Complete Binary Tree\n");
                else
                    printf("Agac Yapisi: Complete Binary Tree Degil\n");
                break;
            case 9:
                return 0;

        }
    }
    return 0;
}
