/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);
  
  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  // Part 1
  friend std::ostream& operator<<(std::ostream& os, const User& user);

  // Part 2
  ~User();
  User(const User& user);
  User operator=(const User& user);

  User(User&& user) = delete;             // 禁止 move construction
  User& operator=(User&& user) = delete;  // 禁止 move assignment
  // 上面最后两行确实是我不会的部分，设置函数为delete是为了防止右值操作.

  // Part 3
  User& operator+=(User& rhs);
  bool operator<(const User& rhs) const;

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};