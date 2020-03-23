#pragma once
#include "Repo.h"
class Service {
private:

	Repo repo;

public:

	void insert_service(char*, char*, int);
	int get_len();
	Shop* get_all();
	void update_shop(char*, char*, int);
	/*void set_len(int);*/
	void delete_shop(char*);
};