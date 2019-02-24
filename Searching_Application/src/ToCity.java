
/**
 * edge
 * @author Administrator
 *
 */
public class ToCity {
	
	private double weight;//weight(distance)
	private City to;//to city
	private City from;//from city
	
	public ToCity(City from,City to,double weight) {
		// TODO Auto-generated constructor stub
		this.to=to;
		this.from=from;
		this.weight=weight;
	}
	
	
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "to "+to.getName();
	}
	
	
	
	
	public City getFrom() {
		return from;
	}



	public void setFrom(City from) {
		this.from = from;
	}



	public double getWeight() {
		return weight;
	}
	public void setWeight(double weight) {
		this.weight = weight;
	}
	public City getTo() {
		return to;
	}
	public void setTo(City to) {
		this.to = to;
	}
	
	
	

}
