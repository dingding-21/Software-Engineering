#pragma once
#include "common.h"
#define MAX_PRPDUCT_NUM 1000


class Product
{
private:
	string arryNum;
	string name;
	string company;
	string seller;
	int price;
	int quantity;
public:
	Product(string name, string company, int price, int quantity) {
		this->name = name;
		this->company = company;
		this->price = price;
		this->quantity = quantity;
	}

	bool productNameCheck();
	void createNewProduct();


};

