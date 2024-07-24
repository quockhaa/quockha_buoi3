#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTran(int a[][MAX], int m, int n, int min, int max);
void xuatMaTran(int a[][MAX], int m, int n);
void xuatCotChiSoLe(int a[][MAX], int m, int n);
void timMaxBien(int a[][MAX], int m, int n);
int demChuSo2(int a[][MAX], int m, int n);
void xuatCucTieu(int a[][MAX], int m, int n);
void sapXepDongLeTangDan(int a[][MAX], int m, int n);
void sapXepDongChanGiamDan(int a[][MAX], int m, int n);
void sapXepCotLeGiamDan(int a[][MAX], int m, int n);
void sapXepCotChanTangDan(int a[][MAX], int m, int n);
bool kiemTraZicZac(int a[][MAX], int m, int n);
void xuatDongToanChan(int a[][MAX], int m, int n);
void xuatDongGiamDan(int a[][MAX], int m, int n);
void timGiaTriXuatHienNhieuNhat(int a[][MAX], int m, int n);
void timChuSoXuatHienNhieuNhat(int a[][MAX], int m, int n);
void xuatCotTongMin(int a[][MAX], int m, int n);
void hoanViCot(int a[][MAX], int m, int n, int i, int j);
void hoanViDong(int a[][MAX], int m, int n, int k, int l);
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

	taoMaTran(a, m, n, 0, 100);
	do {
		menu();
		printf("Nhap lua chon: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			xuatCotChiSoLe(a, m, n);
			break;
		case 2:
			timMaxBien(a, m, n);
			break;
		case 3:
			printf("So phan tu co chu so 2: %d\n", demChuSo2(a, m, n));
			break;
		case 4:
			xuatCucTieu(a, m, n);
			break;
		case 5:
			sapXepDongLeTangDan(a, m, n);
			xuatMaTran(a, m, n);
			break;
		case 6:
			sapXepCotLeGiamDan(a, m, n);
			sapXepCotChanTangDan(a, m, n);
			xuatMaTran(a, m, n);
			break;
		case 7:
			if (kiemTraZicZac(a, m, n)) {
				printf("Ma tran co gia tri giam dan theo cot va dong (zic-zac).\n");
			}
			else {
				printf("Ma tran khong giam dan theo cot va dong (zic-zac).\n");
			}
			break;
		case 8:
			xuatDongToanChan(a, m, n);
			break;
		case 9:
			xuatDongGiamDan(a, m, n);
			break;
		case 10:
			timGiaTriXuatHienNhieuNhat(a, m, n);
			break;
		case 11:
			timChuSoXuatHienNhieuNhat(a, m, n);
			break;
		case 12:
			xuatCotTongMin(a, m, n);
			break;
		case 13:
		{
				   int i, j;
				   printf("nhap cot thu i: ");
				   scanf_s("%d", &i);
				   printf("nhap cot thu j: ");
				   scanf_s("%d", &j);
				   hoanViCot(a, m, n, i, j);
				   xuatMaTran(a, m, n);
		}
			break;
		case 14:
		{
				   int k, l;
				   printf("nhap dong thu k: ");
				   scanf_s("%d", &k);
				   printf("nhap dong thu l: ");
				   scanf_s("%d", &l);
				   hoanViDong(a, m, n, k, l);
				   xuatMaTran(a, m, n);
		}
			break;
		case 0:
			printf(" thoat chuong trinh.\n");
			break;
		default:
			printf("lua chon khong phu hop.\n");
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

void xuatCotChiSoLe(int a[][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		bool allOdd = true;
		for (int i = 0; i < m; i++) {
			if (a[i][j] % 2 == 0) {
				allOdd = false;
				break;
			}
		}
		if (allOdd) {
			for (int i = 0; i < m; i++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

void timMaxBien(int a[][MAX], int m, int n) {
	int max = a[0][0];
	for (int j = 0; j < n; j++) {
		if (a[0][j] > max) max = a[0][j];
		if (a[m - 1][j] > max) max = a[m - 1][j];
	}
	for (int i = 1; i < m - 1; i++) {
		if (a[i][0] > max) max = a[i][0];
		if (a[i][n - 1] > max) max = a[i][n - 1];
	}
	printf("Phan tu lon nhat tren bien: %d\n", max);
}

int demChuSo2(int a[][MAX], int m, int n) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int num = a[i][j];
			while (num != 0) {
				if (num % 10 == 2) {
					count++;
					break;
				}
				num /= 10;
			}
		}
	}
	return count;
}

void xuatCucTieu(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			bool isMin = true;
			for (int k = 0; k < m; k++) {
				if (a[k][j] < a[i][j]) {
					isMin = false;
					break;
				}
			}
			for (int k = 0; k < n; k++) {
				if (a[i][k] < a[i][j]) {
					isMin = false;
					break;
				}
			}
			if (isMin) {
				printf("Cuc tieu tai (%d, %d): %d\n", i, j, a[i][j]);
			}
		}
	}
}

void sapXepDongLeTangDan(int a[][MAX], int m, int n) {
	for (int i = 1; i < m; i += 2) {
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

void sapXepDongChanGiamDan(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i += 2) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i][j] < a[i][k]) {
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
}

void sapXepCotLeGiamDan(int a[][MAX], int m, int n) {
	for (int j = 0; j < n; j += 2) {
		for (int i = 0; i < m - 1; i++) {
			for (int k = i + 1; k < m; k++) {
				if (a[i][j] < a[k][j]) {
					int temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;
				}
			}
		}
	}
}

void sapXepCotChanTangDan(int a[][MAX], int m, int n) {
	for (int j = 1; j < n; j += 2) {
		for (int i = 0; i < m - 1; i++) {
			for (int k = i + 1; k < m; k++) {
				if (a[i][j] > a[k][j]) {
					int temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;
				}
			}
		}
	}
}

bool kiemTraZicZac(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if ((i % 2 == 0 && a[i][j] > a[i][j + 1]) || (i % 2 == 1 && a[i][j] < a[i][j + 1])) {
				return false;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m - 1; i++) {
			if ((j % 2 == 0 && a[i][j] > a[i + 1][j]) || (j % 2 == 1 && a[i][j] < a[i + 1][j])) {
				return false;
			}
		}
	}
	return true;
}

