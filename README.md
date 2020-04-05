# The Monty Hall Problem
#### programmed by Geoff Ramler on 09/30/2017 in C++

### Rules:
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