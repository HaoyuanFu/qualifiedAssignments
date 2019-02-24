import java.util.ArrayList;
import java.util.HashMap;

public class RestaurantList {
	
	private HashMap<String, Menu> menuMap=new HashMap<>();
	private ArrayList<Restaurant> restaurants=new ArrayList<>();
	
	
	
	public ArrayList<Restaurant> getRestaurants() {
		return restaurants;
	}

	public void setRestaurants(ArrayList<Restaurant> restaurants) {
		this.restaurants = restaurants;
	}

	/**
	 * load restaurants
	 * @param datas
	 * @param menuName
	 */
	public void loadRestaurants(ArrayList<String[]> datas,String menuName) {
		for (String[] strings : datas) {
			Restaurant restaurant=new Restaurant(strings);
			restaurants.add(restaurant);
			restaurant.setMenu(menuMap.get(menuName));
		}
		
	}
	/**
	 * load menu
	 * @param datas
	 */
	public void loadMenu(ArrayList<String[]> datas) {
		for (String[] strings : datas) {
			if (menuMap.containsKey(strings[0])) {
				menuMap.get(strings[0]).addDeal(new Meal(strings));
			}else {
				Menu menu=new Menu(strings[0]);
				menu.addDeal(new Meal(strings));
				menuMap.put(strings[0], menu);
			}
		}
	}
	

	
	

}