void xuatDongToanChan(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		bool allEven = true;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				allEven = false;
				break;
			}
		}
		if (allEven) {
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

void xuatDongGiamDan(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		bool decreasing = true;
		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] <= a[i][j + 1]) {
				decreasing = false;
				break;
			}
		}
		if (decreasing) {
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

void timGiaTriXuatHienNhieuNhat(int a[][MAX], int m, int n) {
	int count[MAX * MAX] = { 0 };
	int maxCount = 0;
	int maxValue = a[0][0];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			count[a[i][j]]++;
			if (count[a[i][j]] > maxCount) {
				maxCount = count[a[i][j]];
				maxValue = a[i][j];
			}
		}
	}
	printf("Gia tri xuat hien nhieu nhat: %d\n", maxValue);
}
void timChuSoXuatHienNhieuNhat(int a[][MAX], int m, int n) {
	int count[10] = { 0 };
	int maxCount = 0;
	int maxDigit = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int num = a[i][j];
			while (num != 0) {
				count[num % 10]++;
				num /= 10;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (count[i] > maxCount) {
			maxCount = count[i];
			maxDigit = i;
		}
	}
	printf("Chu so xuat hien nhieu nhat: %d\n", maxDigit);

}

void xuatCotTongMin(int a[][MAX], int m, int n) {
	int minSum = 0;
	int colMin = 0;

	int sum[MAX] = { 0 };
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			sum[j] += a[i][j];
		}
	}

	minSum = sum[0];
	for (int j = 1; j < n; j++) {
		if (sum[j] < minSum) {
			minSum = sum[j];
			colMin = j;
		}
	}

	printf("Cac cot co tong nho nhat:\n");
	for (int j = 0; j < n; j++) {
		if (sum[j] == minSum) {
			for (int i = 0; i < m; i++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}

}

void hoanViCot(int a[][MAX], int m, int n, int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n) {
		printf("Chi so cot khong hop le.\n");
		return;
	}

	for (int k = 0; k < m; k++) {
		int temp = a[k][i];
		a[k][i] = a[k][j];
		a[k][j] = temp;
	}

}

void hoanViDong(int a[][MAX], int m, int n, int k, int l) {
	if (k < 0 || k >= m || l < 0 || l >= m) {
		printf("Chi so dong khong hop le.\n");
		return;
	}

	for (int j = 0; j < n; j++) {
		int temp = a[k][j];
		a[k][j] = a[l][j];
		a[l][j] = temp;
	}

}

void menu() {
	printf("1.Xuat cac cot chi chua so le\n");
	printf("2.Tim phan tu lon nhat trong cac phan tu tren bien\n");
	printf("3.Trong ma tran co bao nhieu phan tu co chu so 2\n");
	printf("4.Xuat cac phan tu cuc tieu\n");
	printf("5.Sap xep ma tran : dong le tang dan, dong chan giam dan\n");
	printf("6.Sap xep ma tran : cot le giam dan, cot chan tang dan\n");
	printf("7.Kiem tra ma tran co giam dan theo cot va dong(zic - zac)\n");
	printf("8.Xuat dong chi chua so chan\n");
	printf("9.Xuat dong chua gia tri giam dan\n");
	printf("10.Tim gia tri xuat hien nhieu nhat\n");
	printf("11.Tim chu so xuat hien nhieu nhat\n");
	printf("12.Xuat cot co tong nho nhat\n");
	printf("13.Hoan vi hai cot\n");
	printf("14.Hoan vi hai dong\n");
	printf("0.Thoat\n");
}
		