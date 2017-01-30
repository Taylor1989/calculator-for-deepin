/*
* Copyright (C) 2017 rekols@foxmail.com(Juns Steven)

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <stack>

using namespace std;

class Algorithm
{
public:
    string InfixToPostfix(string infix);
    double posfixCompute(string s);
    double expressionCalculate(string s);
    string GetlastChar(string s);
};

#endif // ALGORITHM_H
