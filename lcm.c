#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"
int lcm_2(int a,int b){
    int res,temp;
    if(a > b){
        res = a;
        temp = a;
    }
    else{
        res = b;
        temp = b;
    }
    //printf("%d %d is %d %d.", a, b, temp,res);
    while (1) {
        if (res % a == 0 && res % b == 0) {
            return res;
        }
        res += temp;
    }
}
int main(int argc, char **argv)
{
    char str[10] = "";
    char endl = '\n';
    int fd,count;
    fd = open("lcm_result.txt",O_CREATE|O_RDWR);
    if (fd == -1) {
        printf(1,"cant open or create file\n");
    }
    //printf("saleh\n");    
    int javab = 1;
    int temp = 1;
    for (int i = 1; i < argc; ++i)
    {
        temp = atoi(argv[i]);
        //printf("%d\n",temp);
        javab = lcm_2(temp,javab);
        //printf("msa2\n");
    }
    printf(1,"%d\n",javab);
    int j = 0;
    while(javab > 0){
        str[j] = (javab % 10) + '0';
        javab = javab / 10;
        j++;
    }
    //printf(1,"%s\n",str);
    while(j >= 0){
        j --;
        count = write(fd, &str[j], 1);
    }
    count = write(fd, &endl, 1);
    //char s = '\n';
    //count = write(fd, &s,  1);
    //printf("salam\n");
    if (count == -1) {
            printf(1,"cant write in to file\n");
    }
    //consputc('c');
    close(fd);
    exit();
}