//
// Created by shosh on 5/19/24.
//

#ifndef LABWORK6_SPORTTEAM_H
#define LABWORK6_SPORTTEAM_H
#include "string"

struct SportTeam {
  int count_of_players;
  double coef_at_Shorohovs;
  bool isDinamoPinsk;
  char name[10];
  int count_of_GOOOOOOLS[10];
  explicit SportTeam(std::string initializer);
  SportTeam();
};


#endif //LABWORK6_SPORTTEAM_H
