#include <stdlib.h>
#include <stdio.h>

void quickSort(int arr[], int low, int high);
void swap(int* a, int* b);
int partition (int arr[], int low, int high);

int main(int argc, char* argv[]) {

  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    perror("fopen failed");
    return EXIT_FAILURE;
  }
  
  char buf[255];
  //char* firstLine = fgets(buf, 255, fp);
  //printf("First Line is %s\n", firstLine);
  char* lineGet = fgets(buf, 255, fp);
  int numOfNum = atoi(lineGet);
  lineGet = fgets(buf, 255, fp);
  int numOfMax = atoi(lineGet);
  
  int *numArray = malloc(numOfNum*sizeof(int));
  //int maxCount = 0;
  
  for (int i=0; i<numOfNum; i++){
    fscanf(fp, "%s", buf);
    numArray[i] = atoi(buf);
  }

  quickSort(numArray, 0, numOfNum-1);

  for (int i=0; i<numOfMax; i++){
    printf("%d ", numArray[i]);
  }

  free(numArray);
  fclose(fp);

}

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] > pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high){
  if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
