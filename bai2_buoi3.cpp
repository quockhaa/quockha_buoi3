//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stdbool.h>
//
//
//#define MAX 100
//
//// 2.1: tao va xuat ma tran 
//void taoMaTran(int a[][MAX], int n, int min, int max) {
//	srand((unsigned int)time(0));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			a[i][j] = min + rand() % (max - min + 1);
//		}
//	}
//}
//
//void xuatMaTran(int a[][MAX], int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//// 2.2: xuat cac phan tu tren duong cheo chinh
//void xuatCheoChinh(int a[][MAX], int n) {
//	for (int i = 0; i < n; i++) {
//		printf("%d ", a[i][i]);
//	}
//	printf("\n");
//}
//// 2.3: xuat cheo phu
//void xuatCheoPhu(int a[][MAX], int n) {
//	for (int i = 0; i < n; i++) {
//		printf("%d ", a[i][n - 1 - i]);
//	}
//	printf("\n");
//}
//
//// 2.4: tim max thuoc tam giac tren cua duong cheo chinh
//int timMaxTamGiacTren(int a[][MAX], int n) {
//	int max = a[0][0];
//	for (int i = 0; i < n; i++) {
//		for (int j = i; j < n; j++) {
//			if (a[i][j] > max) {
//				max = a[i][j];
//			}
//		}
//	}
//	return max;
//}
//
//// 2.5: sap xep zigzag
//void sapXepZigZag(int a[][MAX], int n) {
//	int temp[MAX*MAX];
//	int k = 0;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			temp[k++] = a[i][j];
//		}
//	}
//
//	for (int i = 0; i < k - 1; i++) {
//		for (int j = i + 1; j < k; j++) {
//			if (temp[i] > temp[j]) {
//				int swap = temp[i];
//				temp[i] = temp[j];
//				temp[j] = swap;
//			}
//		}
//	}
//
//	k = 0;
//	for (int i = 0; i < n; i++) {
//		if (i % 2 == 0) {
//			for (int j = 0; j < n; j++) {
//				a[i][j] = temp[k++];
//			}
//		}
//		else {
//			for (int j = n - 1; j >= 0; j--) {
//				a[i][j] = temp[k++];
//			}
//		}
//	}
//}
//
//// 2.6: sap xep duong cheo chinh tang dan 
//void sapXepCheoChinh(int a[][MAX], int n) {
//	int temp[MAX];
//	for (int i = 0; i < n; i++) {
//		temp[i] = a[i][i];
//	}
//
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (temp[i] > temp[j]) {
//				int swap = temp[i];
//				temp[i] = temp[j];
//				temp[j] = swap;
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		a[i][i] = temp[i];
//	}
//}
//
//void menu() {
//	printf("1. Tao va xuat ma tran vuong\n");
//	printf("2. Xuat cac phan tu tren duong cheo chinh\n");
//	printf("3. Xuat cac phan tu thuoc duong cheo phu\n");
//	printf("4. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
//	printf("5. Sap xep ma tran tang dan theo kieu zic-zac\n");
//	printf("6. Sap xep duong cheo chinh tang dan\n");
//	printf("0. Thoat\n");
//}
//
//int main() {
//	int a[MAX][MAX];
//	int n;
//	int choice;
//	printf("Nhap cap cua ma tran (n >= 5): ");
//	scanf("%d", &n);
//
//	if (n < 5) {
//		printf("Cap cua ma tran phai lon hon hoac bang 5.\n");
//		return 0;
//	}
//
//	do {
//		menu();
//		printf("Nhap lua chon: ");
//		scanf("%d", &choice);
//
//		switch (choice) {
//		case 1:
//			taoMaTran(a, n, 0, 100);
//			xuatMaTran(a, n);
//			break;
//		case 2:
//			xuatCheoChinh(a, n);
//			break;
//		case 3:
//			xuatCheoPhu(a, n);
//			break;
//		case 4:
//			printf("Phan tu max thuoc tam giac tren cua duong cheo chinh: %d\n", timMaxTamGiacTren(a, n));
//			break;
//		case 5:
//			sapXepZigZag(a, n);
//			xuatMaTran(a, n);
//			break;
//		case 6:
//			sapXepCheoChinh(a, n);
//			xuatMaTran(a, n);
//			break;
//		case 0:
//			printf("Thoat chuong trinh.\n");
//			break;
//		default:
//			printf("Lua chon khong hop le.\n");
//		}
//	} while (choice != 0);
//
//	return 0;
//}