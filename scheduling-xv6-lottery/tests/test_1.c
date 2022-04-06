#include "types.h"
#include "user.h"
#include "pstat.h"

int main (int argc, char **argv)
{
    int settickets_ret, getpinfo_ret;
    struct pstat pstat;
    int pid = getpid();
    int i;
    int tickets_set = 0;

    settickets_ret = settickets(10);
    getpinfo_ret = getpinfo(&pstat);

    for(i=0;i < NPROC;i++)
    {
        if (pstat.inuse[i] && pstat.pid[i] == pid)
        {
            tickets_set = pstat.tickets[i];
        }
    }

    printf(1, "XV6_TEST_OUTPUT %d %d %d\n", settickets_ret, getpinfo_ret, tickets_set);
    exit();
}
