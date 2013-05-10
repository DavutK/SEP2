/*
 * SensorikIntro.h
 */

#ifndef SENSORIKINTRO_H_
#define SENSORIKINTRO_H_

#include <stdint.h>

#include "HAWThread.h"

const struct sigevent * ISR (void *arg, int id);

namespace hal {

    class Sensorik: public thread::HAWThread {
    private:
        static Sensorik* instance;

        int isrChid;
        int interruptId;
        struct sigevent event;

        int signalChid;
        int signalCoid;

        uint8_t portBstatus;
        uint8_t portCstatus;

        Sensorik();

    public:
        ~Sensorik();
        static Sensorik* getInstance();

        void stop(); // HAWThread: stop -> virtual

    protected:
        virtual void execute(void* arg);
        virtual void shutdown();

    private:
        void initInterrupts();
    };
}

#endif /* Sensorik_H_ */
