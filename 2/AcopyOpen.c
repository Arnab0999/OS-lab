#include<stdio.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv){
    int source_file, target_file;

    long bytesRead, bytesWrite;

    char buffer[BUFFER_SIZE];

    source_file = open("input.out", O_RDONLY);

    if(source_file == -1){
        perror("cant do shit");
        return 1;
    }

    target_file = open("output.out", O_WRONLY | O_EXCL | O_CREAT);

    if(target_file == -1){
        perror("Bruh");
        return 2;
    }
    
    while ( (bytesRead = read (source_file, &buffer, BUFFER_SIZE)) > 0){
        bytesWrite = write(target_file, &buffer, (long) bytesRead);
        
    }
    
    close(source_file);
    close(target_file);

    return 0;

}
