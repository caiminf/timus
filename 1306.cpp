#include <iostream>
using namespace std;

typedef unsigned int uint;
const int MAX = 125050;

class MaxHeap
{
private:
	int heap[MAX];
	int len;
public:
	MaxHeap()
	{
		len = 0;
		memset(heap, 0, MAX);
	}
	MaxHeap(uint *arr, int n){
		len = n;
		memset(heap, 0, MAX);
		build(arr, n);
	}
	int parent(int i){
		return i / 2;
	}
	int left(int i){
		return i * 2;
	}
	int right(int i){
		return i * 2 + 1;
	}
	void heapify(int i){
		int l = left(i);
		int r = right(i);
		int largest;
		if (l <= len && heap[l] > heap[i]){
			largest = l;
		}
		else{
			largest = i;
		}
		if (r <= len && heap[r] > heap[largest]){
			largest = r;
		}
		if (largest != i){
			swap(heap[i], heap[largest]);
			heapify(largest);
		}
	}
	void build(uint *arr, int n){
		for (int i = 0; i < n; ++i){
			heap[i + 1] = arr[i];
		}
		for (int i = len / 2; i >= 1; i--){
			heapify(i);
		}
	}
	uint maximum(){
		return heap[1];
	}
	uint extractMax(){
		if (len < 1)cout << "error, returning -1" << endl;
		uint max = heap[1];
		heap[1] = heap[len];
		len--;
		heapify(1);
		return max;
	}
	void increaseKey(int i, uint key){
		if (key < heap[i]){
			cout << "new key is samller than current key" << endl;
			return;
		}
		heap[i] = key;
		while (i > 1 && heap[parent(i)] < heap[i]){
			swap(heap[i], heap[parent(i)]);
			i = parent(i);
		}
	}
	void insert(uint key){
		len++;
		heap[len] = 0;
		increaseKey(len, key);
	}
	int length(){
		return len;
	}
	void print(){
		for (int i = 1; i <= len; i++){
			cout << heap[i] << endl;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	MaxHeap mHeap;
	uint tmp;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		if (i <= n / 2){
			mHeap.insert(tmp);
		}
		else{
			mHeap.insert(tmp);
			mHeap.extractMax();
		}
	}
	uint num1, num2;
	if (n % 2 != 0){
		cout << mHeap.extractMax() << ".0" << endl;
	}
	else{
		num1 = mHeap.extractMax();
		num2 = mHeap.extractMax();
		if ((num1 + num2) % 2 == 0){
			cout << (num1 + num2) / 2 << ".0" << endl;
		}
		else{
			cout << (num1 + num2) / 2 << ".5" << endl;
		}
	}
	return 0;
}