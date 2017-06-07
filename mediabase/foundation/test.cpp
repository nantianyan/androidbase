#include <stdio.h>
#include <media/stagefright/foundation/AString.h>
#include <ABitReader.h>
#include <AHandler.h>
#include <AMessage.h>
#include <utils/RefBase.h>
#include <unistd.h>

using namespace android;

struct MediaSender : public AHandler {
    enum { //message to notify others.
        kWhatInitDone = 'init',
    };
    MediaSender(){
        ALOGD("MediaSender\n");
    }

    void hello() {
        (new AMessage(kWhatHello, this))->post();
    }
protected:
    enum {
        kWhatHello = 'hell',
    };

    virtual void onMessageReceived(const sp<AMessage> &msg) {
        switch (msg->what()) {
            case kWhatHello:
            {
                ALOGD("some body is say hello to me ..... \n");
                usleep(1000000ll);
                hello();
                break;    
            }
           case kWhatSenderNotify:
            {
                ALOGD("kWhatSenderNotify");
                break;
            }

            default:
                exit(0);
                //TRESPASS();
            }
    }

    virtual ~MediaSender() {
        ALOGD("~MediaSender");
    }
private:
    enum { //give the message channal to others who can use it to notify me.
        kWhatSenderNotify,
    };

    DISALLOW_EVIL_CONSTRUCTORS(MediaSender);
};


int main(void) {
    /*
    printf("hello\n");
    AString body;
    AString req = "SET_PARAMETER rtsp://localhost/wfd1.0 RTSP/1.0\r\n";
    printf("req is:%s \n", req.c_str());
    */
    sp<ALooper> pullLooper = new ALooper;
    pullLooper->setName("pull_looper");
    pullLooper->start(
        false /* runOnCallingThread */,
        false /* canCallJava */,
        PRIORITY_AUDIO);

    sp<MediaSender> ms = new MediaSender();
    pullLooper->registerHandler(ms);

    ms->hello();

    usleep(5000000ll);

//    pullLooper = unregisterHandler(ms);

    return 0;
}
