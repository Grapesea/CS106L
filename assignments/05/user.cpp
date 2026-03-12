#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */

// Part 1

std::ostream& operator<<(std::ostream& os, const User& user){
  os << "User(name=" << user._name << ", friends=[";
  
  for (size_t i = 0; i < user._size; ++i){
    if (i > 0)
      os << ", ";
    os << user._friends[i];
  }
  os << "])";
  return os;
}

// Part 2

User::~User(){
  _name = "";
  delete[] _friends;
  _size = 0;
  _capacity = 0;
}

User::User(const User& user): _name(user._name), _size(user._size), _capacity(user._capacity){
  this->_friends = new std::string[_capacity]; // deep copy, first malloc a new memory
  for (size_t i = 0; i < _size; i++){
    this->_friends[i] = user._friends[i];
  }
}

User User::operator=(const User& user){ //拷贝赋值：二者都已经存在
  User temp(user);
  std::swap(_name, temp._name);
  std::swap(_friends, temp._friends);
  std::swap(_size, temp._size);
  std::swap(_capacity, temp._capacity);

  return *this; //这样子temp析构的时候前面的_friends也会销毁掉.
}

// Part 3

User& User::operator+=(User& rhs){
  this->add_friend(rhs._name);
  rhs.add_friend(this->_name);
  return *this;
}

bool User::operator<(const User& rhs) const{
  return this->_name < rhs._name;
}