# Assignment 2 Problem 1 (COP4520)
Created by Sterling Downs for Concepts of Parallel and Distributed Processing

## Problem
The Minotaur invited N guests to his birthday party. When the guests arrived, he made the following announcement.

The guests may enter his labyrinth, one at a time and only when he invites them to do so. At the end of the labyrinth, the Minotaur placed a birthday cupcake on a plate. When a guest finds a way out of the labyrinth, he or she may decide to eat the birthday cupcake or leave it. If the cupcake is eaten by the previous guest, the next guest will find the cupcake plate empty and may request another cupcake by asking the Minotaur’s servants. When the servants bring a new cupcake the guest may decide to eat it or leave it on the plate.

The Minotaur’s only request for each guest is to not talk to the other guests about her or his visit to the labyrinth after the game has started. The guests are allowed to come up with a strategy prior to the beginning of the game. There are many birthday cupcakes, so the Minotaur may pick the same guests multiple times and ask them to enter the labyrinth. Before the party is over, the Minotaur wants to know if all of his guests have had the chance to enter his labyrinth. To do so, the guests must announce that they have all visited the labyrinth at least once.

Now the guests must come up with a strategy to let the Minotaur know that every guest entered the Minotaur’s labyrinth. It is known that there is already a birthday cupcake left at the labyrinth’s exit at the start of the game. How would the guests do this and not disappoint his generous and a bit temperamental host?

Create a program to simulate the winning strategy (protocol) where each guest is represented by one running thread. In your program you can choose a concrete number for N or ask the user to specify N at the start.

## Installation & Usage
To compile this program, use g++.
You can simply use the following commands:
```
g++ main.cpp
./a.out
```
Additionally, you can supply an argument in the 2nd command, specifying N number of guests.
Otherwise, it will default to 8 guests.

## Output
The program will print all output to the console.
The output is in the following format:
```
All guests have entered the labyrinth!
Finished in: XX.XXms
Total entries into the labyrinth: X
...
```

## Proof of Correctness
This program declares N number of threads matching the guest count. One of these threads 
is designated as the manager thread and has a different role then the rest. A roll then occurs to
determine which guest enters the labyrinth. A thread for that guests is then started and the guest decides 
whether or not to eat the cupcake. They will eat the cupcake if they are not the manager, the cupcake is still there, 
and they have never eaten a cupcake. Otherwise, they will do nothing. When the manager enters, if the cupcake has been eaten, 
they will add 1 to a counter and then replace the cupcake. This continues until the manager declares that all guests have 
entered the labyrinth.

## Efficiency
This program was tested on an i5-9600k CPU @4.60GHz with 6 cores and 6 threads.

In terms of efficiency, this solution has a runtime of O(N^2)

## Evaluation
This program was quite vague, and as such required me to make a few adjustments. My first iteration of this program involved 
each guest as a thread that was always running (until all guests have entered) and fighting for a lock.
This resulted in greedy threads, and while fast, it was not very efficient. The new design might be slower, but 
it is more efficient as it runs in O(N^2).