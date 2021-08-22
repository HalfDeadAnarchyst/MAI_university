#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOLDIER_DISEASE_CHANCE 20
#define STAT_CHANCE 80

typedef enum { false, true } bool;

int main()
{
	/*Initializing variables */
	FILE *mf;
	char gender, f, m;
	f = 'f';
	m = 'm';
	char name[50];
	bool flag;
	int age, temp, ext1, ext2, chance; //ext1 - higher, ext2 - lower

	int line, i;

	/* Age/gender normal values 38/38 */
	//                   hematocri|hemoglobin |Red blo|MCV      |RDW      |MCH      |MCHC     |platelets  |White blo|Neutrophi|Lymphocyt|Monocyte|eosonop|bas    |absneut|abslymp|abseoso|absbaso|SOEV
	/*
	double agem1518[38]={37.0,48.0,117.0,166.0,4.5,5.3,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,180.0,420.0,4.5,11.0 ,47.0,72.0,19.0,37.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.6,1.0,0.0,15.0};
	double agem1845[38]={42.0,50.0,132.0,173.0,4.0,5.0,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,4,2,9.0  ,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,15.0};
	double agem4565[38]={39.0,50.0,131.0,172.0,4.0,5.0,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,4,2,9.0  ,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,20.0};
	double agem6599[38]={37.0,51.0,126.0,174.0,4.0,5.0,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,4,2,9.0  ,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,20.0};
	double agef1518[38]={34.0,44.0,117.0,153.0,4.1,5.1,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,180.0,420.0,4.5,11.0 ,47.0,72.0,19.0,37.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.6,1.0,0.0,20.0};
	double agef1845[38]={38.0,47.0,117.0,155.0,3.5,4.7,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,3,98,10,4,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,20.0};
	double agef4565[38]={35.0,47.0,117.0,160.0,3.5,4.7,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,3,98,10,4,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,30.0};
	double agef6599[38]={35.0,47.0,120.0,161.0,3.5,4.7,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,3,98,10,4,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,30.0};
	*/

	double data[8][38] = { 37.0,48.0,117.0,166.0,4.5,5.3,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,180.0,420.0,4.5,11.0 ,47.0,72.0,19.0,37.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.6,1.0,0.0,15.0,
		42.0,50.0,132.0,173.0,4.0,5.0,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,4.2,9.0,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,15.0,
		39.0,50.0,131.0,172.0,4.0,5.0,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,4.2,9.0,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,20.0,
		37.0,51.0,126.0,174.0,4.0,5.0,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,4.2,9.0,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,20.0,
		34.0,44.0,117.0,153.0,4.1,5.1,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,180.0,420.0,4.5,11.0,47.0,72.0,19.0,37.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.6,1.0,0.0,20.0,
		38.0,47.0,117.0,155.0,3.5,4.7,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,3.98,10.4,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,20.0,
		35.0,47.0,117.0,160.0,3.5,4.7,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,3.98,10.4,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,30.0,
		35.0,47.0,120.0,161.0,3.5,4.7,80.0,95.0,11.6,14.8,24.0,33.0,30.0,38.0,200.0,400.0,3.98,10.4,50.0,70.0,20.0,40.0,3.0,11.0,1.0,5.0,0.0,1.0,1.0,3.0,1.0,4.8,0.0,1.5,0.5,1.0,0.0,30.0 };
	double results[20];

	/* Random seed */
	srand(time(NULL));

	/* Menu */
	printf("Welcome to Coalition Blood Analyses!\nProgram made by Elizabeth Rayvel\n");

	printf("All results would be in file 'Results.txt'\n");
	printf("Trying to open file...\n");
	sleep(rand() % 4);
	/* File opening */
	mf = fopen("Results.txt", "a");
	if (mf == NULL) {
		printf("File opening error, run program as administrator or contact with developer.\n");
		printf("Press any button to close program\n");
		scanf("%c", &gender);
		return -1;
	}
	else {
		printf("Opening successful\n\n");
	}

	/* Enter all variables */
	printf("Enter subject's name:\n");
	fgets(name, 256, stdin);
	/* Remove trailing newline, if there. */
	if ((strlen(name)>0) && (name[strlen(name) - 1] == '\n'))
		name[strlen(name) - 1] = '\0';

	/* Enter gender */
	//TODO Repair gender error multiply
	while ((gender != f) && (gender != m)) {
		printf("Enter subject's gender:\n");
		scanf("%c", &gender);
		if ((gender != 'f') && (gender != 'm')) {
			printf("Gender must be 'm' or 'f'\n");
		}
	}

	/* Enter age */
	while ((age<15) || (age>100)) {
		printf("Enter subject's age\n");
		scanf("%d", &age);
	}
	printf("\n");

	/* Generate */

	/* Chooses needed data for every type of subject */
	line = 0;
	i = 0;
	if (gender == 'f') {
		line += 4;
	}
	if (age<18) {
		//line+=0;
	}
	else if (age<45) {
		line += 1;
	}
	else if (age<65) {
		line += 2;
	}
	else {
		line += 3;
	}

	/* Is soldier healthy */
	i = (rand() % 100);
	if (i<SOLDIER_DISEASE_CHANCE) {
		flag = true;  //Diseased
	}
	else {
		flag = false; //Healthy
	}

	/* In depends of flag makes blood analyses */
	for (i = 0; i<20; i++) {
		ext1 = data[line][i * 2 + 1] * 100;
		ext2 = data[line][i * 2] * 100;
		temp = (rand() % (ext1 - ext2)) + ext2;
		if (flag == true) {
			if ((rand() % 100)<STAT_CHANCE) {
				chance = ((rand() % (ext1 - ext2)) + ext2) / 3;
				if (temp - chance<0) {
					temp += chance;
				}
				else {
					if ((rand() % 100)<33) {
						temp -= chance;
					}
					else {
						temp += chance;
					}
				}
			}
		}
		results[i] = temp;
		results[i] = results[i] / 100;
	}

	/*for(i=0;i<19;i++){
	printf("%.1f\n", results[i]);
	}*/

	/* Printing results */
	printf("Subject: %s, gender: %c, age: %d\nBlood analysis:\nNormal values would be in '[ ]'\n\n", name, gender, age);
	fprintf(mf, "Subject: %s, gender: %c, age: %d\nBlood analysis:\nNormal values would be in '[ ]'\n\n", name, gender, age);
	if ((results[0]>data[line][0]) && (results[0]<data[line][1])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Hematocrit        - %-5.1f  %%       [%.1f-%.1f]\n", results[0], data[line][0], data[line][1]);
	fprintf(mf, "Hematocrit        - %-5.1f  %%       [%.1f-%.1f]\n", results[0], data[line][0], data[line][1]);
	sleep(rand() % 10);
	if ((results[1]>data[line][2]) && (results[1]<data[line][3])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Hemoglobin        - %-5.1f  g/dl    [%.1f-%.1f]\n", results[1], data[line][2], data[line][3]);
	fprintf(mf, "Hemoglobin        - %-5.1f  g/dl    [%.1f-%.1f]\n", results[1], data[line][2], data[line][3]);
	sleep(rand() % 10);
	if ((results[2]>data[line][4]) && (results[2]<data[line][5])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Red Blood Cells   - %-5.1f  mln/mkg [%.1f-%.1f]\n", results[2], data[line][4], data[line][5]);
	fprintf(mf, "Red Blood Cells   - %-5.1f  mln/mkg [%.1f-%.1f]\n", results[2], data[line][4], data[line][5]);
	sleep(rand() % 10);
	if ((results[3]>data[line][6]) && (results[3]<data[line][7])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("MCV               - %-5.1f  fl.     [%.1f-%.1f]\n", results[3], data[line][6], data[line][7]);
	fprintf(mf, "MCV               - %-5.1f  fl.     [%.1f-%.1f]\n", results[3], data[line][6], data[line][7]);
	sleep(rand() % 10);
	if ((results[4]>data[line][8]) && (results[4]<data[line][9])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("RDW               - %-5.1f  %%       [%.1f-%.1f]\n", results[4], data[line][8], data[line][9]);
	fprintf(mf, "RDW               - %-5.1f  %%       [%.1f-%.1f]\n", results[4], data[line][8], data[line][9]);
	sleep(rand() % 10);
	if ((results[5]>data[line][10]) && (results[5]<data[line][11])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("MCH               - %-5.1f  pg      [%.1f-%.1f]\n", results[5], data[line][10], data[line][11]);
	fprintf(mf, "MCH               - %-5.1f  pg      [%.1f-%.1f]\n", results[5], data[line][10], data[line][11]);
	sleep(rand() % 10);
	if ((results[6]>data[line][12]) && (results[6]<data[line][13])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("MCHC              - %-5.1f  g/dl    [%.1f-%.1f]\n", results[6], data[line][12], data[line][13]);
	fprintf(mf, "MCHC              - %-5.1f  g/dl    [%.1f-%.1f]\n", results[6], data[line][12], data[line][13]);
	sleep(rand() % 10);
	if ((results[7]>data[line][14]) && (results[7]<data[line][15])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Platelets         - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[7], data[line][14], data[line][15]);
	fprintf(mf, "Platelets         - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[7], data[line][14], data[line][15]);
	sleep(rand() % 10);
	if ((results[8]>data[line][16]) && (results[8]<data[line][17])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("White Blood Cells - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[8], data[line][16], data[line][17]);
	fprintf(mf, "White Blood Cells - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[8], data[line][16], data[line][17]);
	sleep(rand() % 10);
	if ((results[9]>data[line][18]) && (results[9]<data[line][19])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Neutrophils       - %-5.1f  %%       [%.1f-%.1f]\n", results[9], data[line][18], data[line][19]);
	fprintf(mf, "Neutrophils       - %-5.1f  %%       [%.1f-%.1f]\n", results[9], data[line][18], data[line][19]);
	sleep(rand() % 10);
	if ((results[10]>data[line][20]) && (results[10]<data[line][21])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Lymphocytes       - %-5.1f  %%       [%.1f-%.1f]\n", results[10], data[line][20], data[line][21]);
	fprintf(mf, "Lymphocytes       - %-5.1f  %%       [%.1f-%.1f]\n", results[10], data[line][20], data[line][21]);
	sleep(rand() % 10);
	if ((results[11]>data[line][22]) && (results[11]<data[line][23])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Monocytes         - %-5.1f  %%       [%.1f-%.1f]\n", results[11], data[line][22], data[line][23]);
	fprintf(mf, "Monocytes         - %-5.1f  %%       [%.1f-%.1f]\n", results[11], data[line][22], data[line][23]);
	sleep(rand() % 10);
	if ((results[12]>data[line][24]) && (results[12]<data[line][25])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Eosinophils       - %-5.1f  %%       [%.1f-%.1f]\n", results[12], data[line][24], data[line][25]);
	fprintf(mf, "Eosinophils       - %-5.1f  %%       [%.1f-%.1f]\n", results[12], data[line][24], data[line][25]);
	sleep(rand() % 10);
	if ((results[13]>data[line][26]) && (results[13]<data[line][27])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Basophiles        - %-5.1f  %%       [%.1f-%.1f]\n", results[13], data[line][26], data[line][27]);
	fprintf(mf, "Basophiles        - %-5.1f  %%       [%.1f-%.1f]\n", results[13], data[line][26], data[line][27]);
	sleep(rand() % 10);
	if ((results[14]>data[line][28]) && (results[14]<data[line][29])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Neutrophils abs.  - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[14], data[line][28], data[line][29]);
	fprintf(mf, "Neutrophils abs.  - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[14], data[line][28], data[line][29]);
	sleep(rand() % 10);
	if ((results[15]>data[line][30]) && (results[15]<data[line][31])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Lymphocytes abs.  - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[15], data[line][30], data[line][31]);
	fprintf(mf, "Lymphocytes abs.  - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[15], data[line][30], data[line][31]);
	sleep(rand() % 10);
	if ((results[16]>data[line][32]) && (results[16]<data[line][33])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Eosinophils abs.  - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[16], data[line][32], data[line][33]);
	fprintf(mf, "Eosinophils abs.  - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[16], data[line][32], data[line][33]);
	sleep(rand() % 10);
	if ((results[17]>data[line][34]) && (results[17]<data[line][35])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("Basophils abs.    - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[17], data[line][34], data[line][35]);
	fprintf(mf, "Basophils abs.    - %-5.1f  1k/mkl  [%.1f-%.1f]\n", results[17], data[line][34], data[line][35]);
	sleep(rand() % 10);
	if ((results[18]>data[line][36]) && (results[18]<data[line][37])) {
		printf("   ");
		fprintf(mf, "   ");
	}
	else {
		printf("(!)");
		fprintf(mf, "(!)");
	}
	printf("SOE (By Westgern) - %-5.1f  mm/ch   [%.1f-%.1f]\n\n", results[18], data[line][36], data[line][37]);
	fprintf(mf, "SOE (By Westgern) - %-5.1f  mm/ch   [%.1f-%.1f]\n\n", results[18], data[line][36], data[line][37]);

	printf("Enter any symbol to close the program");
	scanf("%c", &gender);

	fclose(mf);
	return 0;

}