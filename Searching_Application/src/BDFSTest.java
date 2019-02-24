import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Before;
import org.junit.Test;

public class BDFSTest {
	
	CityG cityG;
	ReadFile readFile=new ReadFile("data");

	@Before
	public void setUp() throws Exception {
		cityG=new CityG();
		initG();
	}
	
	private void initG() {
		ArrayList<String[]> datas=readFile.readData("USCities.csv",true);
		cityG.addCitys(datas);
		datas=readFile.readData("connectedCities.txt",false);
		cityG.addToCitys(datas);
	}
	
	private String getStr(ArrayList<City> path) {
		String string="";
		for (City city : path) {
			string+=city.getName()+",";
		}
		return string;
	}

	@Test
	public void bfsTest1() {
		String string=getStr(cityG.bfs("BOSTON", "MINNEAPOLIS"));
		assertEquals("BOSTON,NEW YORK CITY,PITTSBURGH,COLUMBUS,CHICAGO,MINNEAPOLIS,", string);
	}
	
	@Test
	public void bfsTest2() {
		String string=getStr(cityG.bfs("BOSTON", "CHICAGO"));
		assertEquals("BOSTON,NEW YORK CITY,PITTSBURGH,COLUMBUS,CHICAGO,", string);
	}
	
	@Test
	public void bfsTest3() {
		String string=getStr(cityG.bfs("BOSTON", "COLUMBUS"));
		assertEquals("BOSTON,NEW YORK CITY,PITTSBURGH,COLUMBUS,", string);
	}
	
	@Test
	public void bfsTest4() {
		String string=getStr(cityG.bfs("BOSTON", "PITTSBURGH"));
		assertEquals("BOSTON,NEW YORK CITY,PITTSBURGH,", string);
	}
	
	@Test
	public void bfsTest5() {
		String string=getStr(cityG.bfs("BOSTON", "NEW YORK CITY"));
		assertEquals("BOSTON,NEW YORK CITY,", string);
	}
	
	@Test
	public void dfsTest1() {
		String string=getStr(cityG.dfs("BOSTON", "MINNEAPOLIS"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,HOUSTON,DALLAS,OKLAHOMA CITY,KANSAS CITY,"
				+ "ST. LOUIS,INDIANAPOLIS,COLUMBUS,CHICAGO,MINNEAPOLIS,", string);
	}
	
	@Test
	public void dfsTest2() {
		String string=getStr(cityG.dfs("BOSTON", "CHICAGO"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,HOUSTON,DALLAS,OKLAHOMA CITY,KANSAS CITY,"
				+ "ST. LOUIS,INDIANAPOLIS,COLUMBUS,CHICAGO,", string);
	}
	
	@Test
	public void dfsTest3() {
		String string=getStr(cityG.dfs("BOSTON", "COLUMBUS"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,HOUSTON,DALLAS,OKLAHOMA CITY,KANSAS CITY,"
				+ "ST. LOUIS,INDIANAPOLIS,COLUMBUS,", string);
	}
	
	@Test
	public void dfsTest4() {
		String string=getStr(cityG.dfs("BOSTON", "INDIANAPOLIS"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,HOUSTON,DALLAS,OKLAHOMA CITY,KANSAS CITY,"
				+ "ST. LOUIS,INDIANAPOLIS,", string);
	}
	
	@Test
	public void dfsTest5() {
		String string=getStr(cityG.dfs("BOSTON", "ST. LOUIS"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,HOUSTON,DALLAS,OKLAHOMA CITY,KANSAS CITY,"
				+ "ST. LOUIS,", string);
	}
	
	@Test
	public void dfsTest6() {
		String string=getStr(cityG.dfs("BOSTON", "KANSAS CITY"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,HOUSTON,DALLAS,OKLAHOMA CITY,KANSAS CITY,", string);
	}
	
	@Test
	public void dfsTest7() {
		String string=getStr(cityG.dfs("BOSTON", "OKLAHOMA CITY"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,HOUSTON,DALLAS,OKLAHOMA CITY,", string);
	}
	
	@Test
	public void dfsTest8() {
		String string=getStr(cityG.dfs("BOSTON", "DALLAS"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,HOUSTON,DALLAS,", string);
	}
	
	@Test
	public void dfsTest9() {
		String string=getStr(cityG.dfs("BOSTON", "HOUSTON"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,HOUSTON,", string);
	}
	
	@Test
	public void dfsTest10() {
		String string=getStr(cityG.dfs("BOSTON", "NEW ORLEANS"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,NEW ORLEANS,", string);
	}
	
	@Test
	public void dfsTest11() {
		String string=getStr(cityG.dfs("BOSTON", "ATLANTA"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,ATLANTA,", string);
	}
	
	@Test
	public void dfsTest12() {
		String string=getStr(cityG.dfs("BOSTON", "CHARLOTTE"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,CHARLOTTE,", string);
	}
	
	@Test
	public void dfsTest13() {
		String string=getStr(cityG.dfs("BOSTON", "WASHINGTON"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,"
				+ "WASHINGTON,", string);
	}
	
	@Test
	public void dfsTest14() {
		String string=getStr(cityG.dfs("BOSTON", "BALTIMORE"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,BALTIMORE,", string);
	}
	
	@Test
	public void dfsTest15() {
		String string=getStr(cityG.dfs("BOSTON", "PHILADELPHIA"));
		assertEquals("BOSTON,NEW YORK CITY,PHILADELPHIA,", string);
	}
	
	@Test
	public void dfsTest16() {
		String string=getStr(cityG.dfs("BOSTON", "NEW YORK CITY"));
		assertEquals("BOSTON,NEW YORK CITY,", string);
	}


}
