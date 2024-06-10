//
// Created by shosh on 5/19/24.
//

#include "SportTeam.h"

SportTeam::SportTeam(std::string initializer) {
  count_of_players = initializer[1];
  coef_at_Shorohovs = (double)initializer[2];
  isDinamoPinsk = initializer[3] % 2;
  for (int i = 4; i < 14; i++) {
      name[i - 4] = initializer[i];
  }
  for (int i = 15; i < 25; i++) {
      count_of_GOOOOOOLS[i - 15] = initializer[i];
  }
}

SportTeam::SportTeam() {

}
