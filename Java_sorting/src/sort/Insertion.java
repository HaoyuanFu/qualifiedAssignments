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
	 * 针对Job中的数据进行比较
	 * @return
	 */
	private static int compare(Job job1,Job job2){
		//获取job1和job2的seconds值和id值
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
	
		TreeNode root=new TreeNode(x[0],null,null);//生成二叉树的根节点,并将第一个元素放入进去
		TreeNode r=root;//将根节点定义为root
		TreeNode parent=root;//记录每个节点的父节点
		step=0;
		for(int i=1;i<n;i++){//一个节点一个节点的插入
			int f1=0;
			r=root;
			parent=root;
			while(r!=null){
				parent=r;
				 f1=0;
				if (x[i].compareTo(r.getValue())==-1){
					r=r.getLeft();
					f1=1;//如果要插入的节点比当前节点小放入左孩子节点
				}else{
					f1=2;
					r=r.getRight();//否则放入右孩子节点
				}
			}//当遇到空节点时循环结束即位要插入的位置
			r=new TreeNode(x[i],null,null);//创建新节点
			if (f1==1)
				parent.setLeft(r);
			else
				parent.setRight(r);
		}
	//	System.out.println("ABCD");
		mid_traverse(root, x);//中序遍历
		
	}
	/**
	 * 
	 * @param r表示树的节点
	 * @param x表示Comparable数组
	 */
	private static void mid_traverse(TreeNode r,Comparable[]x){
		if (r==null)
			return;
		mid_traverse(r.getLeft(),x);//递归左子树
		 x[step]=r.getValue();//进行赋值
		 step++;
		mid_traverse(r.getRight(),x);//递归右子树
	}
	
	/**
	 * 
	 * @author 
	 *定义一个内部类用来封装树节点的数据,每个树节点包括一个value值,左子树节点,右子树节点
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
