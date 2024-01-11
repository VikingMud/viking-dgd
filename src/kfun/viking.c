# ifndef FUNCDEF
# define INCLUDE_CTYPE
# include "kfun.h"
# endif


# ifdef FUNCDEF
FUNCDEF("rusage", kf_rusage, pt_rusage, 0)
# else
char pt_rusage[] = { C_STATIC, 0, 0, 0, 7, T_INT | (1 << REFSHIFT), 0 };

#include <sys/resource.h>

/*
 * NAME:	kfun->rusage()
 * DESCRIPTION:	report on resource utilization
 */
int kf_rusage(f)
frame *f;
{
    register value	*v;
    array		*a;
    struct rusage	stat;

    i_add_ticks(f, 14);

    --f->sp;

    if (getrusage(RUSAGE_SELF, &stat) == -1) {
	*f->sp = nil_value;
	return 0;
    }

    a = arr_new(f->data, (long)14);
    v = a->elts;

    PUT_INTVAL(v, stat.ru_utime.tv_sec * 1000 +
		  stat.ru_utime.tv_usec / 1000);
    v++;
    PUT_INTVAL(v, stat.ru_stime.tv_sec * 1000 +
		  stat.ru_stime.tv_usec / 1000);
    v++;
    PUT_INTVAL(v, stat.ru_maxrss);
    v++;
    PUT_INTVAL(v, stat.ru_idrss);
    v++;
    PUT_INTVAL(v, stat.ru_minflt);
    v++;
    PUT_INTVAL(v, stat.ru_majflt);
    v++;
    PUT_INTVAL(v, stat.ru_nswap);
    v++;
    PUT_INTVAL(v, stat.ru_inblock);
    v++;
    PUT_INTVAL(v, stat.ru_oublock);
    v++;
    PUT_INTVAL(v, stat.ru_msgsnd);
    v++;
    PUT_INTVAL(v, stat.ru_msgrcv);
    v++;
    PUT_INTVAL(v, stat.ru_nsignals);
    v++;
    PUT_INTVAL(v, stat.ru_nvcsw);
    v++;
    PUT_INTVAL(v, stat.ru_nivcsw);

    PUT_ARRVAL(f->sp, a);

    return 0;
}
# endif
