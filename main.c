#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
char* param[15] = {"device_name","rom_revision","serial_number","bd_addr_part0","bd_addr_part1","bd_pass_part0","serial_baudrate","audio_bitrate","sleep_period","serial_parity","serial_data_bit","serail_stop_bit","bd_pass_part1","rom_checksum_part0","rom_checksum_part1"}; 

int valid(const char* param_name, const char* value){
   int i, number, length = strlen(value);
   char c;
   unsigned char uc;

   if(strcmp(param_name,"device_name") == 0 || strcmp(param_name,"rom_revision") == 0){
       if(length > 15){
       return 0;
    }
   
   for(i=0;i<length;i++)
      if(!((value[i]>='a' && value[i]<='z') || (value[i]>='A' && value[i]<='Z') || (value[i]>='0' && value[i]<='9') || value[i] == '_' || value[i] == '-')){
      return 0;
     }
    return 1;
  }
   
    if(strcmp(param_name,"serial_number") == 0){
       if(length > 15){
       return 0;
    }

   for(i=0;i<length;i++)
    if(!( (value[i]>='A' && value[i]<='Z') || (value[i]>='0' && value[i]<='9')))     {
      return 0;
     }
    return 1;
  }
  
    if(strcmp(param_name,"bd_addr_part0") == 0 || strcmp(param_name,"bd_addr_part1") == 0) {
             if(length > 15){
             return 0;
           } 
 
   for(i=0;i<length;i++)
   if(!( (value[i]>='A' && value[i]<='Z') || (value[i]>='0' && value[i]<='9') || value[i]==':'))
     {
      return 0;
     }
    return 1;
  }

    if(strcmp(param_name,"bd_pass_part0") ==0 || strcmp(param_name,"bd_pass_part1") == 0 || strcmp(param_name,"rom_checksum_part0") == 0 || strcmp(param_name,"rom_checksum_part1") == 0){
       if(length > 15){
       return 0;
    }

   for(i=0;i<length;i++)
    if(!( (value[i]>='a' && value[i]<='z') || (value[i]>='0' && value[i]<='9')))     {
      return 0;
     }
    return 1;
  }

    if(strcmp(param_name,"serial_baudrate")==0){
     number = atoi(value);
    if(!( number == 1200 || number == 2400 || number == 4800 || number == 9600 || number == 19200 || number == 115200)) {
      return 0;
     }
    return 1;
  }
   
    if(strcmp(param_name,"audio_bitrate")==0){
     number = atoi(value);
    if(!( number == 32 || number == 96 || number == 128 || number == 160 || number == 192 || number == 256 || number == 320)) {
      return 0;
     }
    return 1;
  }
 
    if(strcmp(param_name,"sleep_period")==0){
     number = atoi(value);
    if(!( number == 100 || number == 500 || number == 1000 || number == 5000 || number == 10000 )) {
      return 0;
     }
    return 1;
  }

     if(strcmp(param_name,"serial_parity")==0){
        if(length > 1){
         return 0;
       }
       c = value[0];

     if(!( c == 'N' || c == 'E' || c == 'O')) {
      return 0;
     }
    return 1;
  }
   
     if(strcmp(param_name,"serial_data_bit")==0){
        if(length > 1){
         return 0;
       }
       uc = (unsigned char) atoi(value);

     if(!( uc == 5 || uc == 6 || uc == 7|| uc == 8)) {
      return 0;
     }
    return 1;
  }
   
     if(strcmp(param_name,"serail_stop_bit")==0){
        if(length > 1){
         return 0;
       }
       uc = (unsigned char) atoi(value);

     if(!( uc == 0 || uc == 1 )) {
      return 0;
     }
    return 1;
  }

return 0;
}

