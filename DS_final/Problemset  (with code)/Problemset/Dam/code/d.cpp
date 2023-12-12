#include <iostream>

using namespace std;

int main()
{
    int left,right,value,cap,data,num,max_c=0;
    int *height;
    cin >> data;
    for(int i=0;i<data;i++)
    {
        cin >>num;
        height = new int[num];
        for(int j=0;j<num;j++)
            cin >> height[j];

        left = 0;
        right = num-1;
        max_c = 0;
        while(right>left)
        {
            value = height[left];

            if(height[left]>height[right])
                value = height[right];

            cap = value*(right-left);

            if(max_c < cap)
                max_c = cap;
            if(height[left]>height[right])
                right--;
            else
                left++;
        }
        delete []height;
        cout << max_c << endl;

    }
    return 0;
}