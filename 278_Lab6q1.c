#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int csum;
void *runner(void *param);

int main(int argc, char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid,&attr,runner,argv[1]);
    //parent thread ค านวณผลบวก msum จาก 1 ถึงเลขจ านวนนั้น
    int upper = atoi(argv[1]);
    int i;
    int msum = 0;
    if(upper > 0){
        for(i=0;i<=upper;i++){
            msum += i;
        }
    }
    pthread_join(tid,NULL);
    //ให้parent แสดงค่า ผลต่างของ csum กับ msum
     printf("csum = %d , msum = %d now difference = %d\n", csum, msum ,csum - msum );
//หากไม่ join คำตอบที่ได้มีกี่แบบ อะไรบ้าง (โดยมากจะพบ 3 แบบ)
    //printf("sum %d\n" , sum);
    return 0;
}

void *runner(void *param){
    //สร้าง child Thread โดย child thread ค านวณ csum จาก 1 ถึง 2 เท่าของเลขดังกล่าว
    int upper = atoi(param);
    upper = upper * 2;
    int i;
    csum = 0;
    if(upper > 0){
        for(i=0;i<=upper;i++){
            csum += i;
        }
        pthread_exit(0);
    }
}