#include <vector>
#include <stack>
#include <set>
#include "SortFunc.h"
#include <iostream>
template<typename T> void BubbleSort(std::vector<T>& dataList) {
	int len = dataList.size();
	for (int i = 0; i < len; i++) {
		bool flag = true;
		for (int j = 0; j < len - i - 1; j++) {
			if (dataList[j] > dataList[j + 1]) {
				T tmp = dataList[j];
				dataList[j] = dataList[j + 1];
				dataList[j + 1] = tmp;
				flag = false;
			}
		}
		if (flag)
			break;
	}
}
template void BubbleSort(std::vector<int>& dataList);
template<typename T> void SelectSort(std::vector<T>& dataList) {

}