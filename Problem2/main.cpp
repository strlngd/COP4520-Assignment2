#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>

class GQueue {
public:
    GQueue() = default;

    void enq(int item) {
        mtx.lock();
        queue.push(item);
        mtx.unlock();
    }

    int deq() {
        mtx.lock();
        if(queue.empty()){
            return -1;
        }
        int item = queue.front();
        queue.pop();
        mtx.unlock();
        return item;
    }
private:
    std::queue<int> queue;
    std::mutex mtx;
};

int total_guests = 8;
bool ready = true;
int in_room = -1;
void guest(int guestNum);

int guests_waiting = 0;
bool* in_line;
GQueue guest_queue;

int main(int argc, char* argv[]) {
    srand(time(nullptr));
    if(argc > 1)
        total_guests = std::stoi(argv[1]);

    in_line = new bool[total_guests] {false};
    std::vector<std::thread> threads;

    // start guest threads
    for(int i = 0; i < total_guests; i++){
        threads.emplace_back(guest, i);
    }
    while(ready){
        while(guests_waiting < 1) {} // wait until a guest is in line
        in_room = guest_queue.deq();
        guests_waiting--;
        std::cout << "Guest " << in_room << " has entered the showroom." << std::endl;
        while(in_room != -1) { // spend some time in the room
            int roll = rand() % 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            if(roll == 0) break;
        }
        std::cout << "Guest " << in_room << " has left the showroom." << std::endl;
        in_line[in_room] = false;
    }

    return 0;
}

void guest(int guestNumber){
    while(ready){
        if(in_line[guestNumber]) { // already waiting in line so do nothing
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            continue;
        }

        int roll = rand() % 10;
        if(roll == 0){ // queue in line
            in_line[guestNumber] = true;
            guest_queue.enq(guestNumber);
            guests_waiting++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}