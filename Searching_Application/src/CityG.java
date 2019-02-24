import java.awt.datatransfer.StringSelection;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class CityG {
	
	private HashMap<String, City> citysMap=new HashMap<>();
	
	/**
	 * add all citys
	 * @param datas
	 */
	public void addCitys(ArrayList<String[]> datas) {
		for (String[] strings : datas) {
			City city=new City(strings);
			citysMap.put(city.getName(), city);
		}
		
	}
	
	/**
	 * add all restaurants
	 * @param restaurants
	 */
	public void addRestaurants(ArrayList<Restaurant> restaurants) {
		for (City city : citysMap.values()) {
			city.addRestaurants(restaurants);
		}
		
	}
	
	/**
	 * BFS
	 * @param from
	 * @param to
	 * @return
	 */
	public ArrayList<City> bfs(String from,String to) {
		ArrayList<City> arrayList=new ArrayList<>();
		City start=citysMap.get(from);
		City end=citysMap.get(to);
		Queue<City> queue=new LinkedList<>();
		queue.add(start);
		HashMap<City, City>path=new HashMap<>();
		boolean flag=true;
		while (!queue.isEmpty()&&flag) {
			City city=queue.poll();
			
			ArrayList<ToCity> toCities=city.getToCities();
			for (ToCity toCity : toCities) {
				City child=toCity.getTo();
				if (!queue.contains(child)) {
					queue.add(child);
					path.put(child, city);
					if (child==end) {
						flag=false;
						break;
					}
				}
				
			}
		}
		
		while (path.get(end)!=start) {
			arrayList.add(0, end);
			end=path.get(end);
		}
		arrayList.add(0,end);
		arrayList.add(0,start);
		
		return arrayList;
		
	}
	/**
	 * DFS
	 * @param from
	 * @param to
	 * @return
	 */
	public ArrayList<City> dfs(String from,String to) {
		ArrayList<City> arrayList=new ArrayList<>();
		City start=citysMap.get(from);
		City end=citysMap.get(to);
		arrayList.add(start);
		dfsHelper(start, end, arrayList);
		
		return arrayList;
		
	}
	/**
	 * DFS helper
	 * @param start
	 * @param end
	 * @param arrayList
	 * @return
	 */
	private boolean dfsHelper(City start,City end,ArrayList<City> arrayList) {
		if (start==end) {
			return true;
		}else {
			ArrayList<ToCity> toCities=start.getToCities();
			for (ToCity toCity : toCities) {
				City city=toCity.getTo();
				if (!arrayList.contains(city)) {
					arrayList.add(city);
					boolean flag=dfsHelper(city, end, arrayList);
					if (flag) {
						return true;
					}
					arrayList.remove(city);
				}
				
			}
		}
		
		
		
		return false;
		
	}
	
	/**
	 * shortest path
	 * @param from
	 * @param to
	 * @return
	 */
    public ArrayList<City> shortestPath(String from,String to) {
    	
        ArrayList<City> arrayList=new ArrayList<>();
 		City start=citysMap.get(from);
 		City end=citysMap.get(to);
		ArrayList<City> S=new ArrayList<>();
		ArrayList<City> U=new ArrayList<>();
		U.addAll(citysMap.values());
		S.add(start);
		U.remove(start);
		HashMap<City, City> path=new HashMap<>();
		while (!S.contains(end)) {
			ToCity min=minDis(S, U);
			path.put(min.getTo(), min.getFrom());
			S.add(min.getTo());
			U.remove(min.getTo());
		}
		arrayList.add(0,end);
		while (path.get(end)!=start) {
			City city=path.get(end);
			arrayList.add(0,city);
			end=path.get(end);
		}
		
		arrayList.add(0, start);
		return arrayList;
		
	}
    
    /**
     * min distance for shortest path
     * @param s
     * @param u
     * @return
     */
    private ToCity minDis(ArrayList<City>s,ArrayList<City>u) {
    	ArrayList<ToCity> toCities=new ArrayList<>();
    	
    	for (City city2 : s) {
			ArrayList<ToCity> toCities2=city2.getToCities();
			for (ToCity toCity : toCities2) {
				if (u.contains(toCity.getTo())) {
					toCities.add(toCity);
				}
			}
		}
    	ToCity minToCity=Collections.min(toCities, new Comparator<ToCity>() {

			@Override
			public int compare(ToCity o1, ToCity o2) {
				// TODO Auto-generated method stub
				double dif=o2.getWeight()-o1.getWeight();
				return dif>0?1:dif<0?-1:0;
			}
		});
    	
    	return minToCity;
		
	}
    /**
     * get meals for shortest path
     * @param cities
     * @return
     */
    public ArrayList<Meal> getMeals(ArrayList<City> cities) {
		ArrayList<Meal> meals=new ArrayList<>();
		meals.add(cities.get(1).getOneRestaurant().getMinMeal());
		for (int i = 2; i < cities.size(); i++) {
			meals.add(cities.get(i).getOneRestaurant().getMinMeal(meals.get(meals.size()-1)));
		}
		return meals;
	}
	

	/**
	 * add all citys
	 * @param datas
	 */
	public void addToCitys(ArrayList<String[]>datas) {
		for (String[] strings : datas) {
			
			City city1=citysMap.get(strings[0].toUpperCase());
			City city2=citysMap.get(strings[1].toUpperCase());
			double dis=distance(city1, city2);
			city1.addToCity(new ToCity(city1,city2, dis));
			city2.addToCity(new ToCity(city2,city1, dis));
		}
		
	}
	
	/**
	 * compute distance from one city to another city
	 * @param city1
	 * @param city2
	 * @return
	 */
	private double distance(City city1,City city2) {
		double dis;
		dis=Math.sqrt(Math.pow(city1.getLatitude()-city2.getLatitude(), 2)+Math.pow(city1.getLongitude()-city2.getLongitude(), 2));
		return dis;
		
	}
	
	
	
	
	
	

}
