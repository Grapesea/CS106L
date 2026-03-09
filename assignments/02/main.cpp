/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Grapesea Aurora"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream data(filename);
  std::string line;
  std::set<std::string> name_result;
  while (getline(data, line)){
    name_result.insert(line);
  }
  return name_result;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */

std::string initials(const std::string name){
  std::string init = "";
  if (!name.empty()){
    init += name[0];
  }
  for (int i = 1; i < (int)name.size()-1; i++){
    if (name[i] == ' ') //不能用双引号，此处name[i]是char，' '是char而" "是const char*
      init += name[i+1];
  }
  return init;
}

std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> p; 
  std::string init = initials(name);

  for (const std::string& i : students){
    if (initials(i) == init){
      p.push(&(i));
    }
  }

  return p;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if (matches.empty()){
    return "NO MATCHES FOUND.";
  }
  return *(matches.front()); // 直接选第一个，懒得想随机方法了.
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
