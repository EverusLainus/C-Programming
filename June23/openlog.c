#include <stdio.h>
#include <syslog.h>

/*
The openlog() function optionally opens a connection to the logging facility, 
and sets process attributes that affect subsequent calls to the syslog() function
*/
int main(){
    openlog("hey", LOG_PID, LOG_LOCAL0);
    return 0;
}