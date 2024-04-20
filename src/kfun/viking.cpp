#ifndef FUNCDEF
#define INCLUDE_FILE_IO
#define INCLUDE_CTYPE
#include "kfun.h"
#endif

#ifdef FUNCDEF
FUNCDEF("rusage", kf_rusage, pt_rusage, 0)
#else
char pt_rusage[] = { C_STATIC, 0, 0, 0, 7, T_INT | (1 << REFSHIFT), 0 };

#include <sys/resource.h>

/*
 * NAME:    kfun->rusage()
 * DESCRIPTION: report on resource utilization
 */
int kf_rusage(Frame* f, int nargs, KFun *kf) {
    UNREFERENCED_PARAMETER(nargs);
    UNREFERENCED_PARAMETER(kf);

    struct rusage stat;
    if (getrusage(RUSAGE_SELF, &stat) == -1) {
        return 1;
    }

    f->addTicks(14);

    Array* a = Array::create(f->data, static_cast<long>(14));
    Value* v = a->elts;

    PUT_INTVAL(&v[0], stat.ru_utime.tv_sec * 1000 + stat.ru_utime.tv_usec / 1000);
    PUT_INTVAL(&v[1], stat.ru_stime.tv_sec * 1000 + stat.ru_stime.tv_usec / 1000);
    PUT_INTVAL(&v[2], stat.ru_maxrss);
    PUT_INTVAL(&v[3], stat.ru_idrss);
    PUT_INTVAL(&v[4], stat.ru_minflt);
    PUT_INTVAL(&v[5], stat.ru_majflt);
    PUT_INTVAL(&v[6], stat.ru_nswap);
    PUT_INTVAL(&v[7], stat.ru_inblock);
    PUT_INTVAL(&v[8], stat.ru_oublock);
    PUT_INTVAL(&v[9], stat.ru_msgsnd);
    PUT_INTVAL(&v[10], stat.ru_msgrcv);
    PUT_INTVAL(&v[11], stat.ru_nsignals);
    PUT_INTVAL(&v[12], stat.ru_nvcsw);
    PUT_INTVAL(&v[13], stat.ru_nivcsw);

    --f->sp;
    PUT_ARRVAL(f->sp, a);

    return 0;
}
#endif
