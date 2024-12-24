#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dugum yapisi.
typedef struct Node {
    char courseName[50]; // Ders adi
    char instructor[50]; // Egitmen adi
    int credits;  // Kredi sayisi
    char day[20];  // Gün bilgisi (örnegin "Pazartesi")
    char time[10]; // Saat bilgisi (örnegin "10:00")
    struct Node* left; // Sol alt dügüm isaretçisi
    struct Node* right; // Sað alt dügüm isaretçisi
} Node;

// dügüm olusturma fonksiyonu.
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

// olusturgumuz dügümleri agaca ekleme.
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

// Inorder Traversal: sol kök sag sirasi ile.
void inorderTraversal(Node* node) {
   if (node != NULL) {
       inorderTraversal(node -> left );
       printf("Ders Adi: %s | Egitmen: %s | Kredi: %d | Gün: %s | Saat: %s\n", node -> courseName,
              node -> instructor,node -> credits,node -> day,node -> time );
      inorderTraversal(node -> right );
   }
}

// agac icin kullanilan bellegi bosatlma.
void freeTree(Node* node) {
   if (node != NULL) {
       freeTree(node -> left );
       freeTree(node -> right );
       free(node);
  }
}

// Ana fonksiyon.
int main() {
   Node* root = NULL;

   int n;
   printf("Kac ders gireceksiniz? ");
   scanf("%d", &n);

	getchar(); 

	for(int i=0;i<n;i++) {
		char course[50], instructor[50], day[20], time[10];
		int credits;

		printf("\nDers Adini giriniz: ");
		fgets(course,sizeof(course),stdin);
		course[strcspn(course,"\n")]='\0';

		printf("ogretmeni giriniz: ");
		fgets(instructor,sizeof(instructor),stdin);
		instructor[strcspn(instructor,"\n")]='\0';

        printf("Kredi sayisini giriniz: ");
        scanf("%d",&credits);

        getchar();

        printf("Gunu giriniz (orn. Pazartesi): ");
        fgets(day,sizeof(day),stdin);
        day[strcspn(day,"\n")]='\0';

        printf("Saati giriniz (orn. 10:00): ");
        fgets(time,sizeof(time),stdin);
        time[strcspn(time,"\n")]='\0';

	    root=insert(root,
            course,
            instructor,
            credits,
            day,
            time );
	   }

	printf("\nDers Programi:\n");
	inorderTraversal(root);

	freeTree(root);

	return 0;
}
