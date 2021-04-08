#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "pstat.h"

int main(int argc, char *argv[]) {
    int j = getpid();
    sleep(10);
    setslice(j,5);
    //int g = getslice(j);
    //printf(1,"Timeslice for %d should be %d\n", j, y);
    //printf(1,"The timeslice for %d = %d\n", j, g);
    int i;
    int x = 0;
    if (argc != 2) {
	exit();
    }
    
    for (i = 1; i < atoi(argv[1]); i++) {
        x += i;
    }
    struct pstat ps;
    getpinfo(&ps);
    //for (int h = 0; h< 20; h++) { 
      //printf(1, "switches for %d = %d\n", ps.pid[h], ps.schedticks[h]);
      //printf(1, "Process %d sleeps for %d seconds\n", ps.pid[h], ps.sleepticks[h]);
    //}
    
    exit();

}
