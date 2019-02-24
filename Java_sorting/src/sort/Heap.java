package sort;

public class Heap {
	/**
	 * heap sort using Comparable
	 * @param x - the input array containing jobs that need to be sorted.
	 * @param n - the size of the input array
	 */
	public static void sortHeap ( Comparable[] x, int n ) {
		buildMaxHeap(x);
		for(int i=x.length-1;i>=1;i--){
			Comparable tmp=x[0];
			x[0]=x[i];
			x[i]=tmp;
			maxHeap(x,i,0);
		}
	}
	/**
	 * 
	 * @param array
	 * 构建最大堆
	 */
	private static void buildMaxHeap(Comparable[]array){
		int half=array.length/2;
		for(int i=half;i>=0;i--){
			maxHeap(array,array.length,i);
		}
	}
	/**
	 * 
	 * @param array
	 * @param heapSize
	 * @param index
	 * 进行交换
	 */
	private static void maxHeap(Comparable[]array,int heapSize,int index){
		int left=index*2+1;
		int right=index*2+2;
		int largest=index;
		if (left<heapSize&&array[left].compareTo(array[index])==1){
			largest=left;
		}
		if (right<heapSize&&array[right].compareTo(array[largest])==1){
			largest=right;
		}
		if (index!=largest){
			Comparable tmp=array[index];
			array[index]=array[largest];
			array[largest]=tmp;
		
			maxHeap(array,heapSize,largest);
		}
		
	}
}
