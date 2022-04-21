#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
void sfile(char const filename[]);
int main()
{
int val,pid,ppid,fd;
char buffe[80];
ssize_t read1;
char* buffer = 0;
size_t buf_size = 0;
static char message[]="Hello, SPCE – Visnagar";
fd=open("myfile.txt",O_RDWR);
if (fd != -1)
{
printf("myfile.txt opened with read/write access\n");
write(fd,message,sizeof(message));
lseek(fd,0,0);
read(fd,buffe,sizeof(message));
printf("%s — was written to myfile.txt \n",buffe);
close(fd);
}
val=fork();
printf("%d\n",val);
if(val==0)
{
printf("it is a chaild process....\n");
ppid=getppid();
printf("Parent PID is= %d\n",ppid);
exit(0);
}
else
{
printf("it is a parrent process...\n");
printf("waiting till the child has finished...\n");
wait(NULL);
printf("child has finished...\n");
}
printf("Enter the name of a file to check: \n");
read1 = getline(&buffer, &buf_size, stdin);
if (read1 <=0 ){
printf("getline failed\n");
exit(1);
}
if (buffer[read1-1] == '\n'){
buffer[read1-1] = 0;
}
int s=open(buffer,O_RDONLY);
if(s==-1){
printf("File doesn't exist\n");
exit(1);
}
else{
sfile(buffer);
}
free(buffer);
pid=getpid();
printf("PID is= %d\n",pid);
ppid=getppid();
printf("Parent PID is= %d\n",ppid);
execl("/bin/ls", "ls", (char *)0);
printf("this text won't be printed unless an error occurs in
exec().");
return 0;
}
void sfile(char const filename[]){
struct stat sfile;
if(stat(filename,&sfile)==-1){
printf("Error Occurred\n");
}
//Accessing data members of stat struct
printf("\nFile st_uid %d \n",sfile.st_uid);
printf("\nFile st_blksize %ld \n",sfile.st_blksize);
printf("\nFile st_gid %d \n",sfile.st_gid);
printf("\nFile st_blocks %ld \n",sfile.st_blocks);
printf("\nFile st_size %ld \n",sfile.st_size);
printf("\nFile st_nlink %u \n",(unsigned
int)sfile.st_nlink);
printf("\nFile Permissions User\n");
printf((sfile.st_mode & S_IRUSR)? "r":"-");
printf((sfile.st_mode & S_IWUSR)? "w":"-");
printf((sfile.st_mode & S_IXUSR)? "x":"-");
printf("\n");
printf("\nFile Permissions Group\n");
printf((sfile.st_mode & S_IRGRP)? "r":"-");
printf((sfile.st_mode & S_IWGRP)? "w":"-");
printf((sfile.st_mode & S_IXGRP)? "x":"-");
printf("\n");
printf("\nFile Permissions Other\n");
printf((sfile.st_mode & S_IROTH)? "r":"-");
printf((sfile.st_mode & S_IWOTH)? "w":"-");
printf((sfile.st_mode & S_IXOTH)? "x":"-");
printf("\n");
}