#include <stdio.h>
#include <stdlib.h>

struct tree     //1 Binary Tree yi uygulamak için bir veri yapısı
{
    int data;
    struct tree *right;
    struct tree *left;
};
struct BST
{
    int index;
    struct BST *left;
    struct BST *right;
};

void insertleftBST(struct BST *node,int index);
void insertrightBST(struct BST *node,int index);
void insertBST(struct BST *rootBST,int index);
void inOrderBST(struct BST *node);
void postOrderBST(struct BST *node);
void preOrderBST(struct BST *node);
struct BST * maxBST(struct BST *node);
struct BST * minBST(struct BST *node);
struct BST * traversalBST(struct BST *node,int index);
void deletionBST(struct BST *node,int index);
void printBST(struct BST *node,int grade);


void insertleftBT(struct tree *node,int data);
void insertrightBT(struct tree *node,int data);
void preOrder(struct tree *node);
void inOrder(struct tree *node);
void postOrder(struct tree *node);

int StudentList[15][3]=     
{
    {0,18060311,40},
    {1,20060045,50},
    {2,19061091,75},
    {3,20060134,90},
    {4,20060678,40},
    {5,18061086,75},
    {6,20060032,50},
    {7,20060067,60},
    {8,19060456,60},
    {9,18060245,75},
    {10,20060110,40},
    {11,20060234,90},
    {12,20060141,60},
    {13,20060011,50},
    {14,20060012,60},
};
int main(void)
{
    int i;
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));         // Birinci bölüm
    root->left = root->right = NULL;
    root->data = 3;

    insertrightBT(root,21);
    insertrightBT(root,11);
    insertleftBT(root,2);
    insertleftBT(root,15);
    insertleftBT(root,99);

    inOrder(root);
    printf("\n--------------------------------------------------------------------\n");
    struct BST *rootBST = (struct BST *)malloc(sizeof(struct BST));         // İkinci bölüm
    rootBST->index = 0;
    rootBST->left = rootBST->right = NULL;

    for(i=1;i<15;i++)
    {
        insertBST(rootBST,i);
    }

    inOrderBST(rootBST);
    printf("\n--------------------------------------------------------------------\n");
    printBST(rootBST,89);
    printf("\n--------------------------------------------------------------------\n");
    deletionBST(rootBST,2);
    deletionBST(rootBST,6);
    deletionBST(rootBST,10);
    printf("\n--------------------------------------------------------------------\n");
    inOrderBST(rootBST);
}
void insertrightBST(struct BST *node,int index)     //BST ye sagdan ekler
{
    if(node->right == NULL)
    {
        node->right = (struct BST *)malloc(sizeof(struct BST));
        node->right->right = node->right->left = NULL;
        node->right->index = index;
    }
    else if(node->right != NULL)
    {
        insertBST(node->right,index);
    }
}
void insertleftBST(struct BST *node,int index)         //BST ye soldan ekler
{
    if(node->left == NULL)
    {
        node->left = (struct BST *)malloc(sizeof(struct BST));
        node->left->left = node->left->right = NULL;
        node->left->index = index;
    }
    else if(node->left != NULL)
    {
        insertBST(node->left,index);
    }
}
void insertBST(struct BST *root,int index)      //BST ye eleman ekler
{
    if(StudentList[root->index][2] > StudentList[index][2])
    {
        insertleftBST(root,index);
    }
    else if(StudentList[root->index][2] == StudentList[index][2] && StudentList[root->index][1] < StudentList[index][1])
    {
        insertleftBST(root,index);
    }
    else if(StudentList[root->index][2] == StudentList[index][2] && StudentList[root->index][1] > StudentList[index][1])
    {
        insertrightBST(root,index);
    }
    else if(StudentList[root->index][2] < StudentList[index][2])
    {
        insertrightBST(root,index);
    }
    else
    {
        printf("Yeter artik biktim usandim");
    }
}
void deletionBST(struct BST *node,int index)        //Agacı silinme kuralına gore düzenleyebilir fakat yerine geçen  indisin eski adresini silemez  -1 e esitler ((((
{
    struct BST *temp = NULL;
    temp = traversalBST(node,index);        //Silinmek istenen indexin adresi
    if(temp->right == NULL && temp->left == NULL)
    {
        temp->index = -1;
    }
    else if(temp->right != NULL && temp->left == NULL)
    {
        temp->index = minBST(temp->right)->index;
        minBST(temp->right)->index = -1;
    }
    else if(temp->right == NULL && temp->left != NULL)
    {
        temp->index = maxBST(temp->left)->index;
        maxBST(temp->left)->index = -1;
    }
    else if(temp->right != NULL && temp->left != NULL)
    {
        temp->index = minBST(temp->right)->index;
        minBST(temp->right)->index = -1;
    }
}
void preOrder(struct tree *node)                    //4 Pre-order DFS yaklaşımı ile ağacın bütün elemanlarını ekrana yazdıran bir işlev.
{
    if(node != NULL)
    {
        printf("%d\t",node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}
void inOrder(struct tree *node)                     //5 In-order DFS yaklaşımı ile ağacın bütün elemanlarını ekrana yazdıran bir işlev.
{
    if(node != NULL)
    {
        inOrder(node->left);
        printf("%d\t",node->data);
        inOrder(node->right);
    }
}
void postOrder(struct tree *node)                   //6 Post-order DFS yaklaşımı ile ağacın bütün elemanlarını ekrana yazdıran bir işlev.
{
    if(node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d\t",node->data);
    }
}
void BFS(struct tree *node,int index)               //7 BFS yaklaşımı ile ağacın bütün elemanlarını ekrana yazdıran bir işlev.
{
}
void insertrightBT(struct tree *node,int data)      //2 verilen kurallara göre ağaca sağdan ekleme yapan bir işlev.
{
    if(node->right == NULL)
    {
        node->right = (struct tree *)malloc(sizeof(struct tree));
        node->right->right = node->right->left = NULL;
        node->right->data = data;
    }
    else if(node->right != NULL)
    {
        struct tree *tempright = NULL;
        tempright = node->right;
        struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
        temp->data = data;
        temp->left = NULL;
        node->right = temp;
        temp->right = tempright;
    }
}
void insertleftBT(struct tree *node,int data)       //3 verilen kurallara göre ağaca soldan ekleme yapan bir işlev.
{
    if(node->left == NULL)
    {
        node->left = (struct tree *)malloc(sizeof(struct tree));
        node->left->right = node->left->left = NULL;
        node->left->data = data;
    }
    else if(node->left != NULL)
    {
        struct tree *templeft = NULL;
        templeft = node->left;
        struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
        temp->data = data;
        temp->right = NULL;
        node->left = temp;
        temp->left = templeft;
    }
}
void inOrderBST(struct BST *node)                   // inOrder şeklinde verilen kurallara göre binary tree INDEX tablosunu yazdırır.
{
    if(node != NULL)
    {
        inOrderBST(node->right);
        printf("%d\t",node->index);
        inOrderBST(node->left);
    }
}
void postOrderBST(struct BST *node)     //postorder yaklasimi ile agaci yazdirir
{
    if(node != NULL)
    {
        postOrderBST(node->left);
        postOrderBST(node->right);
        printf("%d\t",node->index);
    }
}
void preOrderBST(struct BST *node)      //preorder yaklasimi ile agaci yazdirir
{
    if(node != NULL)
    {
        printf("%d\t",node->index);
        preOrderBST(node->left);
        preOrderBST(node->right);
    }
}
struct BST * maxBST(struct BST *node)       //agactaki en buyuk degeri bulur
{
    while(node->right != NULL)
    {
        node = node->right;
    }
    return node;
}
struct BST * minBST(struct BST *node)       //agactaki en kücük degeri bulur
{
    while(node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
struct BST * traversalBST(struct BST *node,int index)  // istenilen indeksin adresini bulur
{
    if(node != NULL)
    {
        if(node->index == index)
        {
            return node;
        }
        else 
        {
            if(StudentList[node->index][2] < StudentList[index][2])
            {
                traversalBST(node->right,index);
            }
            else if(StudentList[node->index][2] > StudentList[index][2])
            {
                traversalBST(node->left,index);
            }
            else if(StudentList[node->index][2] == StudentList[index][2] && StudentList[node->index][1] > StudentList[index][1])
            {
                traversalBST(node->right,index);
            }
            else if(StudentList[node->index][2] == StudentList[index][2] && StudentList[node->index][1] < StudentList[index][1])
            {
                traversalBST(node->left,index);
            }
            else
            {
                traversalBST(node->left,index);
                traversalBST(node->right,index);
            }
        }
    }
}
void printBST(struct BST *node,int grade)       //istenilen degerden yuksek notları indeks sırasına gore yazdırır
{
    if(node != NULL)
    {
        printBST(node->right,grade);
        if(StudentList[node->index][2] > grade)
        {
            printf("%d\t",node->index);
        }
        printBST(node->left,grade);
    }
}
