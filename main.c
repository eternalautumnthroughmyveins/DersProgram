#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// D���m yap�s�n� tan�ml�yoruz.
typedef struct Node {
    char courseName[50]; // Ders ad�
    char instructor[50]; // E�itmen ad�
    int credits;  // Kredi say�s�
    char day[20];  // G�n bilgisi (�rne�in "Pazartesi")
    char time[10]; // Saat bilgisi (�rne�in "10:00")
    struct Node* left; // Sol alt d���m i�aret�isi
    struct Node* right; // Sa� alt d���m i�aret�isi
} Node;

// Yeni d���m olu�turma fonksiyonu.
Node* createNode(const char *courseName, const char *instructor, int credits, const char *day, const char *time) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->courseName, courseName);
    strcpy(newNode->instructor, instructor);

    newNode->credits = credits;

    strcpy(newNode->day, day);
    strcpy(newNode->time, time);

   newNode->left = NULL;
   newNode->right = NULL;

   return newNode;
}

// A�a�ta dersi ekleyecek olan fonksiyon.
Node* insert(Node* root, const char *courseName, const char *instructor,
             int credits, const char *day,const 	char *time) {

     if (root == NULL) {
         return createNode(courseName,instructor ,credits , day , time);
     }

     if (strcmp(courseName , root->courseName) < 0)
         root -> left = insert(root -> left , courseName,instructor ,credits , day , time);
     else
         root -> right = insert(root -> right , courseName,instructor ,credits , day,time);

     return root;
}

// Inorder Traversal: Soldan ba�layarak k�k� ve sonra sa� �ocu�u ziyaret ederiz.
void inorderTraversal(Node* node) {
   if (node != NULL) {
       inorderTraversal(node -> left );
       printf("Ders Ad�: %s | E�itmen: %s | Kredi: %d | G�n: %s | Saat: %s\n", node -> courseName,
              node -> instructor,node -> credits,node -> day,node -> time );
      inorderTraversal(node -> right );
   }
}

// A�a�taki t�m kaynaklar� serbest b�rakmak i�indir.
void freeTree(Node* node) {
   if (node != NULL) {
       freeTree(node -> left );
       freeTree(node -> right );
       free(node);
  }
}

// Ana fonksiyon - Program�n giri� noktas�d�r.
int main() {
   Node* root = NULL;

   int n;
   printf("Ka� ders gireceksiniz? ");
   scanf("%d", &n);

	getchar(); // Bu sat�r yeni sat�r karakterini temizlemek i�in eklendi.

	for(int i=0;i<n;i++) {
		char course[50], instructor[50], day[20], time[10];
		int credits;

		printf("\nDers Ad�n� giriniz: ");
		fgets(course,sizeof(course),stdin);
		course[strcspn(course,"\n")]='\0';

		printf("E�itmeni giriniz: ");
		fgets(instructor,sizeof(instructor),stdin);
		instructor[strcspn(instructor,"\n")]='\0';

        printf("Kredi say�s�n� giriniz: ");
        scanf("%d",&credits);

        getchar();

        printf("G�n� giriniz (�rn. Pazartesi): ");
        fgets(day,sizeof(day),stdin);
        day[strcspn(day,"\n")]='\0';

        printf("Saati giriniz (�rn. 10:00): ");
        fgets(time,sizeof(time),stdin);
        time[strcspn(time,"\n")]='\0';

	    root=insert(root,
            course,
            instructor,
            credits,
            day,
            time );
	   }

	printf("\nDers Program�:\n");
	inorderTraversal(root);

	freeTree(root);

	return 0;
}
