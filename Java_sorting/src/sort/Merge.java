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
	 * @param array 要排序的数组
	 * @param low 数组的左节点
	 * @param high 数组的右节点
	 * @param tmp 临时数组
	 * @return
	 */
	private static Comparable[] sort(Comparable[]array,int low,int high){
		int mid=(low+high)/2;
		if (low<high){
			sort(array,low,mid);//递归左侧
			sort(array,mid+1,high);//递归右侧
			merge(array,low,mid,high);//将左右侧合并
		}
		return array;
	}
	/**
	 * 
	 * 
	 * @param array 要合并的数组
	 * @param first 开始编号
	 * @param mid 中间节点编号
	 * @param last 终止节点编号
	 * @param tmp 临时数组
	 * 进行合并，将两个有序数组合并为一个有序数组
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
