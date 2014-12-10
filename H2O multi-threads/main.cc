#include <set>
#include <iostream>
#include "marine/mutex.hh"
#include "marine/threads.hh"

using namespace std;
using namespace marine;

CMutex m;
CCondition hc, oc;
set<pthread_t> hq, oq;

void * H(void * arg) {
    bool w = true;
	m.lock();
    cout<<"generate H in "<<pthread_self()<<"\n";
	hq.insert(pthread_self());
	if(hq.size() > 1 && !oq.empty()){
		hc.signal();
        w = (hq.size() > 2);
        if(w)
            hc.signal();
		oc.signal();
	}
    if(w)
        hc.wait(m);
	hq.erase(pthread_self());
    cout<<"consume H in "<<pthread_self()<<"\n";
	m.unlock();
    return NULL;
}

void * O(void * arg) {
    bool w = true;
	m.lock();
    cout<<"generate O in "<<pthread_self()<<"\n";
	oq.insert(pthread_self());
	if(hq.size() > 1 && !oq.empty()){
		hc.signal();
		hc.signal();
        w = (oq.size() > 1);
        if(w)
            oc.signal();
	}
    if(w)
        oc.wait(m);
	oq.erase(pthread_self());
    cout<<"consume O in "<<pthread_self()<<"\n";
	m.unlock();
    return NULL;
}

int main()
{
    CThread th[8], to[4];
    for(int i = 0;i < 7;++i)
        th[i].start(H);
    for(int i = 0;i < 4;++i){
        sleep(1);
        to[i].start(O);
    }
    th[7].start(H);
    for(size_t i = 0;i < ARRAY_SIZE(th);++i)
        th[i].join();
    for(size_t i = 0;i < ARRAY_SIZE(to);++i)
        to[i].join();
    return 0;
}
