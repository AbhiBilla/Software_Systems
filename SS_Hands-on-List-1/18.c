#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int read_lock(int rlock);
int write_lock(int wlock);

struct student {
    int roll_no;
    int marks;
};

int read_lock(int rlock) {
    int fd=open("file.txt", O_RDONLY);
    if(fd==-1){
      perror("Cant open the file");
      return 1;
    }
    struct student std;
    lseek(fd, (rlock - 1) * sizeof(struct student), SEEK_CUR);
    read(fd, &std, sizeof(struct student));
    printf("Roll No: %d \nMarks : %d \n", std.roll_no, std.marks);
    close(fd);
    fd=open("file.txt", O_RDWR);
    if(fd < 0){
       perror("file cant be opened");
       return 1;
    }
    struct flock lock;
    lock.l_type=F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start =  ( rlock - 1 ) * sizeof(struct student);
    lock.l_len = sizeof(struct student);
    printf("Waiting to acquire lock on record %d \n", std.roll_no);
    fcntl(fd, F_SETLKW, &lock);
    printf("Acquired lock on record %d \n", std.roll_no);
    printf("Press return to exit...\n");
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Exited critical section...\n");
}


int write_lock(int wlock) {
    int fd=open("file.txt", O_RDONLY);
    if(fd < 0) {
       perror("Cant open file");
       return 1;
    }
    struct student std;
    lseek(fd, ( wlock  - 1) * sizeof(struct student), SEEK_CUR);
    read(fd, &std, sizeof(struct student));
    printf("Roll No: %d \n", std.roll_no);
    printf("Marks : %d\n",std.marks);
    close(fd);
    fd=open("file.txt", O_RDWR);
    if(fd < 0){
      perror("Cant open the File");
      return 1;
    }
    struct flock lock;
    lseek(fd, ( wlock  - 1) * sizeof(struct student), SEEK_CUR);
    lock.l_type=F_RDLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=(wlock - 1) * sizeof(struct student);
    lock.l_len = sizeof(struct student);
    printf("Waiting to acquire lock on record %d \n", std.roll_no);
    lock.l_type=F_WRLCK;
    int r=fcntl(fd, F_SETLKW, &lock);
    if(r < 0){
      perror("Cant open the file");
      return 1;
    }
    printf("Acquired lock on record %d \n", std.roll_no);
    printf("You selected to write on this record. \nEnter new marks: ");
    int marks;
    scanf("%d", &marks);
    std.marks=marks;
    lseek(fd, -1 * sizeof(struct student), SEEK_CUR);
    write(fd, &std, sizeof(struct student));
    printf("Press return to exit...\n");
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Exited critical section...\n");
}

void main() {
    int fd = open("file.txt", O_RDWR | O_CREAT);
    if (fd < 0) {
		perror("file");
		exit(1);
	}
    struct student x = {1, 10};
    write(fd, &x, sizeof(struct student));
    struct student y = {2, 20};
    write(fd, &y, sizeof(struct student));
    struct student z = {3, 30};
    write(fd, &z, sizeof(struct student));
    close(fd);

    fd=open("file.txt", O_RDONLY);
    if (fd < 0) {
		perror("file");
		exit(1);
	}
    struct student std;
    read(fd, &std, sizeof(struct student));
    printf("Roll No. : %d \n", std.roll_no);
    printf("Marks : %d \n \n", std.marks);

    read(fd, &std, sizeof(struct student));
    printf("Roll No. : %d \n", std.roll_no);
    printf("Marks : %d \n \n", std.marks);

    read(fd, &std, sizeof(struct student));
    printf("Roll No. : %d \n", std.roll_no);
    printf("Marks : %d \n \n", std.marks);

    int lock;
    int choice;
    lseek(fd, 0, SEEK_CUR);
    printf("Select record you want to lock: ");
    scanf("%d", &lock);
    close(fd);
    if(lock < 1 || lock > 3) exit(1);
    printf("Select type of lock: \nRead (1)\nWrite (2) \nChoice: ");
    scanf("%d", &choice);
    if(choice == 1) {
        read_lock(lock);
        exit(1);
    }
    else if(choice == 2) {
        write_lock(lock);
        exit(1);
    }
    else {
        printf("Wrong choice!");
    }
    close(fd);

}


