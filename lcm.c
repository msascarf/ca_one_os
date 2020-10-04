
#include "types.h"
#include "stat.h"
#include "user.h"
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
    int fd,count;
    fd = open("lcm_result.txt",0);
    if (fd == -1) {
        //consputc('c');
    }
    for (int i = 1; i < argc; ++i)
    {
        count = write(fd, argv[i], sizeof(argv[i]));
        //char s = '\n';
        //count = write(fd, &s,  1);
        //printf("salam\n");
        if (count == -1) {
            //consputc('c');
        }
        //printf("%s\n",argv[i]);
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
    //consputc('c');
    close(fd);
    exit();
}
