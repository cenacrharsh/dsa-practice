void removeDuplicates(int *arr, int *size)
{
 int ptr = 1;
 for (int i = 1; i < *size; i++)
 {
  if (arr[i] != arr[i - 1])
  {
   arr[ptr] = arr[i];
   ptr++;
  }
 }
 *size = ptr;
}
