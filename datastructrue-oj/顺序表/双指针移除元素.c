//27. �Ƴ�Ԫ��
//����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�


int removeElement(int* nums, int numsSize, int val) {
    int src = 0;
    int dst = 0;
    while (src < numsSize)
    {
        if (nums[src] != val)
        {
            nums[dst] = nums[src];
            src++;
            dst++;

        }
        else
        {
            src++;
        }
    }
    return dst;
}