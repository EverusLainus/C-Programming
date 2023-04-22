#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <deque> 

using namespace std;

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish_time_()
    {}

    Response Process(const Request &request) {
        long long startTime=0;
        int drop=0;
        
//if older requests are expired rememove from queue finish_time_
        while((finish_time_.size()!=0) && (finish_time_.front()<= request.arrival_time)){
		finish_time_.pop_front();        
	    }
//if finish_time queue is empty set start time and push finish time to queue
        if(finish_time_.size()==0){
            startTime=request.arrival_time;
            finish_time_.push_front(startTime+request.process_time);
            Response result(drop,startTime);
            return result; 
        }

        if(finish_time_.size()>=size_){//if buffer is full drop
            drop = 1;
            Response result(drop,startTime);
            return result;
        }
        else{//there is a space
//last finish time is is over before new arrival time
            if( finish_time_.back() <= request.arrival_time){
                startTime = request.arrival_time;
            }
            else{//last finish time is still on
                startTime = finish_time_.back();
            } 
        }
            finish_time_.push_back(startTime+request.process_time);
            Response result(drop,startTime);
            return result;
    }

private:
    int size_;
    std::deque <long long> finish_time_;
};

std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i){
 //       cout << "For Requests No "<<i<<endl;
        responses.push_back(buffer->Process(requests[i]));
    }        
    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    long long size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
/*
2 3
0 2
1 4
5 3

2 2
0 1
0 1

1 1
0 0

2 2
0 2
1 1

1 2
0 1
1 1

1 2
0 1
0 1

2 5
1 1
1 0
1 0
1 0
14 0
1
2
-1
-1
14

*/

