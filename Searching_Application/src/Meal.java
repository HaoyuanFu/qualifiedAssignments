
public class Meal {
	private String name;//meal name
	private double price;//meal price
	private String comment;//meal comment
	
	public Meal(String [] data) {
		// TODO Auto-generated constructor stub
		name=data[1];
		price=Double.parseDouble(data[2].replace("$", ""));
		comment=data[3];
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return String.format("name:%s,price:%f,comment:%s", name,price,comment);
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public String getComment() {
		return comment;
	}
	public void setComment(String comment) {
		this.comment = comment;
	}
	
	

}
