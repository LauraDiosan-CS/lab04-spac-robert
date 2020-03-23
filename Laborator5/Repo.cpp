#include "Repo.h"

Repo::Repo() {

	this->len = 0;
}

Repo::~Repo() {
	this->len = 0;
}

void Repo::insert(Shop expence) {
	this->array[this->len++] = expence;
}

int Repo::get_len() {
	return this->len;
}

Shop* Repo::get_all() {
	return this->array;
}

//void Repo::set_len(int new_len) {
//	this->len= new_len;
//}

void Repo::update(Shop shop) {

	int n = this->get_len();
	Shop* vector = this->get_all();

	for (int i = 0; i < n; i++) {
		if (strcmp(shop.get_name(), vector[i].get_name()) == 0) {
			vector[i] = shop;
		}
	}

}

void Repo::delete_shop(char* name) {
	
	for (int i = 0; i < this->len; i++) {
		if (strcmp(name, this->array[i].get_name()) == 0) {
			while (i < this->len) {
				if (i + 1 < this->len)
					this->array[i] = this->array[i + 1];
				i++;
			}
			this->len--;
		}
	}
}