#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main() {
	int opt = 5, n_words = 0;  
	char dictionary[3][50][30];
	
	n_words = 5;  
	strcpy(dictionary[0][0], "nula");
	strcpy(dictionary[0][1], "edno");
	strcpy(dictionary[0][2], "dve");
	strcpy(dictionary[0][3], "tri");
	strcpy(dictionary[0][4], "chetiri");  

	strcpy(dictionary[1][0], "zero");
	strcpy(dictionary[1][1], "one");
	strcpy(dictionary[1][2], "two");
	strcpy(dictionary[1][3], "three");
	strcpy(dictionary[1][4], "four");

	strcpy(dictionary[2][0], "nul");
	strcpy(dictionary[2][1], "odin");
	strcpy(dictionary[2][2], "dva");
	strcpy(dictionary[2][3], "tri");
	strcpy(dictionary[2][4], "chetuiri");

	while (opt) {  
		printf("Select an option:\n");
		printf("0: Quit\n");
		printf("1: Enter a word\n");
		printf("2: Delete a word\n");
		printf("3: Show\n");
		printf("4: Sort alphabetically\n");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1: {
			char languages[3][10] = { "Bulgarian","English","Russian" };
			int i;
			for (i = 0; i < 3; i++) {
				printf("Enter a word in %s: ", languages[i]);
				scanf("%s", dictionary[i][n_words]);
				printf("\n");
			}
			n_words++;
		}  break;

		case 2: {
			char word[30];
			printf("Enter a word that you want to delete: ");
			scanf("%s", word);
			for (int l = 0; l < 3; l++) {
				for (int i = 0; i < n_words; i++) {      
					if (strcmp(dictionary[l][i], word) == 0) {
						for (int j = 0; j < 3; j++) { 
							if (i != n_words - 1) {
								strcpy(dictionary[j][i], dictionary[j][n_words - 1]);
								
							}
							strcpy(dictionary[j][n_words - 1], "");
						}
						n_words--;
					}
				}
			}
		}  break;

		case 3: {
			char languages[3][10] = { "Bulgarian","English","Russian" };
			int l1, l2, op;
			printf("Select an option (1/2):\n");
			printf("1.Show in 3 languages\n");
			printf("2.Show in 2 languages\n");
			scanf("%d", &op);

			if (op == 1) {
				for (int i = 0; i < n_words; i++) {
					for (int j = 0; j < 3; j++) {
						printf("%s:\t", languages[j]);
						printf("%s\n", dictionary[j][i]);
					}
					printf("\n");
				}
			}
			else if (op == 2) {
				printf("1.Bulgarian\n");
				printf("2.English\n");
				printf("3.Russian\n");
				printf("Select language 1: ");
				scanf("%d", &l1);
				printf("Select language 2: ");
				scanf("%d", &l2);
				printf("\n");

				for (int i = 0; i < n_words; i++) {
					printf("%s:\t", languages[l1 - 1]);
					printf("%s\n", dictionary[l1 - 1][i]);
					printf("%s:\t", languages[l2 - 1]);
					printf("%s\n", dictionary[l2 - 1][i]);
					printf("\n");
				}
			}
			else {
				printf("There is no such an option\n");
			}
		}  break;

		case 4: {
			int l;
			char rnd[20]; 
			printf("1.Bulgarian\n");
			printf("2.English\n");
			printf("3.Russian\n");
			printf("Select the language you want to sort: ");
			scanf("%d", &l);
			l = l - 1;

			for (int i = 0; i < n_words; i++) {
				for (int j = i + 1; j < n_words; j++) {
					if (strcmp(dictionary[l][i], dictionary[l][j]) > 0) {  
						for (int n = 0; n < 3; n++) {  //minavame prez 3te ezika
							strcpy(rnd, dictionary[n][i]);
							strcpy(dictionary[n][i], dictionary[n][j]);
							strcpy(dictionary[n][j], rnd);
						}
					}
				}
			}
		}   break;

		default: printf("Bye!");  break;
		}
	}

	return 0;
}
