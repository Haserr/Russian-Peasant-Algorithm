/*********************************************
 * Id: hash1886
 *
 * Algorithm that takes 2 numbers as inputs and
 * multiplies them together using additon

 * compile by using 'gcc "file_name" '
 * run by using ./a.out followed by 2 numbers as arguements
 * Ex: './a.out 5 3' 
 *********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fillFirst(int num,int Arr[]);
void fillSecond(int len,int num,int sec[]);
void print(int len,int ans,int arr1[],int arr2[],int adding[],int odd[]);
int findOdd(int len,int arr[],int odd[]);
int RussianPeasant(int len,int odd[],int sec[],int adding[]);
int main(int argc,char *argv[]){

   int firstArg,secArg;
   int firstLen, oddLen;
   int first[10], sec[10], odd[10], adding[10];
   int answer;
   //int i = 0;


   firstArg = atoi(argv[1]); // Finding the 2 numbers to be multiplied
   secArg = atoi(argv[2]);
   //printf("%6d %6d\n", firstArg, secArg);

   
   firstLen = fillFirst(firstArg, first); // Creating arrays based off of 
   fillSecond(firstLen, secArg, sec);     // the 2 numbers 
   //print(firstLen, first, sec);

   oddLen = findOdd(firstLen,first, odd);          // Finds the odd indexies
   answer = RussianPeasant(oddLen, odd, sec, adding);
   print(firstLen, answer, first, sec, adding, odd);
   return 0;
}

// Fills First Array
int fillFirst(int num,int first[]){
   int i = 0;
   first[i] = num;
   while(first[i] >= 1){
      i++;
      first[i] = first[i-1] / 2;
      //printf("%d\n", first[i-1]);
   }
   return i;
}

// Fills First Array
void fillSecond(int len,int num,int sec[]){
   int i = 0;
   sec[i] = num;
   while(len > i){
      i++;
      sec[i] = sec[i-1] * 2;
      //printf("%d\n", sec[i-1]);
   }
}

// Finds odd values in first array
int findOdd(int len, int arr[], int odd[]){
   int i;
   int j = 0;

   for(i = 0; i < len; i++){
      if(arr[i] % 2 == 1){
         //printf("%d ", i);
         odd[j] = i;
         //printf("%d ", odd[j]);
         j++;
      }  
   }
   return j;
}

// Russian Peasant Multiplication
int RussianPeasant(int len, int odd[], int sec[], int adding[]){
   int i, temp;
   int ans = 0;
   
   for(i = 0; i < len; i++){
      temp = odd[i];
      adding[i] = sec[temp];
      ans += adding[i];
      //printf("%d \n", adding[i]);
   }
   //printf("%d \n", ans);
   return ans;

}

// Prints array
void print(int len,int ans,int arr1[], int arr2[], int adding[], int odd[]){
   int i;
   int j = 0;

   for(i = 0; i < len; i++){
      if(odd[j] == i){
         //printf("%d\n", odd[i]);
         printf("%6d %6d %6d\n", arr1[i], arr2[i], adding[j]);
         j++;
      }
      else{
         //printf("%d\n", odd[i]);
         printf("%6d %6d\n", arr1[i], arr2[i]);
      }
   }
   printf("              ------\n");
   printf("%20d\n", ans);
}
