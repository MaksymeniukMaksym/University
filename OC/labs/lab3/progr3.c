    #include <stdio.h>
    int main(int argc, char *argv[])
    {
    FILE *pipe_fp, *infile;
    char readbuf[80];
    if( argc != 3) {
    fprintf(stderr, "USAGE:  popen3 [command] [filename]\n"); 
    return 1;
    }
     /* Відкриття файла для читання */
     if (( infile = fopen(argv[2], "rt")) == NULL)
     {
     perror("fopen");
     return 1;        
     }
     /* Створення програмного каналу за допомогою системного виклику popen() */
     if (( pipe_fp = popen(argv[1], "w")) == NULL)
     {
     perror("popen");
     return 1;
     }
     /* Реалізація циклу */
     do { 
     fgets(readbuf, 80, infile);
     if(feof(infile)) break;
     fputs(readbuf, pipe_fp);
     } while(!feof(infile));
     fclose(infile); 
     pclose(pipe_fp);
     return(0);
     }
     