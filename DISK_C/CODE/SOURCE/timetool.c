#include"common.h"
#include"timetool.h"
#include"common.h"
#include"timetool.h"

void get_time(char*time1)

{

        time_t timep;

        struct tm *p;

        time (&timep);

        p=gmtime(&timep);

        //将它们合成一个字符串

//        sprintf(time1,"%d/%d/%d/ %d:%d:%d",1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour-4,p->tm_min,p->tm_sec);
		sprintf(time1,"%d/%d/%d",1900+p->tm_year,1+p->tm_mon,p->tm_mday);

}
