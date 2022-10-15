#include "List.h"
#include <iostream>

using namespace std;

void printElements(TList head) {
	while (!isEmpty(head)) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void addElements(TList &list, int *arr, int n) {
	addToHead(list, *(arr + 0));
	TList current = list;
	for (int i = 1; i < n; i++) {
		addAfterNode(list, *(arr + i));
		list = list->next;
	}
	list = current;
}

TList LongInclude(TList Xs, TList Ys) {
	TList cur_first = Xs;
	TList max_first = Xs;
	TList h_Ys = Ys;
	
	int max = 0, current = 0;
	
	while (!isEmpty(Xs)) {
		bool flag = false;
		
		while (!isEmpty(h_Ys)) {
			if (Xs->data == h_Ys->data) {
				if (current == 0) cur_first = Xs;
				flag = true;
				current += 1;
				h_Ys = h_Ys->next;
				break;
			}
			h_Ys = h_Ys->next;
		}
		h_Ys = Ys; 
		if ((!flag or isEmpty(Xs->next))&& current > max)
		{
			max = current;
			current = 0;
			max_first = cur_first;
		}
		Xs = Xs->next;
	}

	int* arr_include = new int[max];
	for (int i = 0; i < max; i++) {
		*(arr_include + i) = max_first->data;
		max_first = max_first->next;
	}

	TList LongInclude;
	init(LongInclude);
	addElements(LongInclude, arr_include, max);
	return LongInclude;
}



int main()
{
	TList Xs;
	init(Xs);
	TList Ys;
	init(Ys);
	int a[20] = { 1, 2, 1, 2, 4, 2, 1, 1, 1, 2, 1, 2, 2, 5, 1, 2, 5, 1, 1, 1 };
	int b[2] = { 1, 2 };
    addElements(Xs, a, 20);
	cout << "=====================" << endl;
	printElements(Xs);
	cout << endl;
	addElements(Ys, b, 2);
	printElements(Ys);
	cout << "=====================" << endl;
	TList XY = LongInclude(Xs, Ys);
	printElements(XY);
	cout << "=====================" << endl;
}