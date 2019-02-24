package sort;
/**
 * 
 * @author 
 *Job用于封装数据,一共含有两个数据
 *1:String id;2: int seconds;
 *实现对id和seconds的get set方法
 *并且实现Comparable<Job>接口从而可以完成比较
 */
public class Job implements Comparable<Job>{
	private String Id;//表示job's id
	private int seconds;//表示execute time
	public String getId() {
		return Id;
	}
	public void setId(String id) {
		Id = id;
	}
	public int getSeconds() {
		return seconds;
	}
	public void setSeconds(int seconds) {
		this.seconds = seconds;
	}//实现相应的get set方法

	public Job(String id,int seconds){
		this.Id=id;
		this.seconds=seconds;
	}
	/**
	 * 首先比较seconds当前的seconds小于o中的
	 * seconds时返回-1，当前的seconds大于o中的seconds时
	 * 返回1,当前的seconds==o中的seconds时比较id
	 */
	public int compareTo(Job o) {
	
		if (seconds<o.seconds)
			return -1;
		else{
			if (seconds>o.seconds){
				return 1;
			}else{
				
				return Id.compareTo(o.Id);
			}
		}
	}
	public String toString(){
		return "{"+Id+","+seconds+"}";
	}
	
}
