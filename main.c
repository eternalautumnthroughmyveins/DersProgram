#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Düðüm yapýsýný tanýmlýyoruz.
typedef struct Node {
    char courseName[50]; // Ders adý
    char instructor[50]; // Eðitmen adý
    int credits;  // Kredi sayýsý
    char day[20];  // Gün bilgisi (örneðin "Pazartesi")
    char time[10]; // Saat bilgisi (örneðin "10:00")
    struct Node* left; // Sol alt düðüm iþaretçisi
    struct Node* right; // Sað alt düðüm iþaretçisi
} Node;

// Yeni düðüm oluþturma fonksiyonu.
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

// Aðaçta dersi ekleyecek olan fonksiyon.
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

// Inorder Traversal: Soldan baþlayarak kökü ve sonra sað çocuðu ziyaret ederiz.
void inorderTraversal(Node* node) {
   if (node != NULL) {
       inorderTraversal(node -> left );
       printf("Ders Adý: %s | Eðitmen: %s | Kredi: %d | Gün: %s | Saat: %s\n", node -> courseName,
              node -> instructor,node -> credits,node -> day,node -> time );
      inorderTraversal(node -> right );
   }
}

// Aðaçtaki tüm kaynaklarý serbest býrakmak içindir.
void freeTree(Node* node) {
   if (node != NULL) {
       freeTree(node -> left );
       freeTree(node -> right );
       free(node);
  }
}

// Ana fonksiyon - Programýn giriþ noktasýdýr.
int main() {
   Node* root = NULL;

   int n;
   printf("Kaç ders gireceksiniz? ");
   scanf("%d", &n);

	getchar(); // Bu satýr yeni satýr karakterini temizlemek için eklendi.

	for(int i=0;i<n;i++) {
		char course[50], instructor[50], day[20], time[10];
		int credits;

		printf("\nDers Adýný giriniz: ");
		fgets(course,sizeof(course),stdin);
		course[strcspn(course,"\n")]='\0';

		printf("Eðitmeni giriniz: ");
		fgets(instructor,sizeof(instructor),stdin);
		instructor[strcspn(instructor,"\n")]='\0';

        printf("Kredi sayýsýný giriniz: ");
        scanf("%d",&credits);

        getchar();

        printf("Günü giriniz (örn. Pazartesi): ");
        fgets(day,sizeof(day),stdin);
        day[strcspn(day,"\n")]='\0';

        printf("Saati giriniz (örn. 10:00): ");
        fgets(time,sizeof(time),stdin);
        time[strcspn(time,"\n")]='\0';

	    root=insert(root,
            course,
            instructor,
            credits,
            day,
            time );
	   }

	printf("\nDers Programý:\n");
	inorderTraversal(root);

	freeTree(root);

	return 0;
}
