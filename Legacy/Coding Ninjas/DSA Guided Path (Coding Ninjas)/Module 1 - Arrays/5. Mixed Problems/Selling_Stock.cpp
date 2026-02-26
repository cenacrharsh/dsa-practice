//# Tutorial: https://www.youtube.com/watch?v=HWJ9kIPpzXs&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=

//! Infinite Transaction Allowed (no overlapping transactions allowed)

long getMaximumProfit(long *values, int n)
{
 // Write your code here
 long buyingDate = 0;
 long sellingDate = 0;
 long totalProfit = 0;
 for (int i = 1; i < n; i++)
 {
  if (values[i] >= values[i - 1])
  {
   sellingDate++;
  }
  else
  {
   totalProfit += values[sellingDate] - values[buyingDate];
   buyingDate = i;
   sellingDate = i;
  }
 }
 // last transaction won't be done if no dip in price. so handle it separately
 totalProfit += values[sellingDate] - values[buyingDate];
 return totalProfit;
}