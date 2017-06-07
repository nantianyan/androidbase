#include "stdio.h"

#include <stdint.h>
#include <sys/types.h>
//#include "stdatomic.h"
#include <cutils/atomic.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>
#include <utils/Log.h>
#include <utils/String8.h>
#include <utils/threads.h>
#include <utils/Vector.h>

using namespace android;

struct MyClass : public RefBase {
    bool mybool;
    int myint;
    void hello(void) {
        ALOGD("myint:%d, mybool:%d\n", myint, mybool);
    }
};

class MyThread : public Thread {
    int mDelayMillis;

public:
    MyThread(int delayMillis) : mDelayMillis(delayMillis), Thread(true/*canCallJava*/) {
        printf("Thread\n");
    }

protected:
    virtual ~MyThread() {
        printf("~Thread\n");
    }

    void doTask() {
        printf("hahhahha\n");
    }

    bool threadLoop() {
        printf("threadLoop\n");
        usleep(mDelayMillis * 1000);
        doTask();
        return false; // only run once
    }
};

int main(void) {
    /*
    int32_t i = 0;
    i++;
    android_atomic_inc(&i);
    printf("hello %d\n", i);
    */

    /*
    sp<MyClass> mc = new MyClass;
    mc->myint = 10;
    ALOGD("myint:%d \n", mc->myint);
    mc->hello();
    */

    /*
    String8* str= new String8("hello world");
    str->append(" yxd\n");
    ALOGD("%s", str->string());
    */

    /*
    sp<MyThread> pTh = new MyThread(1000);
    pTh->run();
    pTh->join();
    */

    Vector<int32_t > iv;
    iv.push(12);
    iv.push_back(13);
    iv.push_back(14);
    iv.push_back(15);
    printf("*begin:%d \n", *iv.begin());
    Vector<int32_t >::iterator it = iv.begin();
    printf("size:%d \n", iv.size());
    //iv.erase(iv.begin() + iv.size());

    return 0;
}
