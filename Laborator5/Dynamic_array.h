#pragma once
template <typename T>

class Dynamic_array {

private:
	T* arr;
	int len;
	int cap;//capacity

	void expand() {
		cap *= 2;
		T* tempArr = new T[cap];
		for (size_t i = 0; i < len; i++) {
			tempArr[i] = arr[i];
		}
		delete[]arr;
		arr = tempArr;
		//initialize(len);
	}

	/*void initialize(int from) {
		for (size_t i = from; i < cap; i++)
			arr[i] = NULL;
	}*/
	
public:

	Dynamic_array() {
		cap = 10;
		len = 0;
		arr = new T[cap];
	}

	~Dynamic_array() {

		delete[]arr;
	}

	T* getAll() {
		return arr;
	}

	void add(T el) {
		if (this->len >= this->cap)
			expand();
		this->arr[this->len++] = el;
	}

	int len_array() {
		return len;
	}
};