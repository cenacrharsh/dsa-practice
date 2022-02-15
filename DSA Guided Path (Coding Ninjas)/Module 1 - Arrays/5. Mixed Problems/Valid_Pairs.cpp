//# Tutorial: https://www.youtube.com/watch?v=BvKv-118twg

/*
! if we want sum of 2 elements to be divisible by K, then one should be of type Kn + x and the other Km + (K-x), so that they add up to become K(n+m) + K which will be divisible by K.

! if our case where div by k and remainder m is required our reamainders should be x and m - x, then rest is as above

> for elements like 0 remainder wale, and K/2 remainder types -> they should have even frequency

* so we'll store all the freq in our hashmap and check
*/
