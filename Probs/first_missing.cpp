#include <bits/stdc++.h>
using namespace std;

void disp(vector<int> vec){
    for(int a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
}

int firstMissingPositive(vector<int> &A) {
    int start=0;
    int n=A.size();
    int minusInd=n-1;
    int i=0;
    int j=n-1;
    while(i<=j){
        if(A[i]<0){
            if(A[j]<0){
                j--;
            }
            else if(A[j]>=0){
                swap(A[i],A[j]);
                i++,j--;
            }
        }
        else{
            i++;
        }
    }
    return 0;
}
int solve(vector<int> &vec){
    int n=vec.size();
    int mini=n+1;
    for (int i = 0; i < n; i++){
        if(vec[i]>0)mini=min(mini,vec[i]);
    }
    if(mini==INT_MAX)return 1;
    if(mini >1)return 1;
    for (int i = 0; i < n; i++)
    {
        if(vec[i]<0 || vec[i]==0)vec[i]=mini;
    }
    // disp(vec);
    for (int i = 0; i < n; i++){
        // cout<<i<<" ";
       if(abs(vec[i])<(n+1) and vec[abs(vec[i])-1]>0)vec[abs(vec[i])-1]*=-1;
    }
    // disp(vec);
    for (int i = 0; i < n; i++){
        if(vec[i]>0)return (i+1);
    }
    // disp(vec);
    return n+1;
}



int main()
{
    vector<int> vec={110, 483, 137, 881, 946, 231, 378, 449, 68, 518, 476, 898, 685, 384, 839, 553, 304, 689, 467, 292, 414, 679, 301, 30, 457, 300, 93, 427, 619, 439, 4, 348, 714, 966, 142, 538, 484, 827, 237, 447, 442, 133, 771, 578, 190, 782, 182, 23, 192, 177, 164, 276, 273, 45, 624, 12, 354, 938, 472, 899, 42, 612, 813, 386, 380, 63, 136, 589, 334, 349, 757, 999, 526, 156, 803, 991, 961, 535, 297, 336, 409, 59, 558, 678, 755, 720, 88, 906, 571, 770, 673, 581, 399, 868, 446, 123, 707, 643, 548, 226, 854, 830, 423, 621, 14, 767, 801, 651, 932, 492, 462, 321, 250, 591, 208, 862, 413, 418, 724, 746, 388, 925, 882, 808, 543, 171, 737, 994, 283, 950, 528, 443, 853, 671, 699, 19, 344, 365, 134, 818, 531, 48, 464, 124, 377, 379, 792, 387, 11, 796, 159, 65, 842, 109, 631, 600, 987, -3, 263, 28, 833, 779, 100, 73, 790, 179, 889, 557, 887, 455, 502, 511, 907, 686, 713, 864, 271, 372, 850, 534, 347, 649, 21, 169, 712, 435, 1, 222, 509, 866, 628, 604, 885, 385, 896, 498, 964, 598, 508, 575, 893, 294, 520, 918, 729, 789, 772, 660, 87, 569, 677, 602, 962, 217, 69, 648, 72, 331, 749, 637, 180, 489, 733, 481, 393, 40, 274, 320, 113, 930, 633, 516, 878, 835, 754, 126, 15, 593, 338, 494, 972, 603, 34, 739, 947, 592, 886, 583, 127, 172, 675, 975, 232, 394, 763, 92, 512, 616, 983, 856, 955, 166, 157, 608, 218, 56, 66, 696, 310, 933, 185, 563, 647, 960, 323, 727, 471, 397, 367, 582, 223, 369, 759, 706, 35, 588, 478, 317, 564, 768, 904, 149, 202, 165, 695, 985, 731, 486, 312, 561, 466, 197, 245, 980, 979, 620, 774, 438, 193, 146, 653, 468, 963, 485, 178, 29, 434, 272, 296, 700, 549, 181, 586, 595, 410, 108, 91, 640, 175, 750, 490, 20, 101, 879, 74, 798, 910, 611, 187, 286, 997, 138, 488, 901, 154, 267, 403, 122, 572, 787, 942, 391, 525, 176, 383, 1000, 458, 24, 780, 691, 738, 151, 170, 351, 441, 776, 453, 590, 545, 139, 859, 461, 970, 491, 785, 969, 670, 570, 219, 99, 353, 723, 470, 716, 249, 115, 680, 501, 128, 851, 9, 120, 256, 820, 114, 416, 329};
    cout<<solve(vec)<<endl;
    // disp(vec);


    return 0;
}