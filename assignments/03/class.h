#ifndef CLASS_H
#define CLASS_H
#include<iostream>
#include<string>
class Juice{
    private:
        std::string name;
        std::string owner;
        const int sweetness;
        int remained_num;
        int price;
        bool is_valid_num(int num);
        
    public:
        Juice();
        Juice(const std::string name, std::string owner, int remained, int price);
        Juice(const Juice& j);
        ~Juice();
        int getData() const;
        int get_price() const;
        std::string get_owner_name() const;
        std::string get_name() const;
        void change_owner(const std::string new_owner);
        void set_price(int price);
        int  sell(int num); // sell num cups of Juice and return the money earned.
        void make(int num); // make num cups of Juice;
        void change_price(const int new_price);
};

#endif