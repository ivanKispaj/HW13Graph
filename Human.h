//
// Human.h
// 2023-05-01
// Ivan Konishchev
//

#pragma once
#include <string>
#include "People.h"
#define PEOPLE_COUNT 6
#include <iostream>

template <typename T>
class Human
{

    // Связь между людьми
    void peopleСommunication(T &people1, T &people2)
    {
        _link[people1.getId()][people2.getId()] = 1;
        _link[people2.getId()][people1.getId()] = 1;
    }

    // существует ли человек
    bool peopleExist(const T &people) const
    {
        for (int i = 0; i < _countPeople; i++)
        {
            if (_people[i].getId() == people.getId())
            {
                return true;
            }
        }
        return false;
    }

    int _link[PEOPLE_COUNT][PEOPLE_COUNT]{0}; // matrix
    int _countPeople{0};                      // количество людей
    T _people[PEOPLE_COUNT];                  // массив с людьми

public:
    Human() = default;
    std::string getPeopleNmae(int id)
    {
        for (int i = 0; i < _countPeople; i++)
        {
            if (_people[i].getId() == id)
            {
                return _people[i].getName();
            }
        }
        return "";
    }

    // Добавление лжюдей
    void addPeople(T &people)
    {
        if (!peopleExist(people))
        {
            _people[_countPeople] = people;
            _countPeople++;
        }
    }

    // Добавление связи людей по трем рукопожатиям!
    void addCommunoicationWithThreeHandshakes()
    {
        for (int i = 0; i < _countPeople; i++)
        {
            int three{1};
            while (three < 4)
            {
                if (i + three > _countPeople - 1)
                {
                    break;
                }
                peopleСommunication(_people[i], _people[i + three]);
                three++;
            }
        }
    }

// Печать связей людей исходя из 3 рукопожатий
    void printCommunication() const
    {
        for (int i = 0; i < _countPeople; i++)
        {
            for (int j = 0; j < _countPeople; j++)
            {
                if (_link[i][j] == 1)
                {
                    std::cout << _people[i].getName() << " знает " << _people[j].getName() << "\n";
                }
            }
        }
    }
};