int segment(const char* param_name){
   if(strcmp(param_name,"device_name") == 0) return 0;
   if(strcmp(param_name,"rom_revision") == 0) return 0;
   if(strcmp(param_name,"serial_number") == 0) return 0;

   if(strcmp(param_name,"bd_addr_part0") == 0) return 1;
   if(strcmp(param_name,"bd_addr_part1") == 0) return 1;
   if(strcmp(param_name,"bd_pass_part0") == 0) return 1;

   if(strcmp(param_name,"serial_baudrate") == 0) return 2;
   if(strcmp(param_name,"audio_bitrate") == 0) return 2;
   if(strcmp(param_name,"sleep_period") == 0) return 2;
  
   if(strcmp(param_name,"serial_parity") == 0) return 3;
   if(strcmp(param_name,"serial_data_bit") == 0) return 3;
   if(strcmp(param_name,"serail_stop_bit") == 0) return 3;

   if(strcmp(param_name,"bd_pass_part1") == 0) return 4;
   if(strcmp(param_name,"rom_checksum_part0") == 0) return 4;
   if(strcmp(param_name,"rom_checksum_part1") == 0) return 4;
  
  return 0;
}
 
int position(const char* param_name){
if(strcmp(param_name,"device_name") == 0) return 0;
   if(strcmp(param_name,"rom_revision") == 0) return 1;
   if(strcmp(param_name,"serial_number") == 0) return 2;

   if(strcmp(param_name,"bd_addr_part0") == 0) return 0;
   if(strcmp(param_name,"bd_addr_part1") == 0) return 1;
   if(strcmp(param_name,"bd_pass_part0") == 0) return 2;

   if(strcmp(param_name,"serial_baudrate") == 0) return 0;
   if(strcmp(param_name,"audio_bitrate") == 0) return 1;
   if(strcmp(param_name,"sleep_period") == 0) return 2;
  
   if(strcmp(param_name,"serial_parity") == 0) return 0;
   if(strcmp(param_name,"serial_data_bit") == 0) return 1;
   if(strcmp(param_name,"serail_stop_bit") == 0) return 2;

   if(strcmp(param_name,"bd_pass_part1") == 0) return 0;
   if(strcmp(param_name,"rom_checksum_part0") == 0) return 1;
   if(strcmp(param_name,"rom_checksum_part1") == 0) return 3;
  
  return 0;
}

unsigned char checkBit(int fd, const char* param_name){
 int seg = segment(param_name);
 int pos = position(param_name);
 
 unsigned char buffer, mask = 0x80;
 lseek(fd,64*seg,SEEK_SET);
 lseek(fd,1,SEEK_CUR);

 int offset = pos / 8;
 int bit_number = pos % 8;

 lseek(fd,offset,SEEK_CUR);
 read(fd, &buffer, 1);
 lseek(fd, -1, SEEK_CUR);
 
 return (buffer & (mask >> bit_number));

}

void setBit(int fd, const char* param_name){

 int seg = segment(param_name);
 int pos = position(param_name);
 
 unsigned char buffer, mask = 0x80;
 lseek(fd,64*seg,SEEK_SET);
 lseek(fd,1,SEEK_CUR);

 int offset = pos / 8;
 int bit_number = pos % 8;

 lseek(fd,offset,SEEK_CUR);
 read(fd, &buffer, 1);
 lseek(fd, -1, SEEK_CUR);

 buffer |= (mask >> bit_number);
 write(fd, &buffer, 1);

}
void unsetBit(int fd, const char* param_name){

 int seg = segment(param_name);
 int pos = position(param_name);

 unsigned char buffer, mask = 0x80;
 lseek(fd,64*seg,SEEK_SET);
 lseek(fd,1,SEEK_CUR);

 int offset = pos / 8;
 int bit_number = pos % 8;

 lseek(fd,offset,SEEK_CUR);
 read(fd, &buffer, 1);
 lseek(fd, -1, SEEK_CUR);

 buffer &= ~(mask >> bit_number);
 write(fd, &buffer, 1);
}

