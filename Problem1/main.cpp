#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

void labyrinth(int guestNum);

bool has_cupcake = true;
int total_guests = 8;
int total_cupcakes_eaten = 0;
int labyrinth_entries = 0;
bool ready = true;
bool* ate_cupcake;

int main(int argc, char* argv[]) {
    srand(time(nullptr));
    if(argc > 1)
        total_guests = std::stoi(argv[1]);

    ate_cupcake = new bool[total_guests] {false};

    std::vector<std::thread> threads;

    // declare guest threads
    threads.emplace_back(); // manager guest
    for(int i = 0; i < total_guests - 1; i++){
        threads.emplace_back(); // normal guest
    }

    auto start = std::chrono::high_resolution_clock::now();

    while(ready){
        int n = rand() % total_guests; // pick a guest
        threads[n] = std::thread(labyrinth, n); // send them to the labyrinth
        threads[n].join(); // wait for guest to finish before sending in the next guest
    }

    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> runtime = end - start;

    // Output
    std::cout << "All guests have entered the labyrinth!" << std::endl;
    std::cout << "Finished in: " << runtime.count() << "ms" << std::endl;
    std::cout << "Total entries into the labyrinth: " << labyrinth_entries << std::endl;

    return 0;
}

void labyrinth(int guestNum){
    labyrinth_entries++;
    if(guestNum == 0){
        if(!has_cupcake){
            has_cupcake = true; // reset cupcake
            total_cupcakes_eaten++; // add to counter

            if(total_cupcakes_eaten == total_guests - 1) // -1 since we don't need to include the manager in the count{
                ready = false; // When total is met, stop threads
        }
    }
    else {
        if(has_cupcake && !ate_cupcake[guestNum]){
            // eat cupcake
            has_cupcake = false;
            ate_cupcake[guestNum] = true;
        }
    }
}