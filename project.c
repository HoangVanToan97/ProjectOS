#include <pthread.h> 
#include <stdio.h>
#include <unistd.h>
pthread_cond_t cv;
pthread_mutex_t lock;
void process1(){
   fork();
   wait(NULL);
   system("ffmpeg -i video video.webm");
   pthread_cond_signal(&cv);
   system("vlc /home/hoangvantoan/Documents/Kernel/Bai2/mnq.webm");
   exit(0);
}

void process2(){
   fork();
   wait(NULL);
   system("ffmpeg -i /home/hoangvantoan/Documents/Kernel/Bai2/mnq /home/hoangvantoan/Documents/Kernel/Bai2/mnq.webm");
   pthread_mutex_lock(&lock);
   pthread_cond_wait(&cv, &lock);
   pthread_mutex_unlock(&lock);
   system("vlc abc.webm");
   exit(0);
}

void main(){
  pthread_t thread1;
  pthread_t thread2;
  printf("Thanh vien trong nhom \n");
  printf("1. Hoang Van Toan - 20153825 \n");
  printf("2. Nguyen Anh Tuan - 20154105 \n");
  printf("3. Le Thanh Trung - 20153965 \n");
  printf("4. Pham Duc Thuc - 20153747 \n");
  printf("5. Tran Quoc Tuan - 20154064 \n");
  pthread_create(&thread1, NULL, process1, NULL); 
  pthread_create(&thread2, NULL, process2, NULL); 
  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);
}

