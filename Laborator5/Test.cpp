#include "Test.h"
#include "Repo.h"
#include <cassert>
#include "Service.h"
#include <iostream>
void test_service() {

	char* nume1 = new char[101], * person1 = new char[10];
	char* nume2 = new char[101], * person2 = new char[10];
	char* date3 = new char[101], * persoana3 = new char[100];

	strcpy_s(nume1, sizeof "12.02.2020", "12.02.2020");
	strcpy_s(person1, sizeof "Ana", "Ana");
	Shop s1(person1, nume1, 23);
	strcpy_s(person2, sizeof "Alin", "Alin");
	strcpy_s(nume2, sizeof "02.02.2020", "02.02.2020");
	Shop s2(person2, nume2, 14);
	char* name = new char[20];
	strcpy_s(persoana3, sizeof"Ioana", "Ioana");

	Shop s3(persoana3, date3, 8);
	Repo repo;
	Shop expence[2];
	expence[0] = s1;
	expence[1] = s2;

	repo.insert(s1);
	repo.insert(s2);
	assert(repo.get_len() == 2);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == expence[i]);
	}

	//Update

	Service service;
	service.update_shop(persoana3, date3, 8);
	for (int i = 0; i < service.get_len(); i++) {
		assert(service.get_all()[i] == expence[i]);
	}


	//Delete

	Shop expence1[1];
	expence1[0] = s2;
	name = new char[1 + strlen("Ana")];
	strcpy_s(name, 1 + strlen("Ana"), "Ana");
	service.delete_shop(name);
	for (int i = 0; i < service.get_len(); i++) {
		assert(service.get_all()[i] == expence1[i]);
	}
}

void tests() {

	test_service();
	char* nume1 = new char[101], * person1 = new char[10];
	char* nume2 = new char[101], * person2 = new char[10];
	char* date3 = new char[101], * persoana3 = new char[100];

	strcpy_s(nume1, sizeof "12.02.2020", "12.02.2020");
	strcpy_s(person1, sizeof "Ana", "Ana");
	Shop s1(person1,nume1, 23);
	strcpy_s(person2, sizeof "Alin", "Alin");
	strcpy_s(nume2, sizeof "02.02.2020", "02.02.2020");
	Shop s2(person2,nume2, 14);
	char* name = new char[20];
	strcpy_s(persoana3, sizeof"Ioana", "Ioana");

	Shop s3(persoana3, date3, 8);
	Repo repo;
	Shop expence[2];
	expence[0] = s1;
	expence[1] = s2;

	repo.insert(s1);
	repo.insert(s2);
	assert(repo.get_len() == 2);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == expence[i]);
	}

	//Update
	
	repo.update(s3);
	assert(repo.get_len() == 2);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == expence[i]);
	}
	Service service;


	//Delete

	Shop expence1[1];
	expence1[0] = s2;
	name = new char[1 + strlen("Ana")];
	strcpy_s(name, 1 + strlen("Ana"), "Ana");
	repo.delete_shop(name);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == expence1[i]);
	}

}