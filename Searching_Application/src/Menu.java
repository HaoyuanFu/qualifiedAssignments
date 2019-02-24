import java.util.ArrayList;

public class Menu {
	
	private String name;//menu name
	private ArrayList<Meal> mealList=new ArrayList<>();//meals
	
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		StringBuilder stringBuilder=new StringBuilder();
		for (Meal meal : mealList) {
			stringBuilder.append(name+" "+meal+"\n");
		}
		return stringBuilder.toString();
	}
	
	public Menu(String name) {
		// TODO Auto-generated constructor stub
		this.name=name;
	}
	
	public void addDeal(Meal meal) {
		mealList.add(meal);
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public ArrayList<Meal> getMealList() {
		return mealList;
	}

	public void setMealList(ArrayList<Meal> mealList) {
		this.mealList = mealList;
	}
	
	

}
