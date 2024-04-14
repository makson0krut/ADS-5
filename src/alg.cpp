// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    int count = 0, count1 = 0, count2 = 0;
    std::string res;
    std::string exit;
    for (auto c : inf) {
        count += 1;
    }
    for (int i = 0; i < count; ++i) {
        int prior = getPrior(inf[i]);
        char op = inf[i];
        if (prior == -1) {
            vixod.push(inf[i]);
        } else {
            if (prior > getPrior(charstack.peek()) || charstack.isEmpty()) {
                charstack.push(op);
            } else if (prior == 0) {
                charstack.push(op);
            } else if (op == ')') {
                while (prior <= getPrior(charstack.peek())) {
                    if (charstack.peek() != '(' && charstack.peek() != ')') {
                        vixod.push(charstack.peek());
                    }
                    charstack.pop();
                }
                charstack.pop();
            } else {
                while (prior <= getPrior(charstack.peek())) {
                    if (charstack.peek() != '(' && charstack.peek() != ')') {
                        vixod.push(charstack.peek());
                    }
                    charstack.pop();
                }
                charstack.push(op);
            }
        }
    }
    while (!charstack.isEmpty()) {
        if (charstack.peek() != '(' && charstack.peek() != ')') {
            vixod.push(charstack.peek());
        }
        charstack.pop();
    }
    res.resize(count);
    auto it = res.rbegin();
    while (!vixod.isEmpty()) {
        *it = vixod.peek();
        vixod.pop();
        ++it;
        count1 += 1;
    }
    for (auto a : res) {
        if (res.find(' ')) {
            count2 += 1;
        }
    }
    int get = count2 - count1;
    for (int i = get; i < count; ++i) {
        char ex = res[i];
        exit.push_back(ex);
        exit.push_back(' ');
    }
    exit.pop_back();
    return exit;
}

int eval(std::string pref) {
   int count = 0;
   for (auto c : pref) {
       count += 1;
   }
   for (int i = 0; i < count; ++i) {
       if (pref[i] >= 48 && pref[i] <= 57) {
           if (pref[i] == 48)
               intstack.push(0);
           if (pref[i] == 49)
               intstack.push(1);
           if (pref[i] == 50)
               intstack.push(2);
           if (pref[i] == 51)
               intstack.push(3);
           if (pref[i] == 52)
               intstack.push(4);
           if (pref[i] == 53)
               intstack.push(5);
           if (pref[i] == 54)
               intstack.push(6);
           if (pref[i] == 55)
               intstack.push(7);
           if (pref[i] == 56)
               intstack.push(8);
           if (pref[i] == 57)
               intstack.push(9);
       } else if (pref[i] >= 42 && pref[i] <= 47) {
           char oper = pref[i];
           int c = operat(oper);
           intstack.push(c);
       }
   }
   return intstack.peek();
}
