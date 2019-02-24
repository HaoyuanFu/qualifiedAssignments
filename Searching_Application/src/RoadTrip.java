import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class RoadTrip {
	
	CityG cityG;
	ReadFile readFile=new ReadFile("data");
	RestaurantList restaurantList=new RestaurantList();
	private PrintWriter printWriter1;
	private PrintWriter printWriter2;
	
	
	public RoadTrip() {
		// TODO Auto-generated constructor stub
		cityG=new CityG();
		initG();
		initRestaurants();
		addRestaurantToCity();
		
		
		
	}
	
	/**
	 * out information to a2_out.txt and a2_answers.txt
	 */
	public void out() {
		try {
			printWriter1=new PrintWriter("data/a2_out.txt");
			printWriter2=new PrintWriter("data/a2_answers.txt");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		printWriter2.println("Adjacency list solve the problem.Node represent city."
				+ "Recursion solve DFS.Queue solve BFS. Dijkstra solve shortest path.");
		bfs("Boston", "Minneapolis");
		dfs("Boston", "Minneapolis");
		shortestPath("Boston", "Minneapolis");
		printWriter1.close();
		printWriter2.close();
		
	}
	
	/**
	 * DFS
	 * @param from
	 * @param to
	 */
	public void dfs(String from,String to) {
		ArrayList<City> path=cityG.dfs(from.toUpperCase(), to.toUpperCase());
		printWriter1.print("DFS:");
		printWriter2.print("DFS:");
		for (int i = 0; i < path.size(); i++) {
			if (i==path.size()-1) {
				printWriter1.println(path.get(i).getName());
				printWriter2.println(path.get(i).getName());
			}else {
				printWriter1.print(path.get(i).getName()+",");
				printWriter2.print(path.get(i).getName()+",");
			}
		}
		
	}
	
	/**
	 * BFS
	 * @param from
	 * @param to
	 */
	public void bfs(String from,String to) {
		ArrayList<City> path=cityG.bfs(from.toUpperCase(), to.toUpperCase());
		printWriter1.print("BFS:");
		printWriter2.print("BFS:");
		for (int i = 0; i < path.size(); i++) {
			if (i==path.size()-1) {
				printWriter1.println(path.get(i).getName());
				printWriter2.println(path.get(i).getName());
			}else {
				printWriter1.print(path.get(i).getName()+",");
				printWriter2.print(path.get(i).getName()+",");
			}
		}
	}
	
	/**
	 * shortest path
	 * @param from
	 * @param to
	 */
	public void shortestPath(String from,String to) {
		ArrayList<City> path=cityG.shortestPath(from.toUpperCase(), to.toUpperCase());
		ArrayList<Meal> meals=cityG.getMeals(path);
		printWriter2.print("ShortestPath:");
		for (int i = 0; i < path.size(); i++) {
			if (i==0) {
				printWriter2.print(path.get(i).getName()+",");
			}else if (i==path.size()-1) {
				printWriter2.print(path.get(i).getName());
				printWriter2.print("["+meals.get(i-1).getName()+":$"+meals.get(i-1).getPrice()+"]");
			}else{
				printWriter2.print(path.get(i).getName());
				printWriter2.print("["+meals.get(i-1).getName()+":$"+meals.get(i-1).getPrice()+"],");
			}
		}

	}
	
	/**
	 * add restaurant to city
	 */
	private void addRestaurantToCity() {
		cityG.addRestaurants(restaurantList.getRestaurants());
	}
	/**
	 * init Graph
	 */
	private void initG() {
		ArrayList<String[]> datas=readFile.readData("USCities.csv",true);
		cityG.addCitys(datas);
		datas=readFile.readData("connectedCities.txt",false);
		cityG.addToCitys(datas);
	}
	/**
	 * load restaurants from file
	 */
	private void initRestaurants() {
		ArrayList<String[]> datas=readFile.readData("menu.csv",true);
		
		restaurantList.loadMenu(datas);
		
		datas=readFile.readData("burgerking.csv",true);
		restaurantList.loadRestaurants(datas,"Burger King");
		datas=readFile.readData("mcdonalds.csv",false);
		restaurantList.loadRestaurants(datas,"McDonalds");
		datas=readFile.readData("wendys.csv",false);
		restaurantList.loadRestaurants(datas,"Wendys");
		
		
	}

}
