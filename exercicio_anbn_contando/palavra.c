#include <string.h>

int checa_string(char* string){
  int marker_a, marker_b;
  marker_a = marker_b = 0;
  for(int i = 0; i<strlen(string);i++){
    if(string[0] == 'a'){
      switch (string[i]) {
        case 'a':
        if(marker_b == 1 )
          return 0;
        break;

        case 'b':
        marker_b = 1;
        break;

        default:
          return 0;
      }
    }else
      return 0;
  }
  return 1;
}