unsigned char locate(int fd, const char* param_name){
  unsigned char buffer;
  int seg = segment(param_name);
  int pos = position(param_name);
   
  lseek(fd, 64*seg, SEEK_SET);
  
  //we need the segment type
  read(fd, &buffer, 1);
  
  //we skip the 7 bytes meta information
  lseek(fd,7,SEEK_CUR);

  if(buffer == 0)  //text segment
    lseek(fd,16*pos,SEEK_CUR);
  else if(buffer == 1)  //number segment
    lseek(fd,4*pos,SEEK_CUR);
  else if(buffer == 2) //byte segment
    lseek(fd,pos,SEEK_CUR);
 
  return buffer;
}

void write_value(int fd, const char* param_name, const char* value){
int value_num, i;  
char value_ch, null_ch = '\0';
unsigned char value_uch;

unsigned char type = locate(fd,param_name);

if( type == 0) {

  write(fd, value, strlen(value));
  for(i=0;i < (int) (16 - strlen(value)); i++)
     write(fd, &null_ch, 1);
  
    }  //text segment
  else if(type == 1) {

     value_num = atoi(value);
     write(fd, &value_num, 4);

    } //number segment
  else if(type == 2 && strcmp(param_name,"serial_parity") == 0) {

       value_ch = value[0];
       write(fd,&value_ch,1);

      }//byte segment
      else if(type == 2 && (strcmp(param_name,"serial_data_bit") == 0 || strcmp(param_name,"serail_stop_bit") == 0) ) {

               value_uch = (unsigned char) atoi(value);
               write(fd,&value_uch,1);

            }//byte segment

}

void read_value(int fd, const char* param_name) {
int value_num;  char value_txt[16];
char value_ch;
unsigned char value_uch;

unsigned char type = locate(fd,param_name);

if( type == 0) {

  read(fd, value_txt, 16);
  printf("%s : %s \n", param_name, value_txt);

    }  //text segment
  else if(type == 1) {

    read(fd, &value_num, 4);
    printf("%s : %d \n", param_name, value_num);

    } //number segment
  else if(type == 2 && strcmp(param_name,"serial_parity") == 0) {

           read(fd,&value_ch,1);
           printf("%s : %c \n", param_name, value_ch);

          }//byte segment
       else if(type == 2 && (strcmp(param_name,"serial_data_bit") == 0 || strcmp(param_name,"serail_stop_bit") == 0) ) {
               read(fd,&value_uch,1);
               printf("%s : %u \n", param_name, value_uch);

            }//byte segment

}

void write_segment(int fd, const char* segm, const char* type){
  int segment = atoi(segm);
  char type_seg = type[0];
  unsigned char type_id;
 
  lseek(fd,64*segment,SEEK_SET);

  switch(type_seg){
   case 't': type_id = 0; break;
   case 'n': type_id = 1; break;
   case 'b': type_id = 2; break;
   default:  type_id = 0;
  }
  write(fd,&type_id,1); 
}
   
