#include "Service.h"

void Service::insert_service(char* name, char* date, int price) {
	Shop shop(name,date,price);
	repo.insert(shop);
}
Shop* Service::get_all() {
	return this->repo.get_all();
}
int Service::get_len() {
	return this->repo.get_len();
}
void Service::update_shop(char* name, char* date, int price) {
	Shop shop(name, date, price);
	this->repo.update(shop);
}
//void Service::set_len(int new_len) {
//	this->repo.set_len(new_len);
//}
void Service::delete_shop(char* name) {
	this->repo.delete_shop(name);
}