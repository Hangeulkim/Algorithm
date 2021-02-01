#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **arr, int idx1, int idx2) {
   char *s;
   s = (char *)malloc(sizeof(char) * 51);
   strcpy(s, arr[idx1]);
   strcpy(arr[idx1], arr[idx2]);
   strcpy(arr[idx2], s);
   free(s);
}

int part(char **arr, int left, int right) {
   char *pivot = arr[left];
   int low = left + 1;
   int high = right;

   while (low <= high) {
      while (strlen(pivot) >= strlen(arr[low]) && low <= right)
            low++;

      while (strlen(pivot) <= strlen(arr[high]) && high >= left + 1)
            high--;

      if (low <= high)
         swap(arr, low, high);
   }

   swap(arr, left, high);
   return high;

}

void quicksort(char **arr, int left, int right) {
   if (left <= right) {
      int pivot = part(arr, left, right);
      quicksort(arr, left, pivot - 1);
      quicksort(arr, pivot + 1, right);
   }
}

int main(void) {
   int N;
   char **words;

   scanf("%d", &N);
   words = (char **)malloc(sizeof(char*)*N);
   for (int i = 0; i < N; i++) {
      words[i] = (char *)malloc(sizeof(char) * 51);
      scanf("%s", words[i]);
   }

   quicksort(words, 0, N - 1);

   for (int i = 0; i < N; i++) {
      printf("%s\n", words[i]);
      free(words[i]);
   }


   return 0;
}
