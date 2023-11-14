#include <pthread.h>
#include <iostream>
#include <deque>
#include <vector>
#include <assert.h>

using namespace std;

struct Work{
    void (*f)(void *) = NULL;
    void *arg = NULL;
};

struct ThreadPool{
    vector <pthread_t> threads;
    deque<Work> queue;
    pthread_mutex_t m;
    pthread_cond_t not_empty;
};

void *worker(void *arg){
    //worker code
}

void *producer(void *arg){
    //producer code
}

void thread_pool_init(ThreadPool *tp, size_t n_threads){

//initialise mutex and condition
    assert(n_threads > 0);
    //initialise pthread with attribute as null
    int rv = pthread_mutex_init(&tp->m, NULL);
    assert(rv == 0);
    rv = pthread_cond_init(&tp->not_empty, NULL);
    assert(rv == 0);

    tp->threads.resize(n_threads);
    for(size_t i=0; i<n_threads ; ++i){
        int rv = pthread_create(&tp->threads[i], NULL, &worker, tp);
        assert(rv == 0);
    }
}

int main(){

    ThreadPool *T;
    T =  (ThreadPool *) malloc(sizeof(ThreadPool));
    thread_pool_init(T, 5);

    return 0;
}