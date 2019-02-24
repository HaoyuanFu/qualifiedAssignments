package sort;



public class Merge {
	/**
	 * merge sort using Comparable
	 * @param x - the input array containing jobs that need to be sorted.
	 * @param n - the size of the input array
	 */
	public static void sortMerge ( Comparable[] x, int n ) {
		//Comparable[]tmp=new Comparable[x.length];
		sort(x,0,n-1);
	}
	/**
	 * 
	 * @param array Ҫ���������
	 * @param low �������ڵ�
	 * @param high ������ҽڵ�
	 * @param tmp ��ʱ����
	 * @return
	 */
	private static Comparable[] sort(Comparable[]array,int low,int high){
		int mid=(low+high)/2;
		if (low<high){
			sort(array,low,mid);//�ݹ����
			sort(array,mid+1,high);//�ݹ��Ҳ�
			merge(array,low,mid,high);//�����Ҳ�ϲ�
		}
		return array;
	}
	/**
	 * 
	 * 
	 * @param array Ҫ�ϲ�������
	 * @param first ��ʼ���
	 * @param mid �м�ڵ���
	 * @param last ��ֹ�ڵ���
	 * @param tmp ��ʱ����
	 * ���кϲ�����������������ϲ�Ϊһ����������
	 */
	private static void merge(Comparable[]array,int first,int mid,int last){
		Comparable[]tmp=new Comparable[last-first+1];
		int i=first;
		int j=mid+1;
		int m=mid;
		int n=last;
		int k=0;
		while(i<=m&&j<=n){
			if (array[i].compareTo(array[j])!=1){
				tmp[k++]=array[i++];
			}else{
				tmp[k++]=array[j++];
			}
		}
		while(i<=m){
			tmp[k++]=array[i++];
		}
		while(j<=n){
			tmp[k++]=array[j++];
		}
		for(i=0;i<last-mid+1;i++)
			array[first+i]=tmp[i];
		
	}
}
