#pragma once
#include "common.h"
#define MAX_PRODUCT_NUM 1000


class Product
{
private:
	int arrayNum;
	string name;
	string company;
	string sellerId;
	int price;
	int quantity;
	double averagePurchaseSatisfaction;
public:
	Product(string sellerId, string name, string company, int price, int quantity, double averagePurchaseSatisfaction) {
		this->sellerId;
		this->name = name;
		this->company = company;
		this->price = price;
		this->quantity = quantity;
		this->averagePurchaseSatisfaction = averagePurchaseSatisfaction;
	}

	Product(string name) {
		this->name = name;
	}

	bool productNameCheck();
	void createNewProduct();
	void getProductDetails();

	string getSellerId();
	string getName();
	string getCompany();
	int getPrice();
	int getQuantity();
	double getAveragePurchaseSatisfaction();
};

