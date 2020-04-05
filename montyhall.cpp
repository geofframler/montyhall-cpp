/*
  The Monty Hall Problem
  programmed by Geoff Ramler on 09/30/2017

  Rules:
  A while back there was a show on TV called "Let's Make a Deal", with a host "Monty Hall".
  At a point in the show there were three doors, and behind two doors were goats (losing condition),
  and behind one door there was a car (winning condition).

  The contestant would select a door, and Monty would then open one of the unselected doors that contained a goat.
  This means now, there are two doors, one being a car, and one being a goat.
  Monty then asks if the contestant wants to change to the other door or remain on their selected door.
  Statistically, contestants who remained on their initial decision only had a 1/3 chance of winning,
  and those who changed doors has a 2/3 chance of winning. Write a program that shows this in action.

  Plan:
  Run a simulation 100,000 times in which the computer stays with their first choice.
  Run a simulation 100,000 times in which the computer chooses to switch doors.
  Display the total wins of both simulations to prove the rules.
*/

#include <iostream>
#include <chrono>
#include <cmath>

// Function to round percentage accurately
double round(double number)
{
  return floor(number + 0.5);
}

// The Main Function
int main()
{
  char run;
  // Introduction and Rules
  std::cout << "\n Welcome to LET'S MAKE A DEAL! I'm your host, Monty Hall!                  " << std::endl;
  std::cout << "\n In this game, there are 3 doors. 2 have goats behind them, 1 has a car!   ";
  std::cout << "\n The goal is to find the car.                                              " << std::endl;

  std::cout << "\n After the contestant chooses a door, one of the other two is opened       ";
  std::cout << "\n revealing a goat. The contestant then has the opportunity to keep         ";
  std::cout << "\n the first door they chose, or switch to the other closed door.            " << std::endl;

  std::cout << "\n Contestants should have a 1/3 chance of winning with their first choice,  ";
  std::cout << "\n but a 2/3 chance of winning when they switch to the other closed door.    " << std::endl;

  std::cout << "\n This is a simulation in which a contestant plays 200,000 randomized games.";
  std::cout << "\n In the first 100,000 games, they keep their first choice.                 ";
  std::cout << "\n In the second 100,000 games, they change to the other door.               ";
  std::cout << "\n The totals are displayed in an attempt to prove the rules.                " << std::endl;

  std::cout << "\n Would you like to run the simulation? (y/n): ";

  std::cin >> run;

  // Simulation
  while (run == 'y')
  {
    // Set random seed and calibrate win counters
    srand(time(NULL));
    double winsKeep = 0;
    double winsSwitch = 0;

    // Run simulation 200,000 times
    for (int i = 1; i <= 200000; i++)
    {
      // Randomize doors, two goats and one car
      std::string doors[3] = {"goat", "goat", "goat"};
      doors[rand() % 3] = "car";

      // Contestant chooses a random door
      int doorChoice = rand() % 3;

      // If a door is a goat and is not the contestant's choice, it is removed
      for (int j = 0; j < 3; j++)
      {
        if (doors[j] == "goat" && j != doorChoice)
        {
          doors[j] = "removed";
        }
      }

      // The contestant keeps the first door 100,000 times
      if (i <= 100000)
      {
        for (int k = 0; k < 3; k++)
        {
          if (doors[k] == "car" && k == doorChoice)
            winsKeep++;
        }
      }
      // The contestant switches doors 100,000 times
      else
      {
        for (int s = 0; s < 3; s++)
        {
          if (doors[s] == "goat" && s == doorChoice)
            winsSwitch++;
        }
      }
    }

    std::cout << " __________________________________________________________________________" << std::endl;

    std::cout << "\n Total wins keeping first door:       " << winsKeep << "/100000";
    std::cout << "\n Total wins switching to other door:  " << winsSwitch << "/100000" << std::endl;

    std::cout << "\n Percentage of wins keeping first door:       ~" << round(winsKeep / 1000) << "%";
    std::cout << "\n Percentage of wins switching to other door:  ~" << round(winsSwitch / 1000) << "%" << std::endl;

    std::cout << "\n Would you like to try again? (y/n): ";
    std::cin >> run;
  }

  return 0;
}