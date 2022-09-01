/*
  usbreset.c
  USB RESET for linux

  2022 GaRocK (aka Gaka)

  This program is used to reset a usb from a linux machine.
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>

int main(int argc, char **argv){
  const char *drivername;
  int driverstat;              // if < 0: file error
  int resetstat;               // if < 0: ioctl error

  //colors if tty
  if (isatty(1)){
    #define COLOR_RED         "\x1b[31m"
    #define COLOR_GREEN       "\x1b[32m"
    #define BOLD_WHITE        "\x1b[1;37m"
    #define COLOR_WHITE       "\x1b[0m"
  }
  //usage string
  const char usbreset_usage_string[] =
	 ("usbreset <device-filename>\n"
	  "example:\n"
	  "           usbreset /dev/bus/usb/002/002 \n"
	  "usbreset must run with " COLOR_RED "root " BOLD_WHITE "privileges.");
  
  //parser
  if (argc !=2){
    fprintf(stderr, BOLD_WHITE "Usage: %s\n" COLOR_WHITE,usbreset_usage_string);
    return 1;
  }
  
  drivername = argv[1];

  driverstat = open(drivername, O_WRONLY);

  if (driverstat < 0){
    perror(COLOR_RED "[File Error] Error opening output file\n             Are you running as root?" COLOR_WHITE);
    return 1;
  }

  printf (BOLD_WHITE "[Reset] Trying to reset USB device %s\n", drivername);

  resetstat = ioctl(driverstat, USBDEVFS_RESET,0);

  if (resetstat <0){
    perror(COLOR_RED "[System Error] Error in ioctl\n" COLOR_WHITE);
    return 1;
  }

  printf(COLOR_GREEN "[Success] Device %s has been reseted successfully!\n" COLOR_WHITE, drivername);
  
  return 0;
}
