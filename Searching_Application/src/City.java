import java.util.ArrayList;
import java.util.Random;

public class City {
	
	private String stateCode;
	private String zipCode;
	private String stateAbbreviation;
	private String name;
	private double latitude;
	private double longitude;
	private ArrayList<ToCity> toCities=new ArrayList<>();
	private ArrayList<Restaurant> restaurants=new ArrayList<>();
	/**
	 * add restaurants
	 * @param restaurants
	 */
	public void addRestaurants(ArrayList<Restaurant> restaurants) {
		for (int i = 0; i < restaurants.size(); i++) {
			Restaurant restaurant=restaurants.get(i);
			//System.out.println(inTheCity(restaurant));
			if (inTheCity(restaurant)) {
				this.restaurants.add(restaurant);
				restaurants.remove(i);
				i--;
				
			}
			
		}
	}
	/**
	 * the restaurant yes or no in the city
	 * @param restaurant
	 * @return
	 */
	private boolean inTheCity(Restaurant restaurant) {
		return Math.abs(latitude-restaurant.getLatitude())<0.5&&Math.abs(longitude-restaurant.getLongitude())<0.5;
	}
	/**
	 * random a restaurant in the city
	 * @return
	 */
	public Restaurant getOneRestaurant() {
		Random random=new Random();
		
		return restaurants.get(random.nextInt(restaurants.size()));
		
	}
	
	
	public City(String[]data) {
		// TODO Auto-generated constructor stub
		stateCode=data[0];
		zipCode=data[1];
		stateAbbreviation=data[2];
		name=data[3];
		latitude=Double.parseDouble(data[4]);
		longitude=Double.parseDouble(data[5]);
		
	}
	
	/**
	 * add can arrival city
	 * @param toCity
	 */
	public void addToCity(ToCity toCity) {
		
		toCities.add(toCity);
		
	}
	
	
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return String.format("StateCode:%s,ZipCode:%s,StateAbbreviation:%s,Name:%s,Latitude:%f,Longitude:%s", stateCode,zipCode,stateAbbreviation,name,latitude,longitude);
	}
	
	
	
	public ArrayList<ToCity> getToCities() {
		return toCities;
	}

	public void setToCities(ArrayList<ToCity> toCities) {
		this.toCities = toCities;
	}

	public String getStateCode() {
		return stateCode;
	}
	public void setStateCode(String stateCode) {
		this.stateCode = stateCode;
	}
	public String getZipCode() {
		return zipCode;
	}
	public void setZipCode(String zipCode) {
		this.zipCode = zipCode;
	}
	public String getStateAbbreviation() {
		return stateAbbreviation;
	}
	public void setStateAbbreviation(String stateAbbreviation) {
		this.stateAbbreviation = stateAbbreviation;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
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

}
