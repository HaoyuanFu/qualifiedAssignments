import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Restaurant {
	
	
	private double latitude;
	private double longitude;
	private String name;
	private String comment;
	private Menu menu;
	
	public Restaurant(String[] data) {
		// TODO Auto-generated constructor stub
		longitude=Double.parseDouble(data[0]);
		latitude=Double.parseDouble(data[1]);
		name=data[2];
		comment=data[3];
	}
	/**
	 * get a cheap meal
	 * @return
	 */
	public Meal getMinMeal() {
		Meal meal=null;
		
		meal=Collections.min(menu.getMealList(),new Comparator<Meal>() {

			@Override
			public int compare(Meal o1, Meal o2) {
				// TODO Auto-generated method stub
				double dif=o1.getPrice()-o2.getPrice();
				return dif>0?1:dif<0?-1:0;
			}
		});
		
		return meal;
		
	}
	/**
	 * get a cheap meal but not preMeal
	 * @param preMeal
	 * @return
	 */
	public Meal getMinMeal(Meal preMeal) {
		Meal meal=null;
		ArrayList<Meal>meals=new ArrayList<>();
		meals.addAll(menu.getMealList());
		
		meal=Collections.min(meals,new Comparator<Meal>() {

			@Override
			public int compare(Meal o1, Meal o2) {
				// TODO Auto-generated method stub
				double dif=o1.getPrice()-o2.getPrice();
				return dif>0?1:dif<0?-1:0;
			}
		});
		
		if (meal==preMeal) {
			meals.remove(meal);
			meal=Collections.min(meals,new Comparator<Meal>() {

				@Override
				public int compare(Meal o1, Meal o2) {
					// TODO Auto-generated method stub
					double dif=o1.getPrice()-o2.getPrice();
					return dif>0?1:dif<0?-1:0;
				}
			});
			
		}
		
		return meal;
		
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return String.format("name:%s,latitude:%f,longitude:%f,comment:%s", name,latitude,longitude,comment);
	}

	public double getLatitude() {
		return latitude;
	}

	public void setLatitude(double latitude) {
		this.latitude = latitude;
	}

	public double getLongitude() {
		return longitude;
	}

	public void setLongitude(double longitude) {
		this.longitude = longitude;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getComment() {
		return comment;
	}

	public void setComment(String comment) {
		this.comment = comment;
	}

	public Menu getMenu() {
		return menu;
	}

	public void setMenu(Menu menu) {
		this.menu = menu;
	}
	
	
	

}
