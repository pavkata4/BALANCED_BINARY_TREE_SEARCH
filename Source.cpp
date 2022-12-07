#include<iostream>
using namespace std;
typedef struct Node* ptr;
ptr root;
int COUNT = 10;
struct Node {
	int Data;
	ptr left;
	ptr right;
};
ptr IBTS(int* arr, int li, int di) {
	if (li <= di) {
		int mid = li + (di - li) / 2;
		ptr loc = root, insert = root;
		if (root == NULL) {
			root = new Node;
			root->Data = arr[mid];
			root->left = NULL;
			root->right = NULL;
		}
		else {
			while (loc != NULL && loc->Data != arr[mid]) {
				insert = loc;
				if (arr[mid] > loc->Data) {
					loc = loc->right;
				}
				else {
					loc = loc->left;
				}
			}
			if (loc != NULL) {
				cout << "There is!" << endl;
			}
			else {
				loc = new Node;
				loc->Data = arr[mid];
				loc->left = NULL;
				loc->right = NULL;
				if (arr[mid] > insert->Data) {
					insert->right = loc;
				}
				else {
					insert->left = loc;
				}
			}
		}
		IBTS(arr, li, mid - 1);
		IBTS(arr, mid + 1, di);
		return root;
	}
	else {
		return NULL;
	}
}
void fillArray(int*& arr, int size) {
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}
void quickSort(int* arr, int iBeg, int iEnd) {
	if (iBeg < iEnd) {
		int j = iBeg, k = iEnd;
		int etalon = arr[(iBeg + iEnd) / 2];
		while (j <= k) {
			while (arr[j] < etalon)j++;
			while (arr[k] > etalon)k--;
			if (j <= k) {
				int buffer = arr[j];
				arr[j] = arr[k];
				arr[k] = buffer;
				j++;
				k--;
			}
		}
		quickSort(arr, iBeg, k);
		quickSort(arr, j, iEnd);
	}
}
void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void deleteRepeated(int*& arr, int& n) {
	int* arr2 = new int[n];
	bool repeated = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		repeated = false;
		for (int j = 0; j < cnt; j++) {
			if (arr[i] == arr2[j]) {
				repeated = true;
				break;
			}
		}
		if (!repeated) {
			arr2[cnt] = arr[i];
			cnt++;
		}
	}
	if (arr != nullptr) {
		delete[] arr;
		arr = nullptr;
		arr = new int[cnt];
		for (int i = 0; i < cnt; i++) {
			arr[i] = arr2[i];
		}
	}
	if (arr2 != nullptr) {
		delete[] arr2;
		arr2 = nullptr;
	}
	n = cnt;
}
void print(ptr root, int space) {
	if (root == NULL)
		return;
	space += COUNT;
	print(root->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->Data << "\n";
	print(root->left, space);
}
int main() {
	setlocale(LC_ALL, "BULGARIAN");
	int n = 15;
	int* arr = new int[n];
	// {1,0,1,1,4,3,10,11,43,0,1,4,7,01,47};
	arr[0] = 1, arr[1] = 0, arr[2] = 1, arr[3] = 1, arr[4] = 4, arr[5] = 3, arr[6] = 10,
		arr[7] = 11, arr[8] = 43, arr[9] = 0, arr[10] = 1, arr[11] = 4, arr[12] = 7, arr[13] = 01,
		arr[14] = 47;
	//fillArray(arr, n);
	cout << "Array: -> ";
	printArray(arr, n);
	quickSort(arr, 0, n - 1);
	deleteRepeated(arr, n);
	cout << "Array after ordering and removing the repeated elements: ";
	printArray(arr, n);
	IBTS(arr, 0, n - 1);
	print(root, 10);
	return 0;
}