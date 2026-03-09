#include<iostream>

#include "class.h"
#include <stdexcept>

Juice::Juice(): name("orange"), owner("cs106_class"), 
                sweetness(1), price(2), remained_num(0){}
Juice::Juice(const std::string name, std::string owner, int remained, int price): 
    name(name), sweetness(1), owner(owner), remained_num(remained), price(price){}

Juice::Juice(const Juice& j):name(j.name), sweetness(j.sweetness), 
                    owner(j.owner), remained_num(j.remained_num), price(j.price){}
Juice::~Juice(){}
bool Juice::is_valid_num(int num){
    return num >= 0;
}

int Juice::getData() const {
    return sweetness;
}

int Juice::get_price() const {
    return price;
}

std::string Juice::get_owner_name() const {
    return owner;
}

std::string Juice::get_name() const {
    return name;
}

void Juice::change_owner(const std::string new_owner){
    owner = new_owner;
}

void Juice::set_price(int price){
    this->price = price;
}

int  Juice::sell(int num){
    int total = 0;
    if (num > remained_num){
        total = remained_num * price;
        std::cout << "Not enough cups! You bought " << remained_num << " this time." << std::endl;
        remained_num = 0;
    }
    else{
        total = num * price;
        std::cout << "You bought " << num << " this time." << std::endl;
        remained_num -= num;
        std::cout << "There are " << remained_num << " cups left." << std::endl;
    }

    return total;
} // sell num cups of Juice and return the money earned.
        
void Juice::make(int num){
    if (num <= 0){
        throw std::invalid_argument("Invalid number.");
    }
    remained_num += num;
} // make num cups of Juice;
        
void Juice::change_price(const int new_price){
    this->price = new_price;
}