void main(int argc, char* argv[]){

  int fd_conf, i;  

 if(strcmp(argv[1],"-h") == 0){

   printf("./bk8000l_conf conf.bin -s device_name DeviceN1\n changes the value of the parameter device_name in conf.bin to DeviceN1. The value of the responsible bit is also changed properly.\n");

   printf("./bk8000l_conf conf.bin -S device_name DeviceN1\n the same functionality but without setting the responsible bit.\n");

   printf("./bk8000l_conf conf.bin -g device_name\n prints the value of the parameter device_name only if it is activated.\n");

   printf("./bk8000l_conf conf.bin -G device_name\n prints the value of the parameter device_name.\n");

   printf("./bk8000l_conf conf.bin -l \n prints a list of all activated configuration parameters.\n");

   printf("./bk8000l_conf conf.bin -L \n prints a list of all configuration parameters (activated or not).\n"); 

   printf("./bk8000l_conf conf.bin -l device_name baudrate \n prints the values of all conf. parameters listed in the command line only if they are activated.\n");

   printf("./bk8000l_conf conf.bin -L device_name baudrate \n prints the values of all conf. parameters listed in the command line (activated or not).\n");
   printf("./bk8000l_conf conf.bin -b device_name 1 \n setting or unsetting the activation bit of the given conf. parameter.\n");
   
   printf("./bk8000l_conf new.bin -c 0 t 1 b 2 t 3 n \n creates an empty configuration file with the given segment types: t-text b-byte n-number segment. \n");
   printf("./bk8000l_conf -h \n prints a manual.\n");
   exit(0);
  }

 /* argv[1] must be the name of a configuration file. Nonexisting only with the -c option, in all other cases it must be existing.*/

  if((fd_conf = open(argv[1],O_RDWR)) < 0){
    
    if(strcmp(argv[2],"-c") == 0){

         if((fd_conf = open(argv[1],O_CREAT|O_TRUNC|O_RDWR,0777)) < 0){ perror("Can not create the file.\n"); exit(1);}
         for(i=3;i<argc;i+=2)
          write_segment(fd_conf,argv[i],argv[i+1]);
         
         close(fd_conf); exit(0);
    }
    else {perror("Can not open the file or it does not exist.\n"); exit(1);}
  }

  /* from now on we have an open config. file with file descriptor fd_conf */
  
   if(strcmp(argv[2],"-s") == 0 || strcmp(argv[2],"-S") == 0){

       if(argc != 5 ) { printf("Invalid data\n"); exit(1); }

       if(valid(argv[3],argv[4])){

           write_value(fd_conf,argv[3],argv[4]);

           if(strcmp(argv[2],"-s") == 0)
              setBit(fd_conf,argv[3]);
          
           close(fd_conf);
           exit(0);
        }
       else {printf("Invalid data!\n"); exit(1); }

   }

   if(strcmp(argv[2],"-g") == 0 || strcmp(argv[2],"-G") == 0){
        if(strcmp(argv[2],"-g") == 0 && !checkBit(fd_conf,argv[3])) //ne e aktiviran conf. param
          { close(fd_conf);  
            exit(0);
          }
       
        read_value(fd_conf, argv[3]);
        close(fd_conf);
        exit(0);
   }

   if(strcmp(argv[2],"-l") == 0 && argc == 3) {
      for(i=0; i < 15; i++)
        if(checkBit(fd_conf, param[i])) {
          write(1,param[i],strlen(param[i]));
          write(1,"\n",1);
        }
       
       close(fd_conf);
       exit(0);
   }
  
   if(strcmp(argv[2],"-L") == 0 && argc == 3) {
      for(i=0; i < 15; i++)
        {
          write(1,param[i],strlen(param[i]));
          write(1,"\n",1);
        }
 
       close(fd_conf);    
       exit(0);
   }
  
   if(strcmp(argv[2],"-l") == 0 && argc > 3) {
      for(i=3; i < argc; i++)
        if(checkBit(fd_conf, argv[i])) {
        read_value(fd_conf,argv[i]);
      }

       close(fd_conf);    
       exit(0);
   }

   if(strcmp(argv[2],"-L") == 0 && argc > 3) {
      for(i=3; i < argc; i++)
        {
         read_value(fd_conf,argv[i]);
        }

       close(fd_conf);
       exit(0);
   }
  
   if(strcmp(argv[2],"-b") == 0){
    char bit;
    if(argc != 5 || strlen(argv[4]) != 1) { printf("Invalid data\n"); exit(1); } 
    bit = *argv[4];

    if(bit == '1')
       setBit(fd_conf,argv[3]);
    else if(bit == '0')
         unsetBit(fd_conf,argv[3]);
         else { printf("Invalid data\n"); exit(1); }

    close(fd_conf);
    exit(0);
   }
   
   close(fd_conf);
   printf("Invalid option!\n");
   exit(1);
}

