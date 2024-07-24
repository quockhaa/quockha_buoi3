
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100

void taoMaTran(int a[][MAX], int m, int n, int min, int max);
void xuatMaTran(int a[][MAX], int m, int n);
void tinhTongDong(int a[][MAX], int m, int n);
void phanTuLonNhatTrenCot(int a[][MAX], int m, int n);
void xuatBien(int a[][MAX], int m, int n);
bool laCucDai(int a[][MAX], int m, int n, int i, int j);
void xuatCucDai(int a[][MAX], int m, int n);
bool laHoangHau(int a[][MAX], int m, int n, int i, int j);
void xuatHoangHau(int a[][MAX], int m, int n);
bool laDiemYenNgua(int a[][MAX], int m, int n, int i, int j);
void xuatDiemYenNgua(int a[][MAX], int m, int n);
void xuatDongSoChan(int a[][MAX], int m, int n);
void sapXepDongTangDan(int a[][MAX], int m, int n);
void menu();

int main() {
	int a[MAX][MAX];
	int m, n;
	int choice;

	printf("Nhap so dong (m): ");
	scanf_s("%d", &m);
	printf("Nhap so cot (n): ");
	scanf_s("%d", &n);

	if (m <= 0 || n <= 0) {
		printf("So dong va so cot phai lon hon 0.\n");
		return 0;
	}

	do {
		menu();
		printf("Nhap lua chon: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			taoMaTran(a, m, n, 0, 100);
			xuatMaTran(a, m, n);
			break;
		case 2:
			tinhTongDong(a, m, n);
			break;
		case 3:
			phanTuLonNhatTrenCot(a, m, n);
			break;
		case 4:
			xuatBien(a, m, n);
			break;
		case 5:
			xuatCucDai(a, m, n);
			break;
		case 6:
			xuatHoangHau(a, m, n);
			break;
		case 7:
			xuatDiemYenNgua(a, m, n);
			break;
		case 8:
			xuatDongSoChan(a, m, n);
			break;
		case 9:
			sapXepDongTangDan(a, m, n);
			xuatMaTran(a, m, n);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le.\n");
		}
	} while (choice != 0);

	return 0;
}

void taoMaTran(int a[][MAX], int m, int n, int min, int max) {
	srand((unsigned int)time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = min + rand() % (max - min + 1);
		}
	}
}

void xuatMaTran(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void tinhTongDong(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
		printf("Tong dong %d: %d\n", i, sum);
	}
}

void phanTuLonNhatTrenCot(int a[][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		int max = a[0][j];
		for (int i = 1; i < m; i++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		printf("Phan tu lon nhat tren cot %d: %d\n", j, max);
	}
}

void xuatBien(int a[][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		printf("%d ", a[0][j]);
	}
	printf("\n");
	for (int i = 1; i < m; i++) {
		printf("%d ", a[i][n - 1]);
	}
	printf("\n");
	if (m > 1) {
		for (int j = n - 2; j >= 0; j--) {
			printf("%d ", a[m - 1][j]);
		}
		printf("\n");
	}
	if (n > 1) {
		for (int i = m - 2; i > 0; i--) {
			printf("%d ", a[i][0]);
		}
		printf("\n");
	}
}

bool laCucDai(int a[][MAX], int m, int n, int i, int j) {
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
			if (a[ni][nj] >= a[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void xuatCucDai(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laCucDai(a, m, n, i, j)) {
				printf("Cuc dai tai (%d, %d): %d\n", i, j, a[i][j]);
			}
		}
	}
}

bool laHoangHau(int a[][MAX], int m, int n, int i, int j) {
	int di[] = { -1, -1, 1, 1, -1, 1, 0, 0 };
	int dj[] = { -1, 1, -1, 1, 0, 0, -1, 1 };
	for (int k = 0; k < 8; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		while (ni >= 0 && ni < m && nj >= 0 && nj < n) {
			if (a[ni][nj] >= a[i][j]) {
				return false;
			}
			ni += di[k];
			nj += dj[k];
		}
	}
	return true;
}

void xuatHoangHau(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laHoangHau(a, m, n, i, j)) {
				printf("Hoang hau tai (%d, %d): %d\n", i, j, a[i][j]);
			}
		}
	}
}

bool laDiemYenNgua(int a[][MAX], int m, int n, int i, int j) {
	int max = a[i][j];
	for (int k = 0; k < n; k++) {
		if (a[i][k] > max) {
			return false;
		}
	}
	int min = a[i][j];
	for (int k = 0; k < m; k++) {
		if (a[k][j] < min) {
			return false;
		}
	}
	return true;
}

void xuatDiemYenNgua(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laDiemYenNgua(a, m, n, i, j)) {
				printf("Diem yen ngua tai (%d, %d): %d\n", i, j, a[i][j]);
			}
		}
	}
}

void xuatDongSoChan(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		bool chiSoChan = true;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				chiSoChan = false;
				break;
			}
		}
		if (chiSoChan) {
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

void sapXepDongTangDan(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i][j] > a[i][k]) {
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
}

void menu() {
	printf("1. Tao va xuat ma tran a\n");
	printf("2. Tinh va xuat tong gia tri tung dong\n");
	printf("3. Xuat phan tu lon nhat tren tung cot\n");
	printf("4. Xuat cac phan tu thuoc cac duong bien\n");
	printf("5. Xuat cac phan tu cuc dai\n");
	printf("6. Xuat cac phan tu hoang hau\n");
	printf("7. Xuat cac phan tu la diem yen ngua\n");
	printf("8. Xuat dong chi chua so chan\n");
	printf("9. Sap xep mang a tang theo tung dong\n");
	printf("0. Thoat\n");
}


	