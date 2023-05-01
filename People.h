//
// People.h
// 2023-05-01
// Ivan Konishchev
//

#pragma once
#include <string>

class People
{
  std::string _name;
  int _age{-1};
  int _peopleID{-1};
  static int _id;

public:
  People() = default;
  People(const std::string &name) : _name(name), _age(-1), _peopleID(_id++) {}
  People(const std::string &name, int age) : _name(name), _age(age), _peopleID(_id++) {}
  People(const std::string &&name) : _name(name), _age(-1), _peopleID(_id++) {}
  People(const std::string &&name, int age) : _name(name), _age(age), _peopleID(_id++) {}
  
  std::string getName() const
  {
    return _name;
  }
  
  int getId() const{
    return _peopleID;
  }
};