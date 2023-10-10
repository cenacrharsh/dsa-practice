	//* valid symmetry - how many elements from nums1 and nums2 will be on left side and right side
	//* there will be only one valid symmetry

	int n1 = nums1.size();
	int n2 = nums2.size();
	if(n1 > n2) {
		return median(nums2, nums1); //* we want the first array to always be smaller
	}
	
	int low = 0, high = n1;
	int left = (n1 + n2 + 1) / 2;
	int n = n1 + n2;
	while(low <= high) {
		int mid1 = (low + high) / 2;
		int mid2 = left - mid1;
		
		int l1 = INT_MIN, l2 = INT_MIN;
		int r1 = INT_MAX, r2 = INT_MAX;
		
		if(mid1 < n1) {
			r1 = nums1[mid1];
		}
		if(mid2 < n2) {
			r2 = nums2[mid2];
		}

		if(mid1 - 1 >= 0) {
			l1 = nums1[mid1 - 1];
		}
		if(mid2 - 1 >= 0) {
			l2 = nums2[mid2 - 1];
		}

		if(l1 <= r2 && l2 <= r1) {
			if(n % 2 == 1) {
				return max(l1, l2);
			}
			return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
		}
		else if(l1 > r2) {
			high = mid1 - 1; //* if we go right, that is more elements from nums1 hence elements larget than l1 hence we need to eliminate the right half
		}
		else {
			low = mid1 + 1; //* if we go left we'll get smaller elements from nums2 so we need to move right
		}
	}
	return 0;