package sort;

public class Insertion {
	private static int step=0;
	/**
	 * regular insertion sort
	 * @param x - the input array containing jobs that need to be sorted.
	 */
	public static void sortInsert ( Job[] x ) {
		int n=x.length;
		Job target;
		int i,j;
		for(i=1;i<n;i++){
			j=i;
			target=x[i];
			while(j>0&&compare(target,x[j-1])==-1){
				x[j]=x[j-1];
				j--;
			}
			x[j]=target;
		}
		
		
		
	}
	/**
	 * 
	 * @param job1
	 * @param job2
	 * ���Job�е����ݽ��бȽ�
	 * @return
	 */
	private static int compare(Job job1,Job job2){
		//��ȡjob1��job2��secondsֵ��idֵ
		int seconds1=job1.getSeconds();
		int seconds2=job2.getSeconds();
		String id1=job1.getId();
		String id2=job2.getId();
		if (seconds1<seconds2){
			return -1;
		}else{
			if (seconds1>seconds2)
				return 1;
			else{
				return id1.compareTo(id2);
			
			}
	}
}
	/**
	 * insertion sort using Comparable
	 * @param x - the input array containing jobs that need to be sorted.
	 * @param n - the size of the input array
	 */
	public static void sortComparable ( Comparable[] x, int n ) {
		//int n=x.length;
		Comparable target;
		int i,j;
		for(i=1;i<n;i++){
			j=i;
			target=x[i];
			while(j>0&&target.compareTo(x[j-1])==-1){
				x[j]=x[j-1];
				j--;
			}
			x[j]=target;
		}
		
		
		
		
		
	}
		
		
		
	
	/**
	 * optimized insertion sort
	 * @param x - the input array containing jobs that need to be sorted.
	 * @param n - the size of the input array
	 */
	
	public static void sortBinary (Comparable[] x, int n ) {
	
		TreeNode root=new TreeNode(x[0],null,null);//���ɶ������ĸ��ڵ�,������һ��Ԫ�ط����ȥ
		TreeNode r=root;//�����ڵ㶨��Ϊroot
		TreeNode parent=root;//��¼ÿ���ڵ�ĸ��ڵ�
		step=0;
		for(int i=1;i<n;i++){//һ���ڵ�һ���ڵ�Ĳ���
			int f1=0;
			r=root;
			parent=root;
			while(r!=null){
				parent=r;
				 f1=0;
				if (x[i].compareTo(r.getValue())==-1){
					r=r.getLeft();
					f1=1;//���Ҫ����Ľڵ�ȵ�ǰ�ڵ�С�������ӽڵ�
				}else{
					f1=2;
					r=r.getRight();//��������Һ��ӽڵ�
				}
			}//�������սڵ�ʱѭ��������λҪ�����λ��
			r=new TreeNode(x[i],null,null);//�����½ڵ�
			if (f1==1)
				parent.setLeft(r);
			else
				parent.setRight(r);
		}
	//	System.out.println("ABCD");
		mid_traverse(root, x);//�������
		
	}
	/**
	 * 
	 * @param r��ʾ���Ľڵ�
	 * @param x��ʾComparable����
	 */
	private static void mid_traverse(TreeNode r,Comparable[]x){
		if (r==null)
			return;
		mid_traverse(r.getLeft(),x);//�ݹ�������
		 x[step]=r.getValue();//���и�ֵ
		 step++;
		mid_traverse(r.getRight(),x);//�ݹ�������
	}
	
	/**
	 * 
	 * @author 
	 *����һ���ڲ���������װ���ڵ������,ÿ�����ڵ����һ��valueֵ,�������ڵ�,�������ڵ�
	 */
	private  static class TreeNode{
		private Comparable value;
		private TreeNode left;
		private TreeNode right;
		public TreeNode(){
			
		}
		public TreeNode(Comparable v,TreeNode l,TreeNode r){
			value=v;
			left=l;
			right=r;
		}
		public Comparable getValue() {
			return value;
		}
		public void setValue(Comparable value) {
			this.value = value;
		}
		public TreeNode getLeft() {
			return left;
		}
		public void setLeft(TreeNode left) {
			this.left = left;
		}
		public TreeNode getRight() {
			return right;
		}
		public void setRight(TreeNode right) {
			this.right = right;
		}
		
		
	}

}
