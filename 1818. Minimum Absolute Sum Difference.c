int compare(const void*a, const void*b);
int find_diff(int arr[], int left, int right, int key);

int minAbsoluteSumDiff(int* nums1, int nums1Size, int* nums2, int nums2Size){
    long long res=0;
    int temp[nums1Size]; int arr[nums1Size];
    memcpy(temp, nums1, sizeof(int)*nums1Size);
    qsort(temp, nums1Size, sizeof(int), compare);
    int size=0;
    for(int i=0;i<nums1Size;i){
        int j=i;
        while(j<nums1Size&&temp[i]==temp[j]) j++;
        arr[size++] = temp[i];
        i=j;
    }
    
    
    int diff=0, diff2=0, value = 0;
    for(int i=0;i<nums1Size;i++){
        res += abs(nums1[i]-nums2[i]);
        
        diff2 = abs(nums1[i]-nums2[i]) - find_diff(arr, 0, size-1, nums2[i]);
        if(diff<diff2) diff = diff2;
    }
    
    return (res-diff)%1000000007;
}

int compare(const void*a, const void*b){
    return *(const int*)a - *(const int*)b;
}

int find_diff(int arr[], int left, int right, int key){
    int diff=100001;
    
    while(left<=right){
        int mid = (right+left)/2;
        if(arr[mid]==key) return 0;
        else if(arr[mid]>key){
            right = mid-1;
            if(diff>abs(key-arr[mid])) diff = abs(key-arr[mid]);
        }else{
            left = mid+1;
            if(diff>abs(key-arr[mid])) diff = abs(key-arr[mid]);
        }
    }
    return diff;
}