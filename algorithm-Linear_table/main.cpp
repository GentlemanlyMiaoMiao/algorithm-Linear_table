#include <iostream>
#include <memory.h>
using namespace std;
class Vector
{
private :
	int *content;
	int lenght;
	int count;
public:
	Vector() {
		this->content = 0;
		this->lenght = 0;
		this->count = 0;
	}
//构造函数
	Vector(int *arr, int lenght, int count) {
		content = new int[lenght];
		this->lenght = lenght;
		this->count = count;
		memcpy(content,arr,sizeof(int)*count);
	}

	Vector(int size) {
		content = new int[size];
		this->lenght = size;
		this->count = 0;
	}

	Vector(int *arr, int size) {
		content = new int[size];
		this->lenght = size;
		this->count = count;
		memcpy(content, arr, sizeof(int)*lenght);
	}
//插入
	void insert(int elem) {
		int a = 0;
		int *p= content;
		int *q =content;
		count = count + 1;
		while (*content < elem && a < lenght) {
			content++;
			a++;
		}
		if (a == lenght) {
			*content = elem;
		}
		else {
			for (int i = 0; i < lenght - a;i++) {
				*(content + (lenght-a -1)- i) = *(content + (lenght-a -1)- i - 1);
			}
			*content = elem;
		}
		content=q;
		for (int i = 0; i < count; i++) {
			std::cout << *(p +i)<<',';
		}
		std::cout <<endl;
	}
	void shift_right(int offset) {
		int a;
		int *p = content;
		int *q = content + count-1;
		for (int i = 0; i < offset; i++) {
			a = *q;
			for (int j = 0; j <count; j++) {

				*(q - j) = *(q - j - 1);
			}
			*p = a;
		}
		content = p;
		for (int i = 0; i < count; i++) {
			std::cout << *(p + i) << ',';
		}

	}

	void revese()
	{
		int a, i = 0;
		int *p = content;
		int *q = content+count-1;
		for (int i = 0; i < count/2; i++) {
			a = *content;
			*content = *q;
			*q = a;
			content++;
			q--;

		}
		content = p;
		for (int i = 0; i < count; i++) {
			std::cout << *(p + i) << ',';
		}
		std::cout << endl;
	}
};


int main() {
	int arr[20] = {12,23,34,45,56,67,78};
	Vector *myv = new Vector(arr, 20, 7);
	myv->insert(15);
	myv->revese();
	myv->shift_right(3);


}