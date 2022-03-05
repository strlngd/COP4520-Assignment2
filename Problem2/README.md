# Assignment 2 Problem 2 (COP4520)
Created by Sterling Downs for Concepts of Parallel and Distributed Processing

## Problem
The Minotaur decided to show his favorite crystal vase to his guests in a dedicated showroom with a single door. He did not want many guests to gather around the vase and accidentally break it. For this reason, he would allow only one guest at a time into the showroom. He asked his guests to choose from one of three possible strategies for viewing the Minotaur’s favorite crystal vase:

1) Any guest could stop by and check whether the showroom’s door is open at any time and try to enter the room. While this would allow the guests to roam around the castle and enjoy the party, this strategy may also cause large crowds of eager guests to gather around the door. A particular guest wanting to see the vase would also have no guarantee that she or he will be able to do so and when.

2) The Minotaur’s second strategy allowed the guests to place a sign on the door indicating when the showroom is available. The sign would read “AVAILABLE” or “BUSY.” Every guest is responsible to set the sign to “BUSY” when entering the showroom and back to “AVAILABLE” upon exit. That way guests would not bother trying to go to the showroom if it is not available.

3) The third strategy would allow the quests to line in a queue. Every guest exiting the room was responsible to notify the guest standing in front of the queue that the showroom is available. Guests were allowed to queue multiple times.

Which of these three strategies should the guests choose? Please discuss the advantages and disadvantages.

Implement the strategy/protocol of your choice where each guest is represented by 1 running thread. You can choose a concrete number for the number of guests or ask the user to specify it at the start.

## Addressing the Problem
1: The advantages of this approach is that a guest can try to enter the room whenever they want. They can either wait for a period of time or go do something else.
The disavantage of this approach is that it is very chaotic. In other words, each guest is competing with all of the other waiting guests to get into the room and there is no guarantee that they will be able to do so.

2: The advantage to this approach is that guests are not waiting. They are free to do other things.
The disavantage is that this approach may take much longer than the others. This is due to the high chance
that there will be time spent with the room being AVAILABLE with no guests showing up for a while to check this status.
This is because guests won't bother trying to go to the showroom if it is not avaiable. If they were allowed to wait, this approach wouldn't be much different from #1.

3: The advantage of this approach is that it is fair. Guests have prioritized access to the room based on their position in the queue.
    The disavantage is that the guest is not able to roam around the castle and enjoy the party while waiting in this queue.   

The strategy the guests should choose depends on what the intentions of the guests are.
If the guests want to be able to make the most of their time with no guarantee of entering the room, they should choose #1.
As for the second approach, it is very similar to the first. However, it has an extra step involved and also doesn't give guests the option to wait.
The third approach does give the guest a guarantee of entering the room provided that they are able to wait long enough. But it also means that the guest isn't doing anything meaningful while waiting in line in the queue.

## Installation & Usage
To compile this program, use g++.
You can simply use the following commands:
```
g++ main.cpp
./a.out
```
Additionally, you can supply an argument in the 2nd command, specifying N number of guests.

## Output
The program will print all output to the console.
The output is in the following format:
```
Guest X has entered the showroom.
Guest X has left the showroom.
...
```

## Proof of Correctness
This program makes uses of a thread-safe queue for enqueueing and dequeueing guests in line.
Each guest spends time rolling a number between 0 and 9 and waiting between each roll until they reach the number 0.
Upon reaching the number zero, they queue in line. After the previous guest leaves the show-room or the show-room is 
empty, the next guest in line can enter the show-room alone. A similar rolling process occurs to determine how long 
the guest stays in the room for. The process then repeats.

## Efficiency
This program was tested on an i5-9600k CPU @4.60GHz with 6 cores and 6 threads.

In terms of efficiency, this solution is not the most efficient due to the added overhead of locking/unlocking 
and managing a queue. However, this solution is fair to the guests as a guest near the start of the line is guaranteed 
to enter the show-room before a guest at the end of the line.

## Evaluation
In my opinion, without further information, there is no correct solution regarding the implementation that best suits 
this issue. Therefore, I went with the most practical solution that ensured fairness between guests.