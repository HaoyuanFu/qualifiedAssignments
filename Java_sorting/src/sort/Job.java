package sort;
/**
 * 
 * @author 
 *Job���ڷ�װ����,һ��������������
 *1:String id;2: int seconds;
 *ʵ�ֶ�id��seconds��get set����
 *����ʵ��Comparable<Job>�ӿڴӶ�������ɱȽ�
 */
public class Job implements Comparable<Job>{
	private String Id;//��ʾjob's id
	private int seconds;//��ʾexecute time
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
	}//ʵ����Ӧ��get set����

	public Job(String id,int seconds){
		this.Id=id;
		this.seconds=seconds;
	}
	/**
	 * ���ȱȽ�seconds��ǰ��secondsС��o�е�
	 * secondsʱ����-1����ǰ��seconds����o�е�secondsʱ
	 * ����1,��ǰ��seconds==o�е�secondsʱ�Ƚ�id
